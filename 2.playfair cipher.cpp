#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void findPosition(char key[SIZE][SIZE], char c, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (key[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encryptPair(char a, char b, char key[SIZE][SIZE]) {
    int row1, col1, row2, col2;
    findPosition(key, a, &row1, &col1);
    findPosition(key, b, &row2, &col2);
    if (row1 == row2) {
        printf("%c%c", key[row1][(col1 + 1) % SIZE], key[row2][(col2 + 1) % SIZE]);
    } else if (col1 == col2) {
        printf("%c%c", key[(row1 + 1) % SIZE][col1], key[(row2 + 1) % SIZE][col2]);
    } else {
        printf("%c%c", key[row1][col2], key[row2][col1]);
    }
}
int main() {
    char key[SIZE][SIZE];
    char keyInput[30], plaintext[100], processed[100];
    char alphabet[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; 
    int i, j, k = 0, m = 0, n;
    printf("Enter the key: ");
    scanf("%s", keyInput);
    n = strlen(keyInput);
    for (i = 0; i < n; i++) {
        keyInput[i] = toupper(keyInput[i]);
        if (keyInput[i] == 'J') keyInput[i] = 'I';
    }
    char used[26] = {0};
    for (i = 0; i < n; i++) {
        if (!used[keyInput[i] - 'A']) {
            key[k / SIZE][k % SIZE] = keyInput[i];
            used[keyInput[i] - 'A'] = 1;
            k++;
        }
    }
    for (i = 0; i < 25; i++) {
        if (!used[alphabet[i] - 'A']) {
            key[k / SIZE][k % SIZE] = alphabet[i];
            used[alphabet[i] - 'A'] = 1;
            k++;
        }
    }
    printf("\nKey Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", key[i][j]);
        }
        printf("\n");
    }
	printf("\nEnter the plaintext: ");
    scanf("%s", plaintext);
    n = strlen(plaintext);
    k = 0;
    for (i = 0; i < n; i++) {
        char current = toupper(plaintext[i]);
        if (current == 'J') current = 'I';
        processed[k++] = current;
        if (i < n - 1) {
            char next = toupper(plaintext[i + 1]);
            if (next == 'J') next = 'I';             
            if (current == next) {
                processed[k++] = 'X'; 
            }
        }
    }
    if (k % 2 != 0) {
        processed[k++] = 'X'; 
    }
    processed[k] = '\0';
    printf("\nCipher Text: ");
    for (i = 0; i < k; i += 2) {
        encryptPair(processed[i], processed[i + 1], key);
    }
    printf("\n");
    return 0;
}

