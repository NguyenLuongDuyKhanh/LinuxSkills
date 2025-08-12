/*
*/
#include <iostream>
#include <csignal>   // For signal(), SIGALRM
#include <unistd.h>  // For alarm()

// Signal handler
void handle_alarm(int signum) {
    std::cout << "\nAlarm triggered! Signal number: " << signum << std::endl;
}

int main() {
    // Set up the signal handler for SIGALRM
    std::signal(SIGALRM, handle_alarm);

    std::cout << "Setting an alarm for 5 seconds...\n";
    alarm(5); // Schedule SIGALRM in 5 seconds

    // Simulate doing other work
    for (int i = 0; i < 10; i++) {
        std::cout << "Working... " << i << std::endl;
        sleep(1);
    }

    std::cout << "Program finished.\n";
    return 0;
}
