#include <iostream>
#include <string>

class ResourceHandler {
public:
    ResourceHandler() {
        std::cout << "Resource acquired." << std::endl;
    }

    ~ResourceHandler() {
        std::cout << "Resource released." << std::endl;
    }
} // ERROR: Missing semicolon here

int main() {
    ResourceHandler res;
    // The destructor will be called automatically when 'res' goes out of scope.
    return 0;
}