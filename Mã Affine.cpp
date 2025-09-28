#include <iostream>
#include <string>

// Tìm nghịch đảo modulo
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;  // Không tồn tại
}

std::string affineEncrypt(const std::string& text, int a, int b) {
    std::string result = "";
    for (char c : text) {
        if (isupper(c)) {
            result += char(((a * (c - 'A') + b) % 26) + 'A');
        } else if (islower(c)) {
            result += char(((a * (c - 'a') + b) % 26) + 'a');
        } else {
            result += c;
        }
    }
    return result;
}

std::string affineDecrypt(const std::string& text, int a, int b) {
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) return "Khóa không hợp lệ";
    std::string result = "";
    for (char c : text) {
        if (isupper(c)) {
            result += char((a_inv * ((c - 'A' - b + 26) % 26)) % 26 + 'A');
        } else if (islower(c)) {
            result += char((a_inv * ((c - 'a' - b + 26) % 26)) % 26 + 'a');
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string text = "HELLO";
    int a = 5, b = 8;
    std::string encrypted = affineEncrypt(text, a, b);  // RCLLA
    std::string decrypted = affineDecrypt(encrypted, a, b);  // HELLO
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}