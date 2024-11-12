#include <iostream>

template <typename T, typename K>
auto max(T a, K b) {
    if (a > b) return a;
    return b;
}

template <typename T>
T median(T a, T b, T c) {
    if (a >= b) std::swap(a, b);
    if (b >= c) std::swap(b, c);
    if (a >= b) std::swap(a, b);

    return b;
}

int main() {
    int x, y, z;
    std::cin >> x >> y >> z;

    std::cout << "Median is: " <<
        median(x, y, z) << std::endl;

    char k, l, m;
    std::cin >> k >> l >> m;

    std::cout << "Median of chars is: " <<
        median(k, l, m) << std::endl;

    // compiler cannot deduce type T
    std::cout << median<char>('a', 95, 'h') << std::endl;
}
