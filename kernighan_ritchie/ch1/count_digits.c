#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 10

int main() {
    int c , whitespace, chars = 0;
    int ndigit[ARR_LEN];

    // Initialize array to zeroes
    for (int i = 0; i < ARR_LEN; i++) {
        ndigit[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++whitespace;
        } else {
            ++chars;
        }
    }

    printf("Whitespace characters: %d\n", whitespace);
    printf("Other characters: %d\n", chars);
    printf("Digits: \n");

    for (int i = 0; i < ARR_LEN; i++) {
        printf("%d: %d\n", i, ndigit[i]);
    }

    exit(0);

}