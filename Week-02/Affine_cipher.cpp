#include <iostream>
#include <string>

using namespace std;

// Function to compute the modular multiplicative inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // If no modular inverse exists
}

// Function to encrypt plaintext using the Affine Cipher
string affineEncrypt(string plaintext, int a, int b) {
    string ciphertext = "";
    int m = 26; // The size of the English alphabet

    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char encryptedChar;
            if (islower(ch)) {
                encryptedChar = 'a' + ((a * (ch - 'a') + b) % m);
            } else {
                encryptedChar = 'A' + ((a * (ch - 'A') + b) % m);
            }
            ciphertext += encryptedChar;
        } else {
            ciphertext += ch; // Preserve non-alphabet characters
        }
    }

    return ciphertext;
}

// Function to decrypt ciphertext using the Affine Cipher
string affineDecrypt(string ciphertext, int a, int b) {
    string plaintext = "";
    int m = 26; // The size of the English alphabet
    int aInverse = modInverse(a, m);

    if (aInverse == -1) {
        cerr << "Invalid 'a' value. Modular inverse does not exist." << endl;
        return plaintext;
    }

    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char decryptedChar;
            if (islower(ch)) {
                decryptedChar = 'a' + (aInverse * (ch - 'a' - b + m)) % m;
            } else {
                decryptedChar = 'A' + (aInverse * (ch - 'A' - b + m)) % m;
            }
            plaintext += decryptedChar;
        } else {
            plaintext += ch; // Preserve non-alphabet characters
        }
    }

    return plaintext;
}

int main() {
    string plaintext, ciphertext, decryptedText;
    int a, b;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the values of 'a' and 'b' for encryption (e.g., 5 8): ";
    cin >> a >> b;

    // Encryption
    ciphertext = affineEncrypt(plaintext, a, b);
    cout << "Encrypted ciphertext: " << ciphertext << endl;

    // Decryption
    decryptedText = affineDecrypt(ciphertext, a, b);
    cout << "Decrypted plaintext: " << decryptedText << endl;

    return 0;
}
