#include <stdio.h>
#include <stdlib.h>

// LoooooooooooooooooooooLoooooooooooooooooooooLoooooooooooooooooooooLoooooooooooooooooooooLoooooooooooooooooooooLoooooooooooooooooooooLooooooooooooooooooooong
int main() {
    char *line = NULL; // This is the line itself (char array? pointer to first char in a contiguous addr?)
    size_t len = 0; // This is the length of the buffer, which dynamically resizes in 4byte increments to contain whatever the largest line length seen so far is
    ssize_t nread; // ssize_t, return type of getline, signed size

    int numBigNuff = 0;
    while ((nread = getline(&line, &len, stdin)) > 0) {

        if (nread > 80) {
            ++numBigNuff;
            printf("%s", line);
        }
    }

    printf("Found %d lines larger than 80 chars\n", numBigNuff);
}