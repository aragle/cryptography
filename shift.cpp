#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, int shift)
{
    string result = "";

    // Iterate through each character in the message
    for (int i = 0; i < message.length(); i++)
    {
        // Shift the character by the given amount
        char c = message[i] + shift;

        // Wrap around if the shifted character goes beyond 'z'
        if (c > 'z')
            c = 'a' + (c - 'z' - 1);

        result += c;
    }

    return result;
}

string decrypt(string message, int shift)
{
    string result = "";

    // Iterate through each character in the message
    for (int i = 0; i < message.length(); i++)
    {
        // Shift the character by the given amount
        char c = message[i] - shift;

        // Wrap around if the shifted character goes beyond 'a'
        if (c < 'a')
            c = 'z' - ('a' - c - 1);

        result += c;
    }

    return result;
}

int main()
{
    string message = "hello world";
    int shift = 3;

    // Encrypt the message
    string encrypted = encrypt(message, shift);
    cout << "Encrypted message: " << encrypted << endl;

    // Decrypt the message
    string decrypted = decrypt(encrypted, shift);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
