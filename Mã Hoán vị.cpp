#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string transpositionEncrypt(const std::string& text, const std::string& key) {
    int cols = key.length();
    int rows = (text.length() + cols - 1) / cols;
    std::vector<std::string> grid(rows, std::string(cols, 'X'));  // Padding X
    int idx = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (idx < text.length()) grid[r][c] = text[idx++];
        }
    }
    std::string result = "";
    std::vector<int> order(cols);
    for (int i = 0; i < cols; i++) order[i] = key[i] - '0' - 1;  // 1-based to 0-based
    std::sort(order.begin(), order.end());  // Không, cần theo thứ tự khóa
    // Thực ra cần map khóa đến thứ tự
    std::vector<std::pair<int, int>> keyOrder;
    for (int i = 0; i < cols; i++) keyOrder.push_back({key[i] - '0', i});
    std::sort(keyOrder.begin(), keyOrder.end());
    for (auto& p : keyOrder) {
        int col = p.second;
        for (int r = 0; r < rows; r++) result += grid[r][col];
    }
    return result;
}

std::string transpositionDecrypt(const std::string& text, const std::string& key) {
    int cols = key.length();
    int rows = text.length() / cols;
    std::vector<std::string> grid(rows, std::string(cols, ' '));
    std::vector<std::pair<int, int>> keyOrder;
    for (int i = 0; i < cols; i++) keyOrder.push_back({key[i] - '0', i});
    std::sort(keyOrder.begin(), keyOrder.end());
    int idx = 0;
    for (auto& p : keyOrder) {
        int col = p.second;
        for (int r = 0; r < rows; r++) grid[r][col] = text[idx++];
    }
    std::string result = "";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] != 'X') result += grid[r][c];
        }
    }
    return result;
}

int main() {
    std::string text = "HELLOWORLD";
    std::string key = "3142";
    std::string encrypted = transpositionEncrypt(text, key);
    std::string decrypted = transpositionDecrypt(encrypted, key);
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;
}