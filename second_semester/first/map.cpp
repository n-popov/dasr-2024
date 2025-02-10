
#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<char, int> letters_to_nums;

    int N;
    std::cin >> N;

    for (auto i = 0u; i < N; i++) {
        char c;
        std::cin >> c;
        letters_to_nums[c]++;
    }

    std::map<int, std::vector<char>> nums_to_letters;

    /* C++17 
    // --std=c++1z
    for (auto [letter, amount]: letters_to_nums) {
        nums_to_letters[amount].push_back(letter);
    }
    */

    for (auto pair: letters_to_nums) {
        nums_to_letters[pair.second].push_back(pair.first);
    }

    /* C++17 
    // --std=c++1z
    for (auto [amount, letters]: nums_to_letters) {
        for (auto letter: letters) {
            std::cout << letter << ": " << amount << std::endl;
        }
    }
    */

    for (auto pair: nums_to_letters) {
        for (auto letter: pair.second) {
            std::cout << letter << ": " << pair.first << std::endl;
        }
    }


}
