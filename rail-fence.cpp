#include <iostream>
#include <string>

using namespace std;

string encryptRailFence(string plaintext, int key) {
    string ciphertext;
    int len = plaintext.length();
    char rail[key][len];
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < len; j++) {
            rail[i][j] = '\n';
        }
    }
    bool dir_down = false;
    int row = 0, col = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0 || row == key-1) {
            dir_down = !dir_down;
        }
        rail[row][col++] = plaintext[i];
        dir_down ? row++ : row--;
    }
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] != '\n') {
                ciphertext.push_back(rail[i][j]);
            }
        }
    }
    return ciphertext;
}

string decryptRailFence(string ciphertext, int key) {
    string plaintext;
    int len = ciphertext.length();
    char rail[key][len];
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < len; j++) {
            rail[i][j] = '\n';
        }
    }
    bool dir_down;
    int row = 0, col = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0) {
            dir_down = true;
        }
        if (row == key-1) {
            dir_down = false;
        }
        rail[row][col++] = '*';
        dir_down ? row++ : row--;
    }
    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] == '*' && index < len) {
                rail[i][j] = ciphertext[index++];
            }
        }
    }
    row = 0, col = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0) {
            dir_down = true;
        }
        if (row == key-1) {
            dir_down = false;
        }
        if (rail[row][col] != '\n') {
            plaintext.push_back(rail[row][col++]);
        }
        dir_down ? row++ : row--;
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext, decryptedtext;
    int key;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    cout << "Enter the key: ";
    cin >> key;
    ciphertext = encryptRailFence(plaintext, key);
    cout << "Encrypted text: " << ciphertext << endl;
    decryptedtext = decryptRailFence(ciphertext, key);
    cout << "Decrypted text: " << decryptedtext << endl;
    return 0;
}
