#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

int main() {
    sem_t *sem = sem_open("/my_semaphore", O_CREAT | O_EXCL, 0644, 0);

    if (sem == SEM_FAILED) {
        exit(1);
    }

    int rc = fork();

    if (rc < 0) {
        exit(1);
    } else if (rc == 0) {
        printf("Hello\n");
        sem_post(sem); 
        exit(0);
    } else {
        sem_wait(sem); 
        printf("Goodbye\n");
        sem_close(sem); 
        sem_unlink("/my_semaphore");
    }

    return 0;
}
