#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
int main() 
{ 
    char plain[100], cipher[100]; 
    int key, i, length; 
    
    printf("\nEnter the plain text: "); 
    scanf("%s", plain); 
    
    printf("\nEnter the key value: "); 
    scanf("%d", &key); 
    
    printf("\n\n\tPLAIN TEXT: %s", plain); 
    
    printf("\n\n\tENCRYPTED TEXT: "); 
    
    length = strlen(plain);
    for (i = 0; i < length; i++) 
    { 
        cipher[i] = plain[i] + key; 
        
        if (isupper(plain[i]) && (cipher[i] > 'Z')) 
            cipher[i] -= 26; 
        if (islower(plain[i]) && (cipher[i] > 'z')) 
            cipher[i] -= 26; 
        
        printf("%c", cipher[i]); 
    } 
    cipher[i] = '\0'; 
    printf("\n\n\tAFTER DECRYPTION: "); 
    for (i = 0; i < length; i++) 
    { 
        plain[i] = cipher[i] - key; 
        
        if (isupper(cipher[i]) && (plain[i] < 'A')) 
            plain[i] += 26; 
        if (islower(cipher[i]) && (plain[i] < 'a')) 
            plain[i] += 26; 
        
        printf("%c", plain[i]); 
    } 
    plain[i] = '\0'; 
    printf("\n");
    
    return 0; 
}
