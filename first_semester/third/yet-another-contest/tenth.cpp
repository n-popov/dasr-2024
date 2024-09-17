
#include <iostream>

int main() {
    int N, prev, current;
    std::cin >> N;
    auto result = 0u, current_same = 1u;

    if (N < 2) {
        std::cout << N << std::endl;
        return 0;
    }

    std::cin >> prev;
    for (auto i = 1; i < N; i++) {
        std::cin >> current;
        if (current == prev) current_same++;
        else {
            result = std::max(result, current_same);
            current_same = 1u;
        }
        prev = current;
    }
    std::cout << std::max(result, current_same) << std::endl;
}

