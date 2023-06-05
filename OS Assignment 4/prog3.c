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
            return 0;  // Not a palindrome
    }
    
    return 1;  // Palindrome
}

int main() {
    int pipefd[2];
    char buffer[BUFFER_SIZE];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // Parent process
        close(pipefd[0]);  // Close the reading end of the pipe

        while (1) {
            printf("Enter a string: ");
            fgets(buffer, BUFFER_SIZE, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character

            if (strcmp(buffer, "quit") == 0) {
                write(pipefd[1], buffer, BUFFER_SIZE);
                break;
            }

            write(pipefd[1], buffer, BUFFER_SIZE);

            char response[BUFFER_SIZE];
            read(pipefd[0], response, BUFFER_SIZE);

            printf("Response from child: %s\n", response);
        }

        close(pipefd[1]);  // Close the writing end of the pipe
    } else {
        // Child process
        close(pipefd[1]);  // Close the writing end of the pipe

        while (1) {
            read(pipefd[0], buffer, BUFFER_SIZE);

            if (strcmp(buffer, "quit") == 0)
                break;

            int isPalindromeResult = isPalindrome(buffer);
            if (isPalindromeResult)
                strcpy(buffer, "YES");
            else
                strcpy(buffer, "NO");

            write(pipefd[1], buffer, BUFFER_SIZE);
        }

        close(pipefd[0]);  // Close the reading end of the pipe
    }

    return 0;
}
