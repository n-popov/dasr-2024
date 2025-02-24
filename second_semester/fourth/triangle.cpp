
#include <cmath>

class Point
{
protected:
    int x;
    int y;

public:
    Point(int x, int y): x(x), y(y) {
    }

    Point operator+(const Point& a) const {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(const Point& a) const {
        return Point(x - a.x, y - a.y);
    }

    double dist() const {
        return sqrt(x * x + y * y);
    }
};
//Логически точка представлена радиус-вектором, поэтому точки можно складывать и вычитать - соответственные операторы для них уже определены. Также у точки есть метод dist() - получить модуль её радиус-вектора.

//Напишите класс треугольника со следующим прототипом:

class Triangle
{
public:
    // Создать треугольник из трёх точек
    Triangle(const Point& a, const Point& b, const Point& c):
        ab((b - a).dist()),
        bc((c - b).dist()),
        ca((a - c).dist()) {}

    // Посчитать и вернуть периметр треугольника
    double perimeter() const {
        return ab + bc + ca;
    }
private:
    double ab, bc, ca;
};
// Для базового тестирования можете использовать следующий пример:

#include <iostream>
using std::cout, std::endl;

int main()
{
    Point a(0, 0), b(0, 5), c(5, 0);
    Triangle t(a, b, c);
    cout << t.perimeter() << endl;
    return 0;
}
