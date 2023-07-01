#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t received_signal = 0;  // Global variable to store the received signal

// Signal handler for SIGUSR1
void handleSIGUSR1(int signum) {
    received_signal = SIGUSR1;
}

// Signal handler for SIGUSR2
void handleSIGUSR2(int signum) {
    received_signal = SIGUSR2;
}

// Function to receive and display the string from the client
void receiveStringFromClient() {
    char received_string[100];
    int index = 0;

    while (1) {
        // Wait for the client to send a signal
        pause();

        // Check the received signal
        if (received_signal == SIGUSR1) {
            received_string[index++] = '0';
        } else if (received_signal == SIGUSR2) {
            received_string[index++] = '1';
        } else {
            fprintf(stderr, "Received unknown signal\n");
            exit(EXIT_FAILURE);
        }

        // Reset the received_signal variable for the next iteration
        received_signal = 0;

        // Print the received string if it is complete
        if (received_string[index - 1] == '\0') {
            printf("Received string: %s\n", received_string);
            index = 0;
        }
    }
}

int main() {
    // Register the signal handlers
    signal(SIGUSR1, handleSIGUSR1);
    signal(SIGUSR2, handleSIGUSR2);

    // Display the server PID
    printf("Server PID: %d\n", getpid());

    // Start receiving strings from clients
    receiveStringFromClient();

    return EXIT_SUCCESS;
}
