#include <string>
#include <type_traits>

// SFINAE
// Substitution Failure Is Not An Error


/*
template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, T> mul3(T value) {
    return value * 3;
}*/

template <typename T,
    std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>
T mul3(T value) {
    return value * 3;
}

int main() {
    mul3(1);
    mul3(4.2);

    std::string s;
    mul3(s);
}