#include <iostream>

int main() {
    int numbers[1000];

    int n;
    std::cin >> n;

    for (auto i = 0; i < n;) {
        std::cin >> numbers[i++];
    }

    for (auto i = n - 1; i >= 0;) {
        std::cout << numbers[i--] << ' ';
    }
}

