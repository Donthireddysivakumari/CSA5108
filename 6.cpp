#include <stdio.h>
#include <string.h>

void simple_encrypt(char *input, char *output, char key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ key; // Simple XOR encryption
    }
    output[i] = '\0';
}

void simple_decrypt(char *input, char *output, char key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ key; // XOR decryption
    }
    output[i] = '\0';
}

int main() {
    char input[100], encrypted[100], decrypted[100];
    char key = 'K'; // simple key (character)
    
    printf("Enter message: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline

    simple_encrypt(input, encrypted, key);

    printf("\nEncrypted message (hex): ");
    for (int i = 0; encrypted[i] != '\0'; i++) {
        printf("%02X ", (unsigned char)encrypted[i]);
    }
    printf("\n");

    simple_decrypt(encrypted, decrypted, key);
    printf("\nDecrypted message: %s\n", decrypted);

    return 0;
}

