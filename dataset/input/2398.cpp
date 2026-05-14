#include <iostream>

class ResourceHandler {
public:
    ResourceHandler() {
        std::cout << "Resource acquired." << std::endl;
    }

    ~ResourceHandler() {
        std::cout << "Resource released." << std::endl;
    }
}; // Missing semicolon here

int main() {
    ResourceHandler rh;
    return 0;
}