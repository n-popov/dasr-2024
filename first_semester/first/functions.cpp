#include <iostream>
#include <functional>
#include <array>
#include <algorithm>


// Функция max принимает функцию третьим аргументом
// тип аргумента std::function<bool(int, int)> означает, что это функция, которая 
// возвращает bool и принимает два аргумента с типами int и int
int max(int a, int b, std::function<bool(int, int)> is_less) {
    if (is_less(a, b)) return b;
    return a;
}

// Функция возвращает true, если первый аргумент меньше по модулю, чем второй
bool less_by_absolute(int x, int y) {
    return std::abs(x) < std::abs(y);
}

int main() {
    int m = 4, n = -5;
    
    std::cout << "Max is " << std::max(m, n, less_by_absolute) << std::endl; // -5
    std::cout << "Min is " << std::min(m, n, less_by_absolute) << std::endl; // 4

    std::cout << "Our Max is " << max(m, n, less_by_absolute) << std::endl; // -5

    // Чтобы не писать функцию отдельно, можно написать её прямо на месте
    // это называется лямбда-функция
    std::cout << "Max is " << std::max(m, n, [](int a, int b){return std::abs(a) < std::abs(b);}) << std::endl;
    
    // Лямбду можно сохранить в переменную
    std::function<bool(int, int)> bigger = [](int a, int b){return b < a;};
    
    // Для разнообразия сделаем не меньше, а больше, но уже не по модулю
    std::cout << "Reverse max (min) is " << std::max(m, n, bigger) << std::endl; // -5

    // Зачем так сложно? можно было бы написать свой max по модулю и не париться
    // Это позволяет унифицировать сложные алгоритмы. Например, давайте отсортируем по модулю,
    // используя стандартный алгоритм сортировки

    std::array<int, 5> array{-5, 3, 4, -2, -1};
    std::sort(array.begin(), array.end(), less_by_absolute);
    for (auto i = 0u; i < 5u; i++) std::cout << array[i] << ' '; // -1 -2 3 4 -5
    std::cout << std::endl;
    
}
