#include <iostream>

struct DynArray {
    int* data = nullptr;
    unsigned size = 0; // actual size
    unsigned capacity = 0; // potential size (allocated in memory)

    // special member functions

    // constructor
    DynArray(unsigned new_capacity = 0u) {
        if (new_capacity)
            resize(new_capacity);
    }

    // desctructor
    ~DynArray() {
        delete[] data;
        capacity = 0u;
        size = 0u;
    }


    // member functions

    void push_back(int value) {
        if (size == capacity) {
            resize(std::max(2 * capacity, 1u));
        }
        data[size++] = value;
    }

    void resize(unsigned new_capacity) {
        int* new_data = new int[new_capacity];

        for (auto i = 0u; i < size; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    int at(unsigned idx) {
        return data[idx];
    }

    void set(unsigned idx, int val) {
        data[idx] = val;
    }
};



int main() {
    int n;
    std::cout << "Input initial array capacity: ";
    std::cin >> n;

    DynArray d(n); // may be empty: DynArray d;

    int items;
    std::cout << "Input number of items: ";
    std::cin >> items;
    for (auto i = 0; i < items; i++) {
        int v;
        std::cin >> v;
        d.push_back(v);
        std::cout << d.size << ' ' << d.capacity << std::endl;
    }

    for (auto i = 0; i < items; i++) {
        std::cout << d.at(i) << ' ';
    }
    std::cout << std::endl;
}
