#include <iostream>

#include <string>


int main() {
    std::string s = "word";
    std::cout << "String value is " << s << std::endl;

    //std::cin >> s; // until spatial symbol
    std::getline(std::cin, s); // until \n
    std::cout << "New string value is " << s << std::endl;
    std::cout << "By index 5 there is letter " << s[5] << std::endl;

    std::cout << (s < "word") << std::endl;
}