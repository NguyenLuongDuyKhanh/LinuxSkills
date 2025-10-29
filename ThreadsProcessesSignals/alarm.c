#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int alarm_fired = 0;

void ding(int sig) {
    alarm_fired = 1;
}

int main_1() {
    pid_t pid;
    
    printf("alarm application starting\n");
    pid = fork();
    printf("%d", pid);
    switch (pid)
    {
    case -1:
        /* Failure */
        perror("fork failed");
        exit(1);
        break;
    case 0:
        /* child*/
        kill(getppid(), SIGALRM);
        exit(0);
    default:
        break;
    }

    /* If we get here, we are the parent process */
    printf("wait for alarm to go off\n");
    (void) signal(SIGALRM, ding);

    printf("done");
    exit(0);
}
