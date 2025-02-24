#include <iostream>

class Class {
public:
    void print() const {
        std::cout << "Class with field: " << field << std::endl;
    }

    const int getField() const {
        return field;
    }
private:
    const int field = 42;
};


class Math{
public:
   static double pi;
};

double Math::pi = 3.14;

int main() {
    Class c;
    c.print();
    std::cout << c.getField() << std::endl;

    Math m;
    std::cout << m.pi << std::endl;
    Math m_other;
    std::cout << m_other.pi << std::endl;
    m_other.pi = 3.1419;
    std::cout << m.pi << std::endl;


    //std::cout << Math::pi << std::endl;
}