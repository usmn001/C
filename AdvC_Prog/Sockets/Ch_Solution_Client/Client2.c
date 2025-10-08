#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void)        // Our Own Function Creating Socket 
{
short hSocket;
printf("Creating the Client socket\n");
hSocket = socket(AF_INET, SOCK_STREAM, 0);
return hSocket;
}

int socketConnect(int hSocket) 
{
int iRetval = -1;
int serverPort = 12345;
char *serverIP = "127.0.0.1";
struct sockaddr_in remote = {0};
/* Internet Address Family */
remote.sin_family = AF_INET;    
/* Server Port number */
remote.sin_port = htons(serverPort);
/* Server IP address */
remote.sin_addr.s_addr = inet_addr(serverIP);
iRetval = connect(hSocket, (struct sockaddr*)&remote, sizeof(remote));
return iRetval;
}


// Send the data to the server and set the timeout of 20 seconds
int socketSend(int hSocket,char* Rqst,short lenRqst) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;

    if(setsockopt(hSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&tv,sizeof(tv)) < 0) {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

//receive the data from the server
int socketReceive(int hSocket,char* Rsp,short RvcSize) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;
    

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO,(char *)&tv,sizeof(tv)) < 0)    {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    printf("Reply From Server : %s\n",Rsp);
    return shortRetval;
}



int main(int argc, char*argv[]) 
{
int socket_desc = 0, sock = 0, clientLen = 0,read_size = 0;
struct sockaddr_in client;
char client_message[10] = {0};
char server_reply[10] = {0};


// Create socket
socket_desc = socketCreate();

if(socket_desc == -1) 
{
  printf("Could Not Create Socket");
  return 1;  
}
else
{
    printf("Socket Created\n");
}

// Connect To Server
if(socketConnect(socket_desc) < 0)
{
  printf("Could Not Connect to Server\n");
  return 1;
}
else
{
    printf("Connected to Server\n");
}
    
// Receive Data From Server
read_size = socketReceive(socket_desc,server_reply,200);

int num = atoi(server_reply);
printf("Number Received From Server: %d\n", num);

close(socket_desc);
return 0;

}