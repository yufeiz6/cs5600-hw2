#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define NUM_ITERATIONS 10000

int main() {
    int pipe1[2], pipe2[2];
    pid_t child_pid;
    struct timeval start_time, end_time;
    double elapsed_time;

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    child_pid = fork();

    if (child_pid == 0) {
        close(pipe1[1]); 
        close(pipe2[0]);

        for (int i = 0; i < NUM_ITERATIONS; i++) {
            char buffer;
            read(pipe1[0], &buffer, 1); 
            write(pipe2[1], &buffer, 1);
        }

        close(pipe1[0]);
        close(pipe2[1]);
    } else {
        close(pipe1[0]);
        close(pipe2[1]); 
        gettimeofday(&start_time, NULL);

        for (int i = 0; i < NUM_ITERATIONS; i++) {
            char buffer = 'A';
            write(pipe1[1], &buffer, 1); 
            read(pipe2[0], &buffer, 1);  
        }

        gettimeofday(&end_time, NULL);

        elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                       (end_time.tv_usec - start_time.tv_usec) / 1e6;

        printf("Context switch time: %.6f seconds\n", elapsed_time);

        close(pipe1[1]);
        close(pipe2[0]);
    }

    return 0;
}
