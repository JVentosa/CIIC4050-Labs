
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork failed!\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        execlp("/bin/ps", "ps", NULL);
        PRINTF("Still around...\n");
    }
    else
    {
        wait(NULL);
        printf("Parent process: Child PID = %d\n", pid);
        exit(0);
    }
    return 0;
}
