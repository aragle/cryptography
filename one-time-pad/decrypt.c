#include <stdio.h>
#include <string.h>

void Decrypt(char cipher[], char key[])
{

    int len = strlen(cipher);
    char message[1000];

    for (int i = 0; i < len; i++)
    {
        message[i] = ((cipher[i] - 'A') ^ (key[i] - 'A')) + 'A';
    }
    message[len] = '\0';

    printf("The decrypted message is: %s\n", message);
}

int main()
{
    char cipher[1000], key[1000];
    
    printf("Enter the encrypted message: ");
    scanf("%s", cipher);
    printf("Enter the key: ");
    scanf("%s", key);

    Decrypt(cipher, key);

    return 0;
}