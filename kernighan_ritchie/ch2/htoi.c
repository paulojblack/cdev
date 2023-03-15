#include <stdio.h>
#include <ctype.h>

int my_atoi(char s[]);
int my_htoi(char s[]);

int main() {
    char s[] = "980";
    char hs[] = "bAF"; 

    my_htoi(hs);
}

int my_atoi(char s[]) {
    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = n * 10 + s[i] - '0';
    }

    return n;
}

int my_htoi(char s[]) {
    int n = 0;
    for (int i = 0; isxdigit(s[i]); i++) {
        int digit = 0;
        if (isdigit(s[i])) {
            digit = s[i] - '0';
        } else {
            digit = tolower(s[i]) - 'a' + 10;
        }

        n = n * 16 + digit;
    }

    return n;
}