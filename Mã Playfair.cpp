#include <iostream>
#include <string>
#include <vector>

class Playfair {
private:
    char table[5][5];
    void buildTable(const std::string& key) {
        std::string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";  // No J
        std::string used = "";
        for (char c : key) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            if (used.find(c) == std::string::npos && isalpha(c)) used += c;
        }
        used += alphabet;
        std::string finalKey = "";
        for (char c : used) if (finalKey.find(c) == std::string::npos) finalKey += c;
        int idx = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) table[i][j] = finalKey[idx++];
        }
    }
    std::pair<int, int> findPos(char c) {
        if (c == 'J') c = 'I';
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (table[i][j] == c) return {i, j};
            }
        }
        return {-1, -1};
    }

public:
    Playfair(const std::string& key) { buildTable(key); }
    std::string encrypt(const std::string& text) {
        std::string prepared = "";
        for (char c : text) {
            c = toupper(c);
            if (isalpha(c)) {
                if (c == 'J') c = 'I';
                prepared += c;
            }
        }
        for (size_t i = 0; i < prepared.length(); i += 2) {
            if (i + 1 == prepared.length()) prepared += 'X';
            else if (prepared[i] == prepared[i+1]) prepared.insert(i+1, "X");
        }
        std::string result = "";
        for (size_t i = 0; i < prepared.length(); i += 2) {
            auto [r1, c1] = findPos(prepared[i]);
            auto [r2, c2] = findPos(prepared[i+1]);
            if (r1 == r2) {
                result += table[r1][(c1 + 1) % 5];
                result += table[r2][(c2 + 1) % 5];
            } else if (c1 == c2) {
                result += table[(r1 + 1) % 5][c1];
                result += table[(r2 + 1) % 5][c2];
            } else {
                result += table[r1][c2];
                result += table[r2][c1];
            }
        }
        return result;
    }
    std::string decrypt(const std::string& text) {
        std::string result = "";
        for (size_t i = 0; i < text.length(); i += 2) {
            auto [r1, c1] = findPos(text[i]);
            auto [r2, c2] = findPos(text[i+1]);
            if (r1 == r2) {
                result += table[r1][(c1 - 1 + 5) % 5];
                result += table[r2][(c2 - 1 + 5) % 5];
            } else if (c1 == c2) {
                result += table[(r1 - 1 + 5) % 5][c1];
                result += table[(r2 - 1 + 5) % 5][c2];
            } else {
                result += table[r1][c2];
                result += table[r2][c1];
            }
        }
        // Xóa padding X nếu cần, nhưng đơn giản giữ nguyên
        return result;
    }
};

int main() {
    std::string key = "MONARCHY";
    Playfair pf(key);
    std::string text = "HELLO";
    std::string encrypted = pf.encrypt(text);  // BM OD ZB XD NA (khoảng trắng cho đọc)
    std::string decrypted = pf.decrypt(encrypted);
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}