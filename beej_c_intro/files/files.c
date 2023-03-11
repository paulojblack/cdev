#include <stdio.h>

int main(void) {
    // File print to stdout
    fprintf(stdout, "printing to stdout\n");
    fprintf(stderr, "printing to stderr\n");

    FILE* fp;

    fp = fopen("hello.txt", "r");

    char c = fgetc(fp);

    printf("First char of file: %c\n", c);
    fclose(fp);
}