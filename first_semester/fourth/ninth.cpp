#include <iostream>

int main() {
    int matrix[10][10];
    int n;
    std::cin >> n;
    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < n; j++) {
            std::cout << matrix[j][i] << ' ';
        }
        std::cout << std::endl;
    }

}

