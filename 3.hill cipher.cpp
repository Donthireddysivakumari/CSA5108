#include <stdio.h>
#include <string.h>

int main() {
    int a[3][3] = {{6,24,1},{13,16,10},{20,17,15}};
    int b[3][3] = {{8,5,10},{21,8,21},{21,12,8}};
    int c[20], d[20], i, j, t;
    char msg[20];

    printf("Enter plain text (3 letters, CAPITAL): ");
    scanf("%s", msg);

    for (i = 0; i < 3; i++) c[i] = msg[i] - 65;

    for (i = 0; i < 3; i++) {
        t = 0;
        for (j = 0; j < 3; j++) t += a[i][j] * c[j];
        d[i] = t % 26;
    }

    printf("Encrypted Text: ");
    for (i = 0; i < 3; i++) printf("%c", d[i] + 65);

    for (i = 0; i < 3; i++) {
        t = 0;
        for (j = 0; j < 3; j++) t += b[i][j] * d[j];
        c[i] = t % 26;
    }

    printf("\nDecrypted Text: ");
    for (i = 0; i < 3; i++) printf("%c", c[i] + 65);

    return 0;
}

