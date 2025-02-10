#include <iostream>

/*
struct Vector {
    int* data;
    int size, capacity;
};

bool empty(Vector& v) {
    return v.size == 0;
}

void Init(Vector& v, int new_size) {
    v.data = new int[new_size];
    v.size = 0;
    v.capacity = new_size;
}

void Destruct(Vector& v) {
    delete[] v.data;
}

void push_back(Vector& v, int value) {
    v.data[v.size++] = value;
}
*/

struct Vector {
public:
    bool empty() {
        return size == 0;
    }

    Vector(int new_size) {
        data = new int[new_size];
        size = 0;
        capacity = new_size;
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(int value) {
        data[size++] = value;
    }

    // getter
    int get_size() {
        return size;
    }
private:
    int* data;
    int size, capacity;
};


class Fraction {
    // some methods..

    int get_denominator() { // getter
        return denominator;
    }

    void set_denominator(int d) { // setter with check
        if (d == 0) {
            std::cout << "Bad denominator" << std::endl;
        } else {
            denominator = d;
        }
    }
private:
    int numerator;
    int denominator;
};


int main() {
    Vector v(5);
    // v.size = 100500; // prohibited
    std::cout << std::boolalpha <<
        "Vector is empty? " << v.empty() << std::endl;
}
