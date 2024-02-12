/*
 ============================================================================
 Name        : P2.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Challenge 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void allocate_Memory(uint8_t **dptr)
{
*dptr = (uint8_t*)malloc(sizeof(uint8_t));
}

int main(void)
{
uint8_t *ptr = NULL;
allocate_Memory(&ptr);
*ptr = 18;
printf("Value Pointed By Pointer ptr %i",*ptr);
free(ptr);
}
