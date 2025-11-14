#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid;
    int n;
    
    printf("fork program starting\n");
    pid = fork();

    switch(pid) {
        case -1:
            perror("fork failed");
            return 1;
        case 0:
            printf("This is the child %d\n", getpid());
            n = 1;
            break;
        default:
            printf("This is the parent %d\n", getpid());
            n = 2;
            break;
    }

    for (; n>0; n--) {
        sleep(30);
    }
    printf("The process %d completed\n", getpid());
    return 0;
}