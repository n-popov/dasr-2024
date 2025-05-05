#include <chrono>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "timer.hpp"
#include "class.hpp"
#include "helpers.hpp"

int main() {

    std::vector<int> ints{1, 3, 5, 4, 2};
    for (auto i: ints) {std::cout << i << ' ';}
    std::cout << std::endl;

    std::vector<std::string> strings{"abc", "def"};
    for (const auto& s: strings) {std::cout << s << ' ';}
    std::cout << std::endl;

    std::string s;
    // read from file
    s.resize(1'000'000'000);

    {
        Timer t(std::cout);

        Process(std::move(s));
    }

    Class c("abcd");
    Class other = std::move(c);

    std::cout << c.get() << ' ' << other.get() << std::endl;
}
