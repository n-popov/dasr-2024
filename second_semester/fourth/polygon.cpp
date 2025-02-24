
#include <cmath>
#include <iostream>

class Point2D
{
protected:
    double _x;
    double _y;

public:
    // Конструктор точки с заданными координатами
    Point2D(double x, double y): _x(x), _y(y) {
    }

    // Получить координату X точки
    double x() const {
        return _x;
    }

    // Получить координату Y точки
    double y() const {
        return _y;
    }
};
//Напишите класс, описывающий выпуклый многоугольник, со следующим прототипом:

#include <vector>

class Polygone
{
public:
    // Конструктор, создаёт полигон из набора точек.
    // Точки передаются в порядке обхода полигона по контуру.
    Polygone(const std::vector<Point2D>& points):
        vertices(points) {}

    // Деструктор, если нужен

    // Возвращает площадь полигона
    double area() const {
        auto retval = 0.;
        for (auto i = 1u; i + 1u < size(); i++) {
            std::cout << "Iteration " << i << std::endl;
            retval += square_triangle(
                vertices[0], vertices[i], vertices[i + 1]);
        }
        return retval;
    }

    // Возвращает количество вершин полигона
    unsigned int size() const {
        return vertices.size();
    }

    // Возвращает N-ую вершину полигона
    // (вершины нумеруются в том же порядке, в котором были переданы)
    Point2D vertex(unsigned int N) const {
        return vertices[N];
    }

private:
    double side(Point2D a, Point2D b) const {
        return std::sqrt(
            std::pow((b.x() - a.x()), 2) +
            std::pow((b.y() - a.y()), 2)
        );
    }

    double square_triangle(Point2D a, Point2D b, Point2D c) const {
        double ab = side(a, b);
        double bc = side(b, c);
        double ca = side(c, a);

        auto p = (ab + bc + ca) / 2;

        return std::sqrt(p * (p - ab) * (p - bc) * (p - ca));
    }

    std::vector<Point2D> vertices;
};



#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<Point2D> points = {{-1.0, -1.0}, {-1.0, 1.0}, {1.0, 1.0}, {1.0, -1.0}};
    std::vector<Point2D> points;
    Polygone p(points);
    cout << "Points:" << endl;
    for(unsigned int i = 0; i < p.size(); i++) {
        cout << p.vertex(i).x() << " " << p.vertex(i).y() << endl;
    }
    std::cout << "Size: " << p.size() << std::endl;
    cout << "Area: " << p.area() << endl;
    return 0;
}
