#include <iostream>

class ClassPrinter;

class Class {
private:
    int field = 42;

friend ClassPrinter;
};

class ClassPrinter {
public:
    void print_other(Class c) {
        c.field = 100500;
        std::cout << "Printing class with field " << c.field << std::endl;
    }
};


int main() {
    Class c;
    // std::cout << c.field; prohibited

    ClassPrinter cp;

    cp.print_other(c);
}
