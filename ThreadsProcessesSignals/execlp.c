#include <unistd.h>
#include <stdio.h>

int main_2() {
    printf("Running ps with execlp");
    execlp("ps", "ps", "-l", 0);
    printf("Done.\n");
    
    // exit(0);
    return 0;
}