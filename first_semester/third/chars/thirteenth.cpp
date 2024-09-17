#include <cctype>

bool is_valid(char x) {
    return std::isdigit(x) || ('A' <= x && x <= 'F');
}

int to_decimal(char x) {
    if (std::isdigit(x)) return x - '0';
    return x - 'A' + 10;
}

unsigned long long get_a_hexadecimal() {
    auto result = 0llu;
    for (char c;;) {
        std::cin.get(c);

        if (c == ' ' || c == '\n') {
            break;
        }

        if (!is_valid(c)) return 0llu;

        result = 16 * result + to_decimal(c);
    }
    return result;
}
