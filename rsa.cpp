#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int modexp(int base, int exponent, int modulus){
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

void generate_keys(int p, int q, int& e, int& d, int& n){
    n = p * q;

    int totient = (p - 1) * (q - 1);

    for (e = 2; e < totient; e++) {
        if (gcd(e, totient) == 1)
            break;
    }

    for (d = 1; d < totient; d++) {
        if ((d * e) % totient == 1)
            break;
    }
}

int encrypt(int message, int e, int n){
    return modexp(message, e, n);
}

int decrypt(int message, int d, int n){
    return modexp(message, d, n);
}

int main(){
    
    int p = 7, q = 11;
    int e, d, n;
    generate_keys(p, q, e, d, n);
    int message;
    
    cout << "Enter your message: ";
    cin >> message;

    int ciphertext = encrypt(message, e, n);
    cout << "Encrypted message: " << ciphertext << endl;

    int plaintext = decrypt(ciphertext, d, n);
    cout << "Decrypted message: " << plaintext << endl;

    return 0;
}