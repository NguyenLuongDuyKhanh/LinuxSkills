#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Running ps %d with system\n", getpid());
    system("./sampleUtility &");
    printf("Done.\n");

    return 0;
}