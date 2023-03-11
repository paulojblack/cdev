#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    int outerVar = 100;
    int *p;
    int rc = fork();


    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }

    if (rc == 0) {
        fprintf(stdout, "In child process \n");
        fprintf(stdout, "(child) Variable value is: %d \n", outerVar);

        outerVar += 10;

        fprintf(stdout, "(child) Variable value, incremented, is: %d \n", outerVar);
    } else {
        int wc = wait(NULL);
        assert(wc >= 0);
        fprintf(stdout, "(parent) Variable value is: %d \n", outerVar);
        outerVar += 10;

        fprintf(stdout, "(parent) Variable value, incremented, is: %d \n", outerVar);
    }

    return 0;
}