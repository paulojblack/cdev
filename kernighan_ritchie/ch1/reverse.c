#include <stdio.h>
#include <string.h>

void reverse(char* s);

int main() {
    char* line = NULL;
    size_t buf = 0;
    ssize_t charcount;

    while ((charcount = getline(&line, &buf, stdin)) > 0) {
        reverse(line);
        printf("%s\n", line);
    }
}

void reverse(char* s) {
    int len = strlen(s);
    char tmp;
    for (int i = 0; i < (len / 2 + 1); i++) {
        tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;

    }
}