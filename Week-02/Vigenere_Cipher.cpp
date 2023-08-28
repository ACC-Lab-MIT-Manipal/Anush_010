#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to perform Vigenère encryption
string vigenereEncrypt(const string &plaintext, const string &key) {
    string ciphertext = "";
    int keyLength = key.length();

    for (int i = 0, j = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[j];

        if (isalpha(plainChar)) {
            char base = islower(plainChar) ? 'a' : 'A';
            char encryptedChar = ((plainChar - base + keyChar - 'A') % 26) + base;
            ciphertext += encryptedChar;
            j = (j + 1) % keyLength;
        } else {
            ciphertext += plainChar; // Preserve non-alphabet characters
        }
    }

    return ciphertext;
}

// Function to perform Vigenère decryption
string vigenereDecrypt(const string &ciphertext, const string &key) {
    string plaintext = "";
    int keyLength = key.length();

    for (int i = 0, j = 0; i < ciphertext.length(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = key[j];

        if (isalpha(cipherChar)) {
            char base = islower(cipherChar) ? 'a' : 'A';
            char decryptedChar = ((cipherChar - base - keyChar + 'A' + 26) % 26) + base;
            plaintext += decryptedChar;
            j = (j + 1) % keyLength;
        } else {
            plaintext += cipherChar; // Preserve non-alphabet characters
        }
    }

    return plaintext;
}

int main() {
    string plaintext, key, ciphertext, decryptedText;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    cin >> key;

    // Encryption
    ciphertext = vigenereEncrypt(plaintext, key);
    cout << "Encrypted ciphertext: " << ciphertext << endl;

    // Decryption
    decryptedText = vigenereDecrypt(ciphertext, key);
    cout << "Decrypted plaintext: " << decryptedText << endl;

    return 0;
}
