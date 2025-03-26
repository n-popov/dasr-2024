#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (auto i = 0u; i + 1u < v.size(); i++) {
        os << v[i] << ", ";
    }
    if (v.size()) {
        os << v[v.size() - 1u];
    }
    return os << "]";
}

void print() {
    std::cout << std::endl;
}

template <typename T, typename... Types>
void print(T first, Types... args) {
    std::cout << first << ' ';
    print(args...);
}

template <typename T>
const T& _print2_wrapper(const T& value, char delim) {
    std::cout << delim;
    return value;
}

template <typename... Types>
void print2(Types... args) {
    (std::cout << ... << _print2_wrapper(args, ' '));

    /*
    std::cout << _print2_wrapper(arg1, ' ')
              << _print2_wrapper(arg2, ' ')
              ...
              << _print2_wrapper(argn, ' ');
    */
}

int main() {
    print();

    std::vector<int> arr = {1, 3, 5};
    std::vector<bool> empty;
    std::vector<std::vector<double>> m;
    m.push_back({1.5, 2.4});
    m.push_back({3.3, 0.5});
    print(1, "abc", empty, false, '=', arr, m);
    print2(1, "xyz", arr);
}