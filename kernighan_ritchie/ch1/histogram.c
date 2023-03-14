#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 10

// Problem: not dynamically resizing array so just picking length 10 as max word length
int main() {
    int c, curWordLen = 0;
    int wordHist[ARR_LEN];

    // Initialize arr
    for (int i = 0; i < ARR_LEN; i++) {
        wordHist[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (curWordLen > 0) {
                ++wordHist[curWordLen];
            }
            curWordLen = 0;
        } else {
            ++curWordLen;
        }
    }

    for (int i = 0; i < ARR_LEN; i++) {
        printf("%d: ", i);
        for (int j = 0; j < wordHist[i]; j++) {
            printf("+");
        }
        printf("\n");
    }

    exit(0);
}