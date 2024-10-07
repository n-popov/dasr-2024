#include <iostream>

int main () {
    int n;
    std::cin >> n;

    if (n <= 1) {
        std::cout << 0 << std::endl;
    }

    int prev, prev_prev;
    std::cin >> prev_prev >> prev;

    int current_price;
    int current;
    for (auto i = 2; i < n; i++) {
        std::cin >> current_price;
        current = std::min(prev, prev_prev) + current_price;
        prev_prev = prev;
        prev = current;
    }

    std::cout << std::min(prev, prev_prev) << std::endl;



}

