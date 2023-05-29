#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int isPalindrome(char *str) {
    int len = strlen(str);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j])
            return 0;
    }

    return 1;
}

int main() {
    int pipefd[2];
    pid_t pid;
    char inputStr[BUFFER_SIZE];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(pipefd[1]); // Close the write end of the pipe

        while (1) {
            char result[BUFFER_SIZE];
            ssize_t numRead = read(pipefd[0], inputStr, BUFFER_SIZE);
            if (numRead == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            inputStr[numRead - 1] = '\0'; // Remove the newline character

            if (strcmp(inputStr, "quit") == 0)
                break;

            if (isPalindrome(inputStr))
                strcpy(result, "YES");
            else
                strcpy(result, "NO");

            if (write(pipefd[1], result, strlen(result)) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        close(pipefd[0]); // Close the read end of the pipe
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(pipefd[0]); // Close the read end of the pipe

        while (1) {
            printf("Enter a string (or 'quit' to exit): ");
            fgets(inputStr, BUFFER_SIZE, stdin);

            if (write(pipefd[1], inputStr, strlen(inputStr)) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }

            if (strcmp(inputStr, "quit\n") == 0)
                break;

            char result[BUFFER_SIZE];
            ssize_t numRead = read(pipefd[0], result, BUFFER_SIZE);
            if (numRead == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            result[numRead] = '\0';

            printf("Palindrome check result: %s\n", result);
        }

        close(pipefd[1]); // Close the write end of the pipe
        wait(NULL); // Wait for the child process to terminate
        exit(EXIT_SUCCESS);
    }

    return 0;
}
