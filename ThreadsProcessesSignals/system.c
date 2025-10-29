#include <stdlib.h>
#include <stdio.h>

int main_system() {
    printf("Running ps with system\n");
    system("ps -l &");
    printf("Done.\n");
    
    // exit(0);
    return 0;
}