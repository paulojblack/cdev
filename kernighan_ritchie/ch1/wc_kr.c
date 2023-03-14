#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nc, nl, nw, state;

    nc = nl = nw = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == '\n') {
            ++nl;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("Total wordcount of input:\n");
    printf("Number of characters: %d\n", nc);
    printf("Number of words: %d\n", nw);
    printf("Number of lines: %d\n", nl);

}