#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
void read_process_state(pid_t pid);
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
        sleep(5);
    }

    /* Parent process query the child process's state. Expected it is zombie process */
    if (pid != 0) {
        read_process_state(pid);
    }
    printf("The process %d completed\n", getpid());

    return 0;
}

void read_process_state(pid_t pid) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Failed to open stat file");
        // Handle error
    }

    char state;
    // Read up to the third field (PID, command name, then state)
    // The command name can contain spaces, so read it carefully.
    // A common way is to read everything until the state character.
    // For simplicity, we'll assume a basic structure here.
    long dummy_pid;
    char comm[256];
    fscanf(fp, "%ld %s %c", &dummy_pid, comm, &state);

    fclose(fp);
    printf("Process %d State: %c\n", pid, state);
}