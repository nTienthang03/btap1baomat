#include <iostream>
#include <string>

std::string caesarEncrypt(const std::string& text, int k) {
    std::string result = "";
    k = k % 26;
    for (char c : text) {
        if (isupper(c)) {
            result += char((c - 'A' + k) % 26 + 'A');
        } else if (islower(c)) {    
            result += char((c - 'a' + k) % 26 + 'a');
        } else {
            result += c;
        }
    }
    return result;
}

std::string caesarDecrypt(const std::string& text, int k) {
    return caesarEncrypt(text, 26 - k);  // Dịch ngược
}

int main() {
    std::string text = "HELLO";
    int k = 3;
    std::string encrypted = caesarEncrypt(text, k);  // KHOOR
    std::string decrypted = caesarDecrypt(encrypted, k);  // HELLO
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}