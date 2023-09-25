#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) {
        execl("/bin/ls", NULL);
        exit(1); 
    } else {
        int rc_wait = wait(NULL); 
        printf("Parent process done.\n");
    }

    return 0;
}
