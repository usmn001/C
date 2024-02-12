/*
 ============================================================================
 Name        : Ch1.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Double Pointers Understanding
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
   uint8_t var = 56;
   uint8_t *sptr = NULL;
   uint8_t **dptr = NULL;
   sptr = &var;
   dptr = &sptr;


   printf("Using Variable %i\n",var);
   printf("Value Using Single Pointer %i\n",*sptr);
   printf("Value Using Double Pointer %i\n",**dptr);

   printf("Address of Integer Variable &var : %p \n",&var);
   printf("Address of Integer Variable sptr : %p \n",sptr);
   printf("Address of Integer Variable dptr : %p \n",*dptr);

   printf("Value of Single Pointer Variable : %i \n",*sptr);
   printf("Value Of Single Pointer Variable : %i \n",**dptr);

   printf("Address of Single Pointer Variable : %p \n",&sptr);
   printf("Address of Single Pointer Variable : %p \n",dptr);

   printf("Double Pointer Address %p : Has Value : %p \n ",&dptr,*dptr);


	return EXIT_SUCCESS;
}
