#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Print the PID and PPID of the original process
    printf("Original process with PID %d and PPID %d\n", getpid(), getppid());

    pid_t childPid = fork();

    if (childPid < 0) {
        perror("Fork failed");
        return -1;
    } else if (childPid == 0) {  // Child process
        // Print the PID and PPID of the child process
        printf("Child process with PID %d and PPID %d\n", getpid(), getppid());

        pid_t grandChildPid = fork();

        if (grandChildPid < 0) {
            perror("Fork failed");
            return -1;
        } else if (grandChildPid == 0) {  // Grandchild process
            // Print the PID and PPID of the grandchild process
            printf("Grandchild process with PID %d and PPID %d\n", getpid(), getppid());
            sleep(2); // wait for 2 seconds
            printf("Grandchild is about to exit\n");
            return 0;
        } else {
            wait(NULL); // Wait for the grandchild to terminate
            printf("Child is about to exit\n");
            return 0;
        }
    } else {  // Parent process
        sleep(2); // wait for 2 seconds
        printf("Parent process with PID %d and PPID %d\n", getpid(), getppid());
        execlp("ps", "ps", "-e", NULL); // Execute the "ps" command
    }

    return 0;
}

