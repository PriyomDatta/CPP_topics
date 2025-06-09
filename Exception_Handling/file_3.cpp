#include <iostream>
#include <typeinfo> // For std::bad_cast

class Base {
public:
    virtual ~Base() {} // Must be polymorphic for dynamic_cast to work
};

class Derived : public Base {
public:
    void greet() {
        std::cout << "Hello from Derived!" << std::endl;
    }
};

int main() {
    try {
        Base baseObj;
        Base& baseRef = baseObj;

        // Attempt to cast baseRef to Derived& (will fail)
        Derived& derivedRef = dynamic_cast<Derived&>(baseRef);

        derivedRef.greet(); // This line won't be reached
    } catch (const std::bad_cast& e) {
        std::cerr << "Caught std::bad_cast: " << e.what() << std::endl;
    }

    return 0;
}
