#include <iostream>
#include <string>

std::string vigenereEncrypt(const std::string& text, const std::string& key) {
    std::string result = "";
    int keyLen = key.length();
    int j = 0;
    for (char c : text) {
        if (isupper(c)) {
            char k = toupper(key[j % keyLen]);
            result += char((c - 'A' + k - 'A') % 26 + 'A');
            j++;
        } else if (islower(c)) {
            char k = tolower(key[j % keyLen]);
            result += char((c - 'a' + k - 'a') % 26 + 'a');
            j++;
        } else {
            result += c;
        }
    }
    return result;
}

std::string vigenereDecrypt(const std::string& text, const std::string& key) {
    std::string result = "";
    int keyLen = key.length();
    int j = 0;
    for (char c : text) {
        if (isupper(c)) {
            char k = toupper(key[j % keyLen]);
            result += char((c - 'A' - (k - 'A') + 26) % 26 + 'A');
            j++;
        } else if (islower(c)) {
            char k = tolower(key[j % keyLen]);
            result += char((c - 'a' - (k - 'a') + 26) % 26 + 'a');
            j++;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string text = "HELLO";
    std::string key = "KEY";
    std::string encrypted = vigenereEncrypt(text, key);  // RIJVS
    std::string decrypted = vigenereDecrypt(encrypted, key);  // HELLO
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}