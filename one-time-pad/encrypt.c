#include <stdio.h>
#include <string.h>

void Encrypt(char message[], char key[])
{

    int len = strlen(message);
    char cipher[1000];

    for (int i = 0; i < len; i++)
    {
        cipher[i] = ((message[i] - 'A') ^ (key[i] - 'A')) + 'A';
    }
    cipher[len] = '\0';

    printf("The encrypted message is: %s\n", cipher);
}

int main()
{
    char message[1000], key[1000];

    printf("Enter the message: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%s", key);

    Encrypt(message, key);

    return 0;
}