#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Experimenting with multiple child processes
int main(int argx, char *argv[]) {
    int rc = fork();
    int rc2 = fork();

    int outerpid = getpid();
    printf("outer pid: %d\n", outerpid);

    if (rc == 0) {
        pid_t cpid = getpid();
        printf("(child)\n");
        printf("(child) pid: %d\n", cpid);
    } else {
        // pid_t wc_pid = wait(NULL);
        pid_t ppid = getpid();
        printf("(parent)\n");
        // printf("wc_pid: %d\n", wc_pid);
        printf("ppid: %d\n", ppid);
    }

    exit(0);
}