#include <iostream>

int main() {
    int sum;
    std::cin >> sum;

    std::cout << sum / 10 << ' ';
    sum %= 10;

    std::cout << sum / 5 << ' ';
    sum %= 5;

    std::cout << sum << std::endl;
}

