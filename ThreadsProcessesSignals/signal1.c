#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch1(int sig) {
    printf("OUCH! - I got signal %d\n", sig);
    (void) signal(SIGINT, SIG_DFL);
}

int main_signal1() {
    (void) signal(SIGINT, ouch1);
    
    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
}