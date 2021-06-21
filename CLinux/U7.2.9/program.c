#include<stdio.h>

int main(int argc, char *argv[]){
	printf("Number Of Passed Arguments are : %i\n",argc);
for(int i=0;i<argc;i++)
{
	printf("Argument %i is %s at Address : %p\n",i+1,argv[i],argv+i);
        printf("Value stored at Address %p is %s\n\n",argv+i,*(argv+i));
        
       
}	





return 0;
}
