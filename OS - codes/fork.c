#include <stdio.h>
#include <stdlib.h>  // Added for exit() function
#include <unistd.h>  // Added for fork(), getpid(), getppid(), execvp()
#include <sys/wait.h>  // Added for wait()
#include <string.h>  // Added for strlen()

int main(int argc, char *argv[]) {
    int pid;
    char s[100];

    pid = fork();

    if (pid < 0) {
        printf("Error forking process\n");
    } else if (pid > 0) {  // Parent process
        wait(NULL);  // Wait for the child process to finish
        printf("\nParent Process:\n");
        printf("\nParent Process id: %d\n", getpid());
        execlp("cat", "cat", argv[1], (char *)0);
        perror("can't execute cat");  // Print an error if execlp fails
        exit(1);  // Exit the program with an error code
    } else {  // Child process
        printf("\nChild process:\n");
        printf("\nChild process parent id: %d\n", getppid());
        sprintf(s, "\nChild process id: %d\n", getpid());
        write(1, s, strlen(s));
        printf(" ");

        execvp(argv[2], &argv[2]);
        perror("can't execute");  // Print an error if execvp fails
        exit(1);  // Exit the program with an error code
    }

    return 0;
}