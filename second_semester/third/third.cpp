
#include <iostream>

class Animal {
public:
    // Погладить данную зверушку.
    // Последствия зависят от реализации данного метода для класса конкретной зверушки.
    virtual void pet() = 0;

    virtual ~Animal() {};
};


class NPC {
public:
    // Поговорить с NPC.
    // Что он скажет - зависит от реализации данного метода для конкретного NPC.
    virtual void talk() = 0;

    virtual ~NPC() {};
};

class SmartCat: public Animal, public NPC {
public:
    virtual void pet() override {
        meow();
    }

    virtual void talk() override {
        meow();
    }

    virtual ~SmartCat() = default;

private:
    void meow() {
        std::cout << "Meow!" << std::endl;
    }

};


int main() {


    // Примерно так с нашим классом будут обращаться части движка,
    // которые вообще-то отвечают за взаимодействие со зверями.
    Animal *a = new SmartCat();
    a->pet();
    delete a;

    // А так - части движка, которые работают с NPC.
    NPC *n = new SmartCat();
    n->talk();
    delete n;

}

