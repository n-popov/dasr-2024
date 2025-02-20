#include <iostream>

namespace A {
    void func() {
        std::cout << "Func from A" << std::endl;
    }
};

namespace BWrapper {
    namespace B {
        void func() {
            std::cout << "Func from B" << std::endl;
        }
    };
};


namespace A {
    class Class {
    };
};

using namespace BWrapper::B;
using namespace A;

int main() {
    // func(); // fail
    A::func();
    BWrapper::B::func(); // the same

    Class c;
}
