#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("This is Child\n");
    } else {
        int rc_wait = wait(NULL);
        printf("rc_wait%d\n", rc_wait);
        printf("This is Parent\n");
    }

    return 0;
}
