#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <signal.h>

// Prompt: Reliably send output from child process before parent process
// WITHOUT using wait()

void sig_handler(int signum)
{
    printf("in parent process\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    int parent_pid = getpid();
    int rc = fork();

    if (rc < 0)
    {
        printf("fork failed\n");
        exit(1);
    }

    if (rc == 0)
    {
        printf("In child process \n");
        kill(parent_pid, SIGCONT);
    }
    else
    {
        signal(SIGCONT, sig_handler);
        pause();

    }

    return 0;
}