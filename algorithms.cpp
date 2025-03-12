#include <iostream>
#include <algorithm>
#include <numeric>

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

    int& operator[](unsigned idx) {
        return data[idx];
    }

    // getter
    int get_size() {
        return size;
    }

    int* begin() {
        return data + 0;
    }

    int* end() {
        return data + size;
    }
private:
    int* data;
    int size, capacity;
};

int main() {
    Vector v(5);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(4);


    for(auto i = 0u; i < v.get_size(); i++) {
        std::cout << v[i] << std::endl;
    }

    // range-based for (RBF)
    for(auto item: v) {
        std::cout << item << std::endl;
    }

    for (auto iter = v.begin(); iter != v.end(); iter++) {
        std::cout << *iter << std::endl;
    }

    std::cout << "Max element is " <<
        *std::max_element(v.begin(), v.end()) << std::endl;

    std::cout << "Elements less than three: " <<
        std::count_if(v.begin(), v.end(), [](auto item) {return item < 3;})
            << std::endl;

    std::vector<int> values = {12, 1, 42, 17, 10};

    std::vector<int> squares(5);

    std::transform(values.begin(), values.end(), squares.begin(), [](auto item){
        return item * item;});

    for (auto item: squares) {
        std::cout << item << std::endl;
    }
    std::cout << std::endl;

    std::replace_if(squares.begin(), squares.end(),
                 [](auto item){return item <= 100;}, 0);

    for (auto item: squares) {
        std::cout << item << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Sum of modified squares: " << std::accumulate(
        squares.begin(), squares.end(), 0) << std::endl;

    std::cout << "Product of initial array: " << std::accumulate(
        values.begin(), values.end(), 1, [](auto l, auto r){ return l * r;})
         << std::endl;

    std::sort(values.begin(), values.end());
    for (auto item: values) {
        std::cout << item << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Inner product is " << std::inner_product(values.begin(),
        values.end(), squares.begin(), 0u) << std::endl;

    auto remove_iterator = std::remove_if(values.begin(), values.end(),
        [](auto item){return item % 2;});

    std::cout << "After remove:" << std::endl;
    for (auto item: values) {
        std::cout << item << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Remove from: " << *remove_iterator << std::endl;

    values.erase(remove_iterator, values.end());
    std::cout << "After erase:" << std::endl;

    for (std::vector<int>::iterator iter = values.begin(); iter != values.end(); iter++) {
        std::cout << *iter << std::endl;
    }

    for (std::vector<int>::reverse_iterator iter = values.rbegin(); iter != values.rend(); iter++) {
        std::cout << *iter << std::endl;
    }
}
