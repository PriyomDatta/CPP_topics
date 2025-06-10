#include <iostream>
#include <exception>

void unexpectedHandler() {
    std::cout << "An unexpected exception occurred! Throwing std::bad_exception...\n";
    throw std::bad_exception();
}

class MyClass {
public:
    void riskyFunction() throw(std::bad_exception) { // Deprecated exception specification
        throw std::runtime_error("Oops! Something went wrong.");
    }
};

int main() {
    std::set_unexpected(unexpectedHandler); // Set unexpected exception handler

    MyClass obj;

    try {
        obj.riskyFunction();
    } catch (const std::bad_exception& e) {
        std::cout << "Caught std::bad_exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught some other exception: " << e.what() << std::endl;
    }

    return 0;
}