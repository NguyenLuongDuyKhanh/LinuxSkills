#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main_fork2() {
    pid_t pid;
    char *message;
    int n;
    
    printf("fork program starting\n");
    pid = fork();
    switch(pid) {
        case -1:
            perror("fork failed");
            return 1;
        case 0:
            message = "This is the child";
            n = 1;
            break;
        default:
            message = "This is the parent";
            n = 15;
            break;
    }
    
    for (; n>0; n--) {
        puts(message);
        sleep(1);
    }
    return 0;
}