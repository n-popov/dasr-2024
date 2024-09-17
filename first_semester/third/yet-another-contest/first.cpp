#include <iostream>

int main() {
    unsigned n;
    std::cin >> n;
    unsigned mask = 1u << 31;

    for (auto i = 0u; i < 32; i++) {
        if ((n & mask) == 0) std::cout << 0;
        else std::cout << 1;
        mask = mask >> 1;
    }
}

