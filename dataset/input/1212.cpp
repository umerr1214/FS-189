#include <iostream>
#include <string>

class ResourceHandler {
public:
    ResourceHandler() {
        std::cout << "Resource acquired." << std::endl;
    }

private: // Semantic error: Destructor is private
    ~ResourceHandler() {
        std::cout << "Resource released." << std::endl;
    }
};

int main() {
    // This will cause a compile-time error because the compiler needs to call
    // the destructor when 'res' goes out of scope, but it's private.
    ResourceHandler res;
    return 0;
}