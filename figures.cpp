
class Class {
    Class(int new_field, int new_const_field):
        field(new_field),
        const_field(new_const_field) {} // using initialization list

private:
    int field;
    const int const_field; // can be initialized only using initialization list
};

#include <cmath>

class Figure { // abstract base class
public:
    virtual double square() = 0; // pure virtual
};

class BaseCircle: public Figure { // abstract base class too as square is 
                                  // still pure virtual

};

class Circle: public BaseCircle {
public:
    Circle(double r): r(r) {}

    virtual double square() override {
        return std::acos(-1) * r * r;
    }

private:
    double r;
};

#include <iostream>

int main() {
    Circle c(2);
    std::cout << c.square() << std::endl;

    Figure* fp = &c;
    std::cout << fp->square() << std::endl;

    //Figure f; // abstract base class
    // BaseCircle bc; // abstract base class too
}
