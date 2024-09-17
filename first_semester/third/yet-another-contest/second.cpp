#include <iostream>

int main() {
    unsigned n;
    std::cin >> n;
    unsigned mask = 1u << 31;

    for (auto i = 0u; i < 32u; i++) {
        if ((n & mask) == 0) std::cout << 0;
        else std::cout << 1;
        mask = mask >> 1;

        if (!((i + 1u) % 4)) std::cout << ' ';
        if (!((i + 1u) % 8)) std::cout << ' ';
    }
}

