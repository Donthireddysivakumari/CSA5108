#include <stdio.h>
#include <string.h>

int main() {
    char a[20], c[20], d[20];
    int i, j, l, k;

    printf("\nRail Fence Technique\n");
    printf("Enter the input string: ");
    gets(a);

    l = strlen(a);

    // Ciphering
    for (i = 0, j = 0; i < l; i += 2) c[j++] = a[i];
    for (i = 1; i < l; i += 2) c[j++] = a[i];
    c[j] = '\0';

    printf("\nCipher Text: %s", c);

    // Deciphering
    k = (l + 1) / 2;
    for (i = 0, j = 0; i < k; i++, j += 2) d[j] = c[i];
    for (i = k, j = 1; i < l; i++, j += 2) d[j] = c[i];
    d[l] = '\0';

    printf("\nDecrypted Text: %s\n", d);

    return 0;
}

