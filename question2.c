#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    int rc;

    fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    rc = fork();

    if (rc < 0) {
        perror("fork");
        exit(1);
    } else if (rc == 0) {
        const char* childMessage = "From Child process.\n";
        write(fd, childMessage, strlen(childMessage));
    } else {
        const char* parentMessage = "From Parent process.\n";
        write(fd, parentMessage, strlen(parentMessage));
    }

    close(fd);
    return 0;
}
