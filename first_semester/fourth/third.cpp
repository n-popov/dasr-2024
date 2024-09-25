#include <iostream>

void sort(int * arr, int n) {
    for (auto i = 1; i < n; i++) {
        for (auto j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
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

    sort(numbers, n);

    int m;
    std::cin >> m;

    for (auto i = n - m; i < n; i++)
        std::cout << numbers[i] << ' ';





}

