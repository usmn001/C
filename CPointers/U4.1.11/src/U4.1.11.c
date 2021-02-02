/*
 ============================================================================
 Name        : U4.1.11.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Work with matrices in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//void printmatrix(int *ptr);
/*
Here we've learnt how to store data in a matrix through both main thread
statements and call'd function outside of main depending upon scenario
*/
int main(void) {

	int matrix[2][3];int line,col;
    printf("Enter Numbers : \n");

    for(line=0;line<2;line++){
    	for(col=0;col<3;col++){
    		scanf("%i",&matrix[line][col]); // storing inputted numbers in matrix array having 6 empty spaces
    	}

    }
    printf("Address of matrix : %p\n",matrix);
    printf("You Entered :\n");
    for(line=0;line<2;line++){
        	for(col=0;col<3;col++){
        		printf("%i ",matrix[line][col]);
        	}
        	printf("\n");

        }
    //printmatrix(matrix); /*Passing matrix array address to function printmatrix */
	return EXIT_SUCCESS;
}
/*void printmatrix(int *ptr){
	// Printf debug statement
	 * printf("Address of ptr : %p, Value is %i\n",ptr,*ptr+3);

    int i;

	for(i=0;i<6;i++){
	printf("%i  ",*ptr+i);
    }


}*/
