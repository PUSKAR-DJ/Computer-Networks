// Decoding using Parity bit nmethod(Receiver's Side)
#include <stdio.h>
#include <string.h>
int main()
{
    char binary[100];
    char i, count = 0;
    char parity_choice;

    // Input binary number as a string
    printf("Enter a binary number: ");
    scanf("%s", &binary);
    // Ask the user for parity type
    printf("Choose parity- even(e) or odd(o): ");
    scanf("%s", &parity_choice);
    // Count the number of 1s in the binary string
    for (i = 0; i < strlen(binary) - 1; i++)
    {
        // Exclude the parity bit
        if (binary[i] == '1')
        {
            count++;
        }
    }
    // Calculate parity and check for errors
    if (parity_choice == 'e')
    {
        // Even parity
        if (count % 2 != 0)
        {
            printf("Error detected in the received data!\n");
            return 1;
        }
    }
    else if (parity_choice == 'o')
    {
        // Odd parity
        if (count % 2 == 0)
        {
            printf("Error detected in the received data!\n");
            return 1;
        }
    }
    else
    {
        printf("Invalid parity choice!\n");
        return 1;
    }
    // Remove the parity bit and output the decoded binary number
    binary[strlen(binary) - 1] = '\0'; // Remove the parity bit
    printf("Decoded Binary number: %s\n", binary);
    return 0;
}