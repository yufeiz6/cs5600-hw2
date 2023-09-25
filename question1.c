#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int x = 100;

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("This is Child: x = %d\n", x);
        x += 200;
        printf("This is Child: Updated x = %d\n", x);
    } else {
        printf("This is Parent: x = %d\n", x);
        x += 300;
        printf("This is Parent: Updated x = %d\n", x);
    }

    return 0;
}
