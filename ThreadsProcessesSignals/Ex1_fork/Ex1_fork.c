#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h> // For PRIdMAX
#include <string.h> // Required for strcat()
#include <stdlib.h>

int main() {
    pid_t pid;
    char *message;
    int n;
    
    printf("fork program starting\n");
    pid = fork();
    pid_t pidsub = getpid();

    switch(pid) {
        case -1:
            perror("fork failed");
            exit(1);
            return 1;
        case 0:
            message = "This is the child";
            n = 5;
            printf("%s %d \n", message, pidsub);
            break;
        default:
            message = "This is the parent";
            n = 3;
            printf("%s %d \n", message, pidsub);
            break;
    }

    for (; n>0; n--) {
        puts(message);
        sleep(10);
    }

    exit(0);
    return 0;
}