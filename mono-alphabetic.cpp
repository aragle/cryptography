#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, string key) {
    string ciphertext = "";
    for (char c : message) {
        if (isalpha(c)) {
            char newChar = key[tolower(c) - 'a'];
            if (isupper(c)) {
                newChar = toupper(newChar);
            }
            ciphertext += newChar;
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string message = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char newChar = 'a' + key.find(tolower(c));
            if (isupper(c)) {
                newChar = toupper(newChar);
            }
            message += newChar;
        } else {
            message += c;
        }
    }
    return message;
}

int main() {
    string message = "hello world";
    string key = "qwertyuiopasdfghjklzxcvbnm";
    string ciphertext = encrypt(message, key);
    cout << "Ciphertext: " << ciphertext << endl;
    string decryptedMessage = decrypt(ciphertext, key);
    cout << "Decrypted message: " << decryptedMessage << endl;
    return 0;
}
