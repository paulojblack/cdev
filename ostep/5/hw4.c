#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argx, char *argv[]) {
    int rc = fork();

    if (rc < 0) {
        exit(1);
    }

    if (rc == 0) {
        // char *lsargs[3];
        printf("I am the child");
        execl("/usr/bin/wc", "./hw4.c");
    } else {
        printf("I am the parent");
    }

    exit (0);
}