#include <iostream>
#include <csignal>
#include <unistd.h>
#include <cstdlib>

void handleSignal(int signal) {
    if (signal == SIGUSR1) {
        std::cout << "Caught SIGUSR1: Custom user-defined signal!" << std::endl;
    }
}

int main() {
    std::signal(SIGUSR1, handleSignal);

    std::cout << "Program running. PID: " << getpid() << std::endl;
    std::cout << "Send SIGUSR1 using: kill -USR1 " << getpid() << std::endl;

    while (true) {
        pause();  // Wait for signals
    }
    std::cout << "Should not get executed";
    return 0;
}
