#include <iostream>
#include <string>

using namespace std;

string vigenere_encrypt(string plaintext, string key) {
    string ciphertext = "";
    int keyIndex = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            c = toupper(c);
            int keyChar = key[keyIndex % key.length()] - 'A';
            int plainChar = c - 'A';
            int cipherChar = (plainChar + keyChar) % 26;
            ciphertext += char(cipherChar + 'A');
            keyIndex++;
        }
        else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

string vigenere_decrypt(string ciphertext, string key) {
    string plaintext = "";
    int keyIndex = 0;
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            c = toupper(c);
            int keyChar = key[keyIndex % key.length()] - 'A';
            int cipherChar = c - 'A';
            int plainChar = (cipherChar - keyChar + 26) % 26;
            plaintext += char(plainChar + 'A');
            keyIndex++;
        }
        else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    string plaintext = "HELLO WORLD";
    string key = "SECRET";
    string ciphertext = vigenere_encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;
    string decryptedText = vigenere_decrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;
    return 0;
}
