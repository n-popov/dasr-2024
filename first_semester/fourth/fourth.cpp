#include <iostream>

int min_idx(int* arr, int n) {
    int result = 0;
    for (auto i = 1; i < n; i++) {
        if (arr[i] <= arr[result]) result = i;
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;

    int numbers[1000];
    for (auto i = 0; i < n; i++)
        std::cin >> numbers[i];

    int m;
    std::cin >> m;
    int result[1000];

    for (auto i = 0; i < m; i++) result[i] = numbers[i];

    for (auto i = m; i < n; i++) {
        auto current_element = numbers[i];
        auto i_min = min_idx(result, m);
        if (result[i_min] < current_element) {
            for (auto j = i_min; j + 1 < m; j++) {
                result[j] = result[j + 1];
            }
            result[m - 1] = current_element;
        }
    }

    for (auto i = 0; i < m; i++) {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;
}


