#include <iostream>

void multiply_by_two(int* p) {
    *p *= 2;
}

int main() {
    int x;
    std::cin >> x;

    multiply_by_two(&x);

    // this way, x is changed
    std::cout << x << std::endl;

    int a[3] = {3, 7, 9};
	
	  // array is pointer
    for (auto i = 0; i < 3; i++)
        std::cout << *(a + i) << std::endl;

	  // variable in heap
    int* ptr_to_dynamic_variable = new int(42);
    std::cout << *ptr_to_dynamic_variable << std::endl;
    delete ptr_to_dynamic_variable;


    unsigned len;
    std::cin >> len;

	  // dynamic array
    int* dyn_arr = new int[len];

    for (auto i = 0u; i < len; i++) {
        std::cin >> dyn_arr[i];
    }

    for (auto i = 0u; i < len; i++) {
        std::cout << dyn_arr[i] << ' ';
    }
    std::cout << std::endl;

    delete[] dyn_arr;

}
