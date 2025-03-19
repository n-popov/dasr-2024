#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

class ZeroDenominatorException: public std::exception {
public:
    ZeroDenominatorException(const std::string& info): info(info) {}

    virtual const char* what() const noexcept {
        return info.c_str();
    }

private:
    std::string info;
};

class Fraction{
public:
    Fraction(int num, int den): num(num), den(den) {
        if (den == 0) {
            throw ZeroDenominatorException("Denominator is zero");
        }
    }

    Fraction(): Fraction(0, 1) {};

    friend std::ostream& operator<<(std::ostream& os, Fraction f);
private:
    int num, den;
};

std::ostream& operator<<(std::ostream& os, Fraction f) {
    return os << f.num << '/' << f.den;
}

int main() {
    try {
        Fraction* fractions = new Fraction[5];
        std::vector<Fraction> fractions_vec;

        int n;
        std::cout << "input amount of fractions" << std::endl;
        std::cin >> n;

        int num, den;
        char trash;
        for (auto i = 0; i < n; i++) {
            std::cin >> num >> trash >> den;
            Fraction f(num, den);
            fractions_vec.push_back(f);
        }
        int idx;
        std::cout << "input index of a fraction" << std::endl;
        std::cin >> idx;
        std::cout << fractions_vec.at(idx) << std::endl;
        delete[] fractions;
        std::cout << "fractions freed" << std::endl;
    } catch (const ZeroDenominatorException& z_exc) {
        std::cout << "Bad denominator: " << z_exc.what() << std::endl;
    } catch (const std::out_of_range& r_exc) {
        std::cout << "Bad index: " << r_exc.what() << std::endl;
    } catch (const std::exception& exc) {
        std::cout << "Unknown exception: " << exc.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown thing thrown" << std::endl;
    }
}