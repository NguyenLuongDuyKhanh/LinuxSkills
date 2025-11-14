#include <unistd.h>
#include <stdio.h>

int main() {
    printf("Running ps %d with execlp\n", getpid());
    
    // execlp("ps", "ps", "-l", 0);
    execlp("./sampleUltility", "sampleUtility","",0);


    printf("Go to sleep ");
    fflush(stdout);
    sleep(10);
    printf("Done.\n");

    return 0;
}