// Прототип класса:
#include <iostream>
class Rational {
public:
    // Конструктор дроби, здесь a - числитель, b - знаменатель
    Rational(int a, int b): n(a), d(b) {}

    // Реализуйте операторы:
    // - сложения двух дробей
    Rational operator+(Rational other) {
        return Rational(d * other.n + n * other.d, d * other.d);
    }
    // - вычитания двух дробей
    friend Rational operator-(Rational l, Rational r);
    // - умножения двух дробей
    Rational operator*(Rational other) {
        return {n * other.n, d * other.d};
    }
    // - деления двух дробей
    auto operator/(Rational other) {
        return Rational(n * other.d, d * other.n);
    }
    // - умножения дроби на целое число (должно работать при любом порядке операндов)
    Rational operator*(int num) {
        return Rational(n * num, d);
    }

    friend Rational operator*(int num, Rational r);
    friend std::ostream& operator<<(std::ostream& out, Rational r);

private:
    int d, n;
};

Rational operator-(Rational l, Rational r) {
    return Rational(l.n * r.d - l.d * r.n, l.d * r.d);
}

Rational operator*(int num, Rational r) {
    return r * num;
}

std::ostream& operator<<(std::ostream& out, Rational r) {
    return out << r.n << '/' << r.d;
}



using std::cout, std::endl;

int main()
{
    Rational a(1, 2);
    Rational b(2, 3);

    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << b * 4 << endl;

    return 0;
}