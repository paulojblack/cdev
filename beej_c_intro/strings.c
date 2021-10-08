#include <stdio.h>
#include <string.h>

int main(void) {
    // Pointer to a char, a char can be a single characters but a char pointer points to the first character in this string, like an array
    // I think?
    char *s = "Hello, bitch";

    printf("%s\n", s);

    // looks like yes bc you can define it using array length
    char otherString[] = "This is my other string";

    printf("%s\n", otherString);

    // Here's some shit
    char *x = "This is a string literal"; //unmutable
    char y[] = "This is a mutable copy of a string"; //mutable

    //Maybe i dont understand what a "string literal" is well enough. What is y a copy of, is the string literal it is a copy of stored elsewhere?
    printf("My string y is %zu bytes big\n", strlen(y));

    // In C a string is defined by 2 characteristics
    // A pointer to the first character in the string
    // A zero valued byte (or NIL character) somewhere in memory after the pointer that indicated end of string

    // So on point 2 there,
    char *o = "Hello"; // is equivalent to "Hello\0" behind the scenes, where \0 is a NUL character

    // And that NUL character is detectable, so to write our own strlen function we could do my_strlen below
}


int my_strlen(char *s)
{
    int count = 0;

    while (s[count] != '\0') // single quotes because its a char, not a string
        count++;

    return count;
}