#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    printf("POSIX version is set to %ld\n", _POSIX_VERSION);
    if (_POSIX_VERSION < 199506L) {
        if (_POSIX_C_SOURCE >= 199506L) {
            printf("Sorry, your system does not support POSIX1003.1c threads\n");
        } else {
            printf("Try agian with -D_POSIX_C_SOURCE=199506L\n");
        }
    } else {
        printf("Your system supports POSIX1003.1c threads,\n");
        #ifdef _POSIX_THREAD_PRIORITY_SCHEDULING // La sao? sao de check
            printf("Including support for priotiry scheduling\n");
        #else
            printf("But does not support priority scheduling\n");
        #endif
    }
    // exit(EXIT_SUCCESS);
    return 0;
}