#include <iostream>

template <typename T>
class SmartPtr {
public:
    template <typename... Types>
    SmartPtr(Types... args) {
        ptr = new T(args...);
    }

    T& operator*() {
        return *ptr;
    }

    ~SmartPtr() {
        delete ptr;
    }
private:
    T* ptr;
};

struct Point{
    Point(): x(0), y(0) {};

    Point(double x, double y):
        x(x), y(y) {}

    double x, y;
};

std::ostream& operator<<(std::ostream& os, Point p) {
    return os << p.x << ", " << p.y;
}

int main() {
    Point* ptr = new Point();
    // ... work with ptr
    // ptr->x = 1;
    // ptr->y = 2;
    delete ptr;

    SmartPtr<Point> s_ptr(2.5, 3.3);
    std::cout << *s_ptr << std::endl;
    // ... work with s_ptr
    // s_ptr.get_value().x = 1;
}