/*
 ============================================================================
 Name        : U4.1.10.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Store multiple strings in an array in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char word[3][10];
    int i;
    printf("Please Enter 3 Words Of Max 9 Characters : "); /* As on 10 th location scanf puts a null terminaotr marking end of an array*/
    for(i=0;i<3;i++)
    {
    	scanf("%s",word[i]);
    }
    printf("You have entered : ");
    for(i=0;i<3;i++){
    	printf("%s ",word[i]);
    }

    printf("\n First Letters : \n ");
    for(i=0;i<3;i++){
    printf("%s letter starts with %c \n ",word[i],word[i][0]);
    }


	return EXIT_SUCCESS;
}


