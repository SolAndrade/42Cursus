#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Function to send the string to the server using signals
void sendStringToServer(pid_t server_pid, const char* string) {
    // Send each character of the string to the server
    for (int i = 0; string[i] != '\0'; i++) {
        // Determine the signal based on the character value
        int signal = (string[i] == '0') ? SIGUSR1 : SIGUSR2;
        
        // Send the signal to the server process
        if (kill(server_pid, signal) == -1) {
            perror("Error sending signal to server");
            exit(EXIT_FAILURE);
        }
        
        // Wait for the server to acknowledge the signal
        pause();
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_pid> <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Extract the server PID from the command-line arguments
    pid_t server_pid = atoi(argv[1]);

    // Send the string to the server
    sendStringToServer(server_pid, argv[2]);

    return EXIT_SUCCESS;
}
