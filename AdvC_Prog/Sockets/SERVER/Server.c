#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

const char *pMesaage = "Hello";

short socketCreate(void)        // Our Own Function Creating Socket 
{
short hSocket;
printf("Create the socket\n");
hSocket = socket(AF_INET, SOCK_STREAM, 0);
return hSocket;
}

int bindCreatedSocket(int hSocket) 
{

int iRetval = -1;
int clientPort = 12345; 
struct sockaddr_in remote = {0};

/* Internet Address Family */
remote.sin_family = AF_INET;

/* Any incoming interface */
remote.sin_addr.s_addr = htonl(INADDR_ANY);   /* Function converts the unsigned integer hostlong from host byte order to network byte order. */
remote.sin_port = htons(clientPort);          /* Function converts the unsigned short integer hostshort from host byte order to network byte order. */

iRetval = bind(hSocket, (struct sockaddr*)&remote, sizeof(remote));
return iRetval;
}

int main(int argc, char*argv[]) 
{

int socket_desc = 0, sock = 0, clientLen = 0;
struct sockaddr_in client;
char msg_from_client[10] = {0};
char msg_to_client[18] = {0};

// Create socket
socket_desc = socketCreate();

if(socket_desc == -1) 
{
  printf("Could Not Create Socket");
  return 1;
  
}

printf("Socket Created\n");

//Bind
if(bindCreatedSocket(socket_desc) < 0)
{
perror("Bind Failed");
return 1;
}

printf("Bind Done\n");

//Listen
listen(socket_desc,3);

// Accept incoming connection
    while(1)
    {
	    printf("Waiting for incoming connections.......\n");
	    //const char *pMesaage = "hello from Jasons server";
        clientLen=sizeof(struct sockaddr_in);

	    // Accept connection from an incoming client, accept is returning a new socket descriptor
	    sock = accept(socket_desc,(struct sockaddr *)&client,(socklen_t*)&clientLen);

	    if(sock<0)
	    {
	        perror("Accept Failed");
 	        return 1;
	    }

	    printf("Connection Accepted\n");
	    //memset(msg_from_client, "\0",sizeof(msg_from_client)); // Setting the buffer we use for sending msg_to_client to client.
	    //memset(msg_to_client,"\0",sizeof(msg_to_client));


	    // Receive a Reply from the client
	    if( recv(sock,msg_from_client,sizeof(msg_from_client),0)<0) 
	    {
        	printf("recv failed");
  		    break;
    	}
    
	   printf("Client Reply : %s\n",msg_from_client);
       
        /*if(strcmp(pMesaage,msg_from_client)==0)
	    {
  	        strcpy(msg_to_client,"Hi There");
	    }

	    else 
        {
	        strcpy(msg_to_client,"Invalid msg_to_client");
	    }*/
		
     	strcpy(msg_to_client,"Hello From Server");				
         
		

		
	    if(send(sock,msg_to_client,strlen(msg_to_client),0)<0)
	    {
  	        printf("Send Failed");
  	    return 1;
	    }
		cnt ++;
    }

	close(sock);
	sleep(1);


	return 0;
 }


































