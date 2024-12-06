#include <stdio.h>
#include <string.h>

// Vulnerable function: Simulates a common coding error
void vulnerable_function(char *input)
{
    // Declare a buffer with a fixed size of 64 bytes
    char buffer[64];
    // Unsafe copying leading to buffer overflow
    // it will overwrite memory beyond the buffer.
    strcpy(buffer, input);
    // Print the contents of the buffer to show what was copied
    printf("Buffer contains: %s\n", buffer);
}

// Main function
int main(int argc, char *argv[])
{
    // Check if exactly one argument is provided
    if (argc != 2)
    {
        // If no input is provided, print usage instructions and exit with an error code
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    // Call the vulnerable function with the provided input
    // The input is taken from the command-line argument (argv[1]).
    vulnerable_function(argv[1]);

    // Print a message to indicate that the program executed successfully
    printf("Function returned normally.\n");

    // Return 0 to indicate successful execution
    return 0;
}
