#include <stdio.h>

int main(void)
{
    int i = 5;   
    float f = 7.5;
    char* x = "a string here"; 

    printf("%s when I %f then i %d\n", x, f, i);

    int a = 999;

    printf("Sizeof operator usage:\n");
    printf("%zu\n", sizeof a);
    printf("%zu\n", sizeof (2+7));
    printf("%zu\n", sizeof 3.14);

    printf("Address of i, %p\n", &i);
    printf("Address of f, %p\n", &f);
    printf("Address of x, %p\n", &x);

    printf("Using pointers\n");

    int orig = 10;
    int *pointer = &orig;

    printf("Original val is %d\n", orig);
    printf("Pointer val is %p\n", pointer);

    printf("Add 10 to dereferenced pointer\n");

    *pointer = *pointer + 10;

    printf("Original val is now %d\n", orig);
    printf("Pointer val is now %d\n", *pointer);
    
    /* One example of pointer usage is to manipulate a variables original copy within a function block
    so a function can receive a copy of i and its pointer *p as params, both get copied inside the function block
    manipulating i won't change the original copy of i, but dereferencing and manipulating *p will
    */
}