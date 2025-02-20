
#include <iostream>


class Parent {
public:
    Parent() {
        std::cout << "Parent constructor called, "
            "allocating resources X" << std::endl;
    }

    virtual ~Parent() {
        std::cout << "Parent destructor called, "
            "freeing resources X" << std::endl;
    }
};

class Child: public Parent {
public:
    Child() {
        std::cout << "Child constructor called, "
            "allocating resources Y" << std::endl;
    }

    virtual ~Child() {
        std::cout << "Child destructor called, "
            "freeing resources Y" << std::endl;
    }
};

int main() {
    Parent* new_child = new Child();

    delete new_child;
}
