#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {} // Ensure Base is polymorphic
};

int main() {
    Base* ptr = nullptr; // Null pointer to a polymorphic type

    try {
        std::cout << "Type of ptr: " << typeid(*ptr).name() << std::endl;
    } catch (const std::bad_typeid& e) {
        std::cout << "Caught std::bad_typeid: " << e.what() << std::endl;
    }

    return 0;
}
