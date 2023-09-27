#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    struct timeval start_time, end_time;
    double elapsed_time;
    pid_t pid;
    int iterations = 10000; 
    int i;

    gettimeofday(&start_time, NULL);

    for (i = 0; i < iterations; i++) {
        pid = getpid();
    }

    gettimeofday(&end_time, NULL);

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                   (end_time.tv_usec - start_time.tv_usec) / 1e6;

    printf("Total elapsed time for 10000 syscalls: %.6f seconds\n", elapsed_time);

    return 0;
}
