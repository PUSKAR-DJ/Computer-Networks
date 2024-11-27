#include <stdio.h>
#include <string.h>

int calculate_parity_bit(const char *binary_str, char parity_choice) {
    int num_ones = 0;
    for (int i = 0; binary_str[i] != '\0'; i++) {
        if (binary_str[i] == '1') {
            num_ones++;
        }
    }

    if (parity_choice == 'e') {
        return num_ones % 2;
    } else if (parity_choice == 'o') {
        return (num_ones + 1) % 2;
    } else {
        printf("Invalid parity choice!\n");
        return -1;
    }
}

int main() {
    char binary[100];
    char parity_choice;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    printf("Choose parity- even(e) or odd(o): ");
    scanf(" %c", &parity_choice);

    // Validate input (e.g., check for invalid characters)

    int parity_bit = calculate_parity_bit(binary, parity_choice);
    if (parity_bit == -1) {
        return 1;
    }

    // Append the parity bit to the binary string
    int len = strlen(binary);
    binary[len] = parity_bit + '0';
    binary[len + 1] = '\0';

    printf("Parity encoded data: %s\n", binary);

    return 0;
}