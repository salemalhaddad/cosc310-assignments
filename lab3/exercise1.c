#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<math.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    int exit_status;

    printf("PID = %d, PPID = %d", getpid(), getppid());

    fork();

    if(pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    printf("PID = %d, PPID = %d", getpid(), getppid());
    
    wait(&exit_status);

    printf("PID = %d, PPID = %d", getpid(), getppid());
}
