#include <stdio.h>
#include <math.h>
#include <string.h>

long int p, q, n, t, e, d, m[100], en[100], i;
char msg[100];

int prime(long int num) {
    int j;
    for (j = 2; j <= sqrt(num); j++) {
        if (num % j == 0)
            return 0;
    }
    return 1;
}

long int modInverse(long int a, long int m) {
    long int m0 = m, t, q;
    long int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

void encrypt() {
    long int pt, ct, k;
    printf("\nEncrypted message: ");
    for (i = 0; msg[i] != '\0'; i++) {
        pt = msg[i] - 96;
        k = 1;
        for (int j = 0; j < e; j++) {
            k = (k * pt) % n;
        }
        en[i] = k + 96;
        printf("%c", en[i]);
    }
    en[i] = -1;
}

void decrypt() {
    long int ct, pt, k;
    printf("\nDecrypted message: ");
    for (i = 0; en[i] != -1; i++) {
        ct = en[i] - 96;
        k = 1;
        for (int j = 0; j < d; j++) {
            k = (k * ct) % n;
        }
        m[i] = k + 96;
        printf("%c", m[i]);
    }
    m[i] = -1;
}

int main() {
    printf("Enter first prime number: ");
    scanf("%ld", &p);
    if (!prime(p)) {
        printf("Wrong input\n");
        return 0;
    }
    printf("Enter second prime number: ");
    scanf("%ld", &q);
    if (!prime(q) || p == q) {
        printf("Wrong input\n");
        return 0;
    }
    printf("Enter message: ");
    fflush(stdin);
    gets(msg);

    n = p * q;
    t = (p - 1) * (q - 1);

    // Simple fixed e
    for (e = 2; e < t; e++) {
        if (prime(e) && (t % e != 0))
            break;
    }
    d = modInverse(e, t);

    printf("\nPublic key (e, n): (%ld, %ld)", e, n);
    printf("\nPrivate key (d, n): (%ld, %ld)", d, n);

    encrypt();
    decrypt();

    return 0;
}

