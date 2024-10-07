#include <iostream>

int main() {
    int n;
    std::cin >> n;

    bool positions[100] = {false};

    for (auto s = n - 1; s >= 0; s--) {
        if (s + 2 >= n || s + 5 >= n || 2 * s >= n) {
            positions[s] = false;
        } else {
            positions[s] = (positions[s + 2] == false &&
             positions[s + 5] == false &&
             positions[2 * s] == false);
        }
    }

    for (auto s = 1; s < n; s++) {
        if (positions[s] == true) {
            std::cout << s << std::endl;
            break;
        }
    }
}

