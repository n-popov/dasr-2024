#include <iostream>

int main() {
    int x0, y0;
    std::cin >> x0 >> y0;
    int max_len = std::abs(x0 - y0);

    int N;
    std::cin >> N;

    int dx, dy;
    for (auto i = 0; i < N; i++) {
        std::cin >> dx >> dy;
        x0 += dx;
        y0 += dy;

        max_len = std::max(max_len, std::abs(x0 - y0));
    }
    std::cout << max_len << std::endl;





}

