/**
 * 1. Set up 2 processes and set affinity to same core
 * 2. Test gettimeofday and rdtsc
 * 3. Look at lmbench separately?
 * 4. Set up pipe from one process to another, reading from one and writing to the other
 * 5. Measure time between reads and writes N times and average
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#define MAX 10

// Experimenting with multiple child processes
int main(int argx, char *argv[])
{
    struct timeval tv;
    struct timezone tz;

    gettimeofday(&tv, &tz);

    // printf("Seconds since 1/1/1970: %lu\n", tv.tv_sec);
    printf("Microseconds: %d\n", tv.tv_usec);
    // printf("Minutes west of Greenwich: %d\n", tz.tz_minuteswest);
    // printf("Daylight Saving Time adjustment: %d\n", tz.tz_dsttime);

    int fd[2], i = 0;
    pipe(fd);
    pid_t rc = fork();

    if (rc < 0) {
        fprintf(stderr,"fork attempt failed\n");
    }
    if (rc > 0)
    {
        printf("(parent)\n");
        wait(NULL); // wait for child process to finish

        close(0); // close stdin

        close(fd[1]); // close write end of pipe

        dup(fd[0]);
        int arr[MAX];

        // n stores the total bytes read successfully
        int n = read(fd[0], arr, sizeof(arr));
        for (i = 0; i < n / 4; i++)

            // printing the array received from child process
            printf("%d ", arr[i]);
        printf ("\n");
    }
    else
    {
        printf("(child)\n");
        int arr[] = {1, 2, 3, 4, 5};

        // no need to use the read end of pipe here so close it
        close(fd[0]);

        // closing the standard output
        close(1);

        // duplicating fd[0] with standard output 1
        dup(fd[1]);
        write(1, arr, sizeof(arr));
    }

    exit(0);
}