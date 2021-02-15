/*
 ============================================================================
 Name        : FP.c
 Author      : M Usman
 Version     :
 Copyright   : Your copyright notice
 Description : Tracking a fire using arrays in C, Ansi-style
 ============================================================================

You have been hired to assist firefighters locate wildfires in a large
geographic area. The area is divided into smaller zones. Each zone is
scanned via satellite for its average temperature. If a zone has an average
temperature strictly greater than 1000°F, we assume there is a fire in that
zone. If the temperature is between 100 degrees (included) and 1000 degrees
(included), we have to further investigate, so it becomes a "zone to watch."
The large geographic area you are watching is a rectangle with a certain
length and width, each given in terms of zones. For example, if the area to
be scanned  has a length of 6 and width of 9 then it will be divided into
6*9 zones:
 ----length = 6----
[ ][ ][ ][ ][ ][ ]   |
[ ][ ][ ][ ][ ][ ]   w
[ ][ ][ ][ ][ ][ ]   i
[ ][ ][ ][ ][ ][ ]   d
[ ][ ][ ][ ][ ][ ]   t
[ ][ ][ ][ ][ ][ ]   h
[ ][ ][ ][ ][ ][ ]   =
[ ][ ][ ][ ][ ][ ]   9
[ ][ ][ ][ ][ ][ ]   |
Because your program will be used for a variety of geographic areas
(each with its own length and width) your program needs to dynamically
allocate the memory for the number of zones it is to handle
(vertically and horizontally).
 */

#include <stdio.h>
#include <stdlib.h>
int ** allocateIntStarArray(int num);
int * allocateIntArray(int num);


int main(void) {
	int length,width,i,j;   /*Here width is row, length is column*/
	scanf("%i",&length);    /* Entering Number of rows */
	scanf("%i",&width);     /* Entering Number of columns */
	int ** array_ptr;
	int  * row_ptr;

	array_ptr = allocateIntStarArray(width);

	for(j=0;j<width;j++){
		row_ptr = allocateIntArray(length);
		array_ptr[j] = row_ptr;
	for(i=0;i<length;i++){
		scanf("%i",row_ptr+i);
	}
	}


	for(i=0;i<width;i++){

		for(j=0;j<length;j++){

			if(array_ptr[i][j]>1000){
				//printf("%i %i",i,j);
                printf("[X]");
			}
			else if(array_ptr[i][j]<=1000 && array_ptr[i][j]>=100 ){
				printf("[*]");
			}
			else
				printf("[ ]");
	}
		printf("\n");
	}

	free(array_ptr);
	free(row_ptr);
	return EXIT_SUCCESS;
}


/*Function Used to allocate an array of pointers, each of which will store
a pointer to a row of integers (temperatures of zones). That is, the
function returns a pointer to an array of pointers. Each cell of this
array will point to an array of integers containing the temperature
values for the zones*/
int ** allocateIntStarArray(int num){
    int ** ptr = (int **) malloc(num * sizeof(int *));
    return ptr;
}


/*Function used to allocate the space required to store the average
 *temperatures in one row of zones, that is, an array of integers.
 *temperatures The function therefore one returns a pointer to such
 *temperatures an array of integers.*/
int * allocateIntArray(int num){
    int * ptr = (int *) malloc(num * sizeof(int));
    return ptr;
}










