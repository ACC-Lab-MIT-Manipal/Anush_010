#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a message using the Caesar cipher
string encrypt(string message, int shift) {
    string encrypted = "";

    for (char c : message) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            encrypted += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            encrypted += c;
        }
    }

    return encrypted;
}

// Function to decrypt a Caesar cipher encrypted message
string decrypt(string message, int shift) {
    return encrypt(message, 26 - shift);
}

int main() {
    string message;
    int shift;

    cout << "Enter a message: ";
    getline(cin, message);

    cout << "Enter the shift value: ";
    cin >> shift;

    // Encrypt the message
    string encrypted = encrypt(message, shift);
    cout << "Encrypted message: " << encrypted << endl;

    // Decrypt the message
    string decrypted = decrypt(encrypted, shift);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
