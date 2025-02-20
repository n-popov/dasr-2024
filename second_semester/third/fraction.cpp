#include <iostream>

class Fraction {
public:
    Fraction(int num, int den): num(num), den(den) {}

    Fraction(): num(0), den(1) {}

    Fraction operator+(Fraction other) {
        return Fraction(this->num * other.den + this->den * other.num,
                    this->den * other.den);
    }

    Fraction operator-(Fraction other) {
        return Fraction(num * other.den - den * other.num,
                    den * other.den);
    }

    Fraction operator*(Fraction other) {
        return Fraction(num * other.num,
                    den * other.den);
    }

    Fraction operator++() {
        num += den;
        return *this;
    }

    Fraction operator++(int) {
        Fraction old = *this;
        num += den;
        return old;
    }

    friend std::ostream& operator<<(std::ostream&, Fraction);
    friend std::istream& operator>>(std::istream&, Fraction&);

private:
    int num, den;
    // unsigned den;
};

std::ostream& operator<<(std::ostream& out, Fraction f) {
    return out << f.num << '/' << f.den;
}

std::istream& operator>>(std::istream& in, Fraction& f) {
    char trash;
    in >> f.num >> trash >> f.den;
    return in;
}

int main() {
    Fraction fl, fr;

    std::cin >> fl >> fr;


    auto sum = fl + fr;
    sum = fl.operator+(fr);

    std::cout << sum << '\n'
        << (fl - fr) << '\n'
        << (fl * fr) << std::endl;

    std::cout << ++fl << ' ' << fl++ << ' ' << fl << std::endl;


}
