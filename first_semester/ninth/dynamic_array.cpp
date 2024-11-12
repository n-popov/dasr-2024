#include <iostream>

template <typename T>
struct DynArray {
    T* data = nullptr;
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

    void push_back(T value) {
        if (size == capacity) {
            resize(std::max(2 * capacity, 1u));
        }
        data[size++] = value;
    }

    void resize(unsigned new_capacity) {
        T* new_data = new T[new_capacity];

        for (auto i = 0u; i < size; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    T& operator[](unsigned idx) {
        return data[idx];
    }
};



int main() {
    /*int n;
    std::cout << "Input initial array capacity: ";
    std::cin >> n;

    DynArray<int> d(n); // may be empty: DynArray d;

    int items;
    std::cout << "Input number of items: ";
    std::cin >> items;
    for (auto i = 0; i < items; i++) {
        int v;
        std::cin >> v;
        d.push_back(v);
    }

    for (auto i = 0; i < items; i++) {
        std::cout << d.at(i) << ' ';
    }
    std::cout << std::endl;*/

    // Ссылка
    /*DynArray<int> arr;

    arr.push_back(3);
    arr.push_back(5);

    arr[1] = 42;

    for (auto i = 0; i < arr.size; i++) {
        std::cout << arr[i] << std::endl;
    }*/


    // Двумерный массив

    DynArray<DynArray<int>> matrix(5u);
    for (auto i = 0u; i < 5u; i++) {
        for (auto j = 0u; j < 4u; j++) {
            matrix[i].push_back(10 * i + j);
        }
    }

    for (auto i = 0u; i < 5u; i++) {
        for (auto j = 0u; j < 4u; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }



}
