#include <stdio.h> 
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); 

    if (pid == 0) {
        char *args[] = {"ls", "-al", NULL};
        execvp(args[0], args); 
    } else {
        wait(NULL);
    }

    return 0;
}

