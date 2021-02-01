/*
 ============================================================================
 Name        : U4.1.9.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Store strings in arrays using pointers in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char a[4];
	char b[6];
	char c[9];

	char * words[3] = {a,b,c};
	printf("Please enter a word with at  most 3 letters :");
	scanf("%s",a); /*note that scanf put's null terminator at end of array and for that space needs to be reserved in a certain array*/
	printf("Please enter a word with at  most 5 letters :");
	scanf("%s",b);
	printf("Please enter a word with at  most 8 letters :");
	scanf("%s",c);
	printf("You entered in arrays a,b,c : %s %s %s \n",a,b,c);
	printf("%s %s %s.\n", words[0],words[1],words[2]);


	/*Debug printf statements
	 * printf("words address %p %p %p \n",words[0],words[1],words[2]);
	printf("arrays a,b,c address %p %p %p",a,b,c); */


}
