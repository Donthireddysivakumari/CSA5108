#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encipher(), decipher();

int main() {
    int choice;
    while (1) {
        printf("\n1. Encrypt Text\t2. Decrypt Text\t3. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);
        if (choice == 1) encipher();
        else if (choice == 2) decipher();
        else if (choice == 3) exit(0);
        else printf("Invalid Option\n");
    }
}

void encipher() {
    char input[50], key[10];
    int i, j;
    printf("\nEnter Plain Text: ");
    scanf("%s", input);
    printf("Enter Key Value: ");
    scanf("%s", key);
    printf("Cipher Text: ");
    for (i = 0, j = 0; i < strlen(input); i++, j = (j + 1) % strlen(key))
        printf("%c", 65 + ((toupper(input[i]) - 65 + toupper(key[j]) - 65) % 26));
    printf("\n");
}

void decipher() {
    char input[50], key[10];
    int i, j, value;
    printf("\nEnter Cipher Text: ");
    scanf("%s", input);
    printf("Enter Key Value: ");
    scanf("%s", key);
    printf("Plain Text: ");
    for (i = 0, j = 0; i < strlen(input); i++, j = (j + 1) % strlen(key)) {
        value = (toupper(input[i]) - toupper(key[j]) + 26) % 26;
        printf("%c", value + 65);
    }
    printf("\n");
}

