
#include <iostream>
#include <functional>

void sort(int * arr, int n, std::function<bool(int, int)> less) {
    for (auto i = 1; i < n; i++) {
        for (auto j = i; j > 0 && less(arr[j], arr[j - 1]); j--) {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    int numbers[1000];
    for (auto i = 0; i < n; i++)
        std::cin >> numbers[i];

    sort(numbers, n, [](int a, int b) {
            if (a * b < 0) {
                return (a > 0);
            } else {
                return std::abs(a) < std::abs(b);
            }

         });

    for (auto i = 0; i < n; i++)
        std::cout << numbers[i] << ' ';

}

