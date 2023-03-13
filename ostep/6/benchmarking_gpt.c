#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

#define BUF_SIZE 64

int main()
{
    int fd[2];
    pid_t pid;
    char buf[BUF_SIZE];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }

    if (pid == 0)
    {
        /* Child process */
        close(fd[0]); /* Close unused read end */

        struct timeval start, end;
        int count = 0;

        gettimeofday(&start, NULL);
        while (1)
        {
            write(fd[1], buf, 0);
            read(fd[1], buf, BUF_SIZE);
            count++;
            gettimeofday(&end, NULL);
            if (end.tv_sec - start.tv_sec >= 1)
            {
                printf("Context switch time: %f us\n", ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / (double)count);
                count = 0;
                gettimeofday(&start, NULL);
            }
        }
    }
    else
    {
        /* Parent process */
        close(fd[1]); /* Close unused write end */

        while (1)
        {
            read(fd[0], buf, BUF_SIZE);
            write(fd[0], buf, 0);
        }
    }

    return 0;
}