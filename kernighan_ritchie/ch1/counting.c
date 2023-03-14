#include <stdio.h>

int main(void) {
    int c, nl;

    nl = 0;
    while( (c = getchar()) != EOF) {
        if (c == ' ') {
            while ((c = getchar()) == ' ') {
                continue;
            }
            putchar(' ');
            putchar(c);
        } else if (c == '\n') {
            putchar('\n');
        } else {
            putchar(c);
        }
    }

    printf("%d\n", nl);
}