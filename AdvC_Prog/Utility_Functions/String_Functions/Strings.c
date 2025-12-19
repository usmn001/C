#include <stdio.h>
#include <stdint.h>

int main(void)                     // Program to Convert
{

    char str[20] = "2030300  This is test";     // end is pointing to "This is test"
    char *ptr = NULL;
    long ret = 0;
    ret = strtol(str,&ptr,10);
    printf("The number(unsigned long integer) is %ld\n",ret);
    printf("String part is %s",ptr);

    return 0;



}
