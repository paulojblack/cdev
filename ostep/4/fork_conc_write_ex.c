#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

    int main(int argc, char *argv[])
{
    close(STDOUT_FILENO);
    open("./fork_output", O_CREAT | O_WRONLY | S_IRWXU);

    int rc = fork();

    if (rc < 0)
    {
        printf("fork failed\n");
        exit(1);
    }

    if (rc == 0)
    {
        printf("In child process \n");
    

    }
    else
    {
        // int wc = wait(NULL);
        // assert(wc >= 0);
        printf("In parent process \n");
    }

    return 0;
}