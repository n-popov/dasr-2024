#include <iostream>

int main() {
    unsigned n;
    std::cin >> n;
    unsigned mask = 1u << 31;
    auto counter = 0u;

    for (auto i = 0u; i < 32u; i++) {
        if (n & mask) std::cout << 1;
        else counter += 1;

        mask = mask >> 1;
    }
    for (auto i = 0u; i < counter; i++) std::cout << 0;



}

