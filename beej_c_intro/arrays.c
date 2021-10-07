#include <stdio.h>
int main(void)
{
    int i;
    float f[9] = {3.14159, 1.41421, 1.61803};     // Declare an array of 4 floats
    // f[0] = 3.14159; // Indexing starts at 0, of course.
    // f[1] = 1.41421;
    // f[2] = 1.61803;


    // Print them all out:

    for (i = 0; i < 9; i++)
    {
        printf("%f\n", f[i]);
    }

    //print array length
    printf("Size of array %zu\n", sizeof f);
    printf("Size of float %zu\n", sizeof(float));

    printf("Size of array div size of float = length of array %zu\n", (sizeof f / sizeof(float)));


    int a[5] = {11, 22, 33, 44, 55};
    int *p = &a[0]; //points to 1st elem of array
    
    printf("%d\n", *p); // Dereferences pointer and gets 11

                                                          // p points to the array, but much nicer-lookin
}