
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {
    std::vector<int> seq;

    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(seq));

    std::copy(seq.begin(), seq.end(),
        std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::vector<int> squares;
    //squares.resize(seq.size());

    std::transform(seq.begin(), seq.end(),
        std::back_inserter(squares),
        [](auto elem){return elem * elem;});

    for (auto item: squares) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    std::set<int, std::greater<int>> sorted_ints;
    std::copy(seq.begin(), seq.end(),
        std::inserter(sorted_ints, sorted_ints.begin()));

    for (auto item: sorted_ints) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}
