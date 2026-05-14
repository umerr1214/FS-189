#include <iostream>

class ResourceHandler {
public:
    ResourceHandler() {
        // Logical Error: Swapped messages - acquiring prints 'released'
        std::cout << "Resource released." << std::endl; 
    }

    ~ResourceHandler() {
        // Logical Error: Swapped messages - releasing prints 'acquired'
        std::cout << "Resource acquired." << std::endl;
    }
};

int main() {
    ResourceHandler rh;
    return 0;
}