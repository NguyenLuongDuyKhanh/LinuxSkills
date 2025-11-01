#include <stdio.h>
#include <stdlib.h> // Required for EXIT_SUCCESS and EXIT_FAILURE
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define ECHOMAX 255

extern void* memset(void* ptr, int value, size_t num);

int main(int argc, char *argv[]) {
    int sock;                           /* Socket */
    struct sockaddr_in echoServAddr;    /* Local address */
    struct sockaddr_in echoClntAddr;    /* Client address */
    unsigned int cliAddrLen;            /* Length of incoming message */
    char echoBuffer[ECHOMAX + 1];       /* Buffer for echo string */
    char clientAddr[INET_ADDRSTRLEN];
    int recvMsgSize;                    /* Size of received message */

    if (argc != 2) {
        fprintf(stderr, "usage %s port\n", argv[0]);
        return EXIT_SUCCESS;
    }

    /* Create socket for sending/receiving datagrams */
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return EXIT_SUCCESS;
    }

    /* Construct local address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr)); /* Zero out structure */
    echoServAddr.sin_family = AF_INET;              /* Internet address family */
    echoServAddr.sin_addr.s_addr = INADDR_ANY;
    echoServAddr.sin_port = htons(atoi(argv[1]));

    /* Bind to the local address */
    bind(sock, (struct sockaddr*) &echoServAddr, sizeof(echoServAddr));

    /* Run forever */
    for (;;) { 
        cliAddrLen = sizeof(echoClntAddr);

        /* Block until receive message from a client */
        recvMsgSize = recvfrom(
            sock, 
            echoBuffer, 
            ECHOMAX, 
            0,
            (struct sockaddr *) &echoClntAddr,
            &cliAddrLen
        );

        /* Convert sockaddr to string */
        inet_ntop(
            AF_INET,
            &(echoClntAddr.sin_addr),
            clientAddr,
            INET_ADDRSTRLEN
        );
        printf("Handling Client: %s: %d\n", clientAddr, ntohs(echoClntAddr.sin_port));

        /* Send received datagram back to the client */
        echoBuffer[recvMsgSize + 1] = '\0';         /* just for safety */
        printf("Echoing: %s\n", echoBuffer);
        sendto(
            sock, 
            echoBuffer, 
            recvMsgSize, 
            0,
            (struct sockaddr *) &echoClntAddr,
            sizeof(echoClntAddr)
        );
    }

    return EXIT_SUCCESS;
} /* end of main() */