#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    int child1_pid = fork(); 
    int child2_pid = fork();


    if (child1_pid < 0 || child2_pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (child1_pid == 0 && child2_pid == 0) {
        close(pipe_fd[0]); 

        dup2(pipe_fd[1], STDOUT_FILENO);

        execlp("echo", "echo", "Hello from Child 1", NULL);

        close(pipe_fd[1]); 

        dup2(pipe_fd[0], STDIN_FILENO);

        execlp("cat", "cat", NULL);
    } 

    close(pipe_fd[0]);
    close(pipe_fd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
