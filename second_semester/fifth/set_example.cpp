#include <set>
#include <iostream>

int main() {
    std::set<int> s = {1, 7, 7, 1, 7, 4};

    int x;
    std::cin >> x;
    std::cout << "Set contains x? " << s.count(x) << std::endl;

    int y;
    std::cin >> y;
    s.insert(y);

    for (auto item: s) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}
