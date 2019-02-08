#include <stdio.h>

int main (void)
{
    void * voidptr;
    char *s = "Foobar";
    int num = 10;

    printf("Char pointer points to: %s\n", s);
    voidptr = s;
    printf("void pointer points to: %s\n", (char *)voidptr);
    voidptr = &num;
    printf("Casting int to void, value is %d\n", *((int *)voidptr));

}