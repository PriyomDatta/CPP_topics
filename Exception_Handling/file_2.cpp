#include <iostream>
#include <vector>
#include <new> // For std::bad_alloc

int main() {
    try {
        std::vector<int> data;
        while (true) {
            // Try to keep pushing large chunks of data
            data.push_back(15); // This will eventually exhaust memory
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }

    return 0;
}
