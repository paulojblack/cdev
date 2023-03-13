#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Err: Not enough args\n");
        exit(1);
    }
    char *data;
    pid_t mypid = getpid();
    int msize = atoi(argv[1]);
    int bytes = 1024 * msize;
    printf("User input: %d to allocate %d bytes\n", msize, bytes);

    data = (char *) malloc(bytes);

    while(1) {

        for (int i=0; i < bytes; i++) {
            printf("%d\n", mypid);
            data[i] = 'a';
            printf("%c\n", data[i]);
        }
    }
    exit(0);
}
