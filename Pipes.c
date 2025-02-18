#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    char buffer[128];

    pipe(pipefd);  // Create a pipe

    if (fork() == 0) {  // Child process
        close(pipefd[1]);  // Close write end
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else {  // Parent process
        close(pipefd[0]);  // Close read end
        write(pipefd[1], "Hello from parent", 18);
        close(pipefd[1]);
    }

    return 0;
}
