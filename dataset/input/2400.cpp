#include <iostream>

class ResourceHandler {
private:
    int* actual_resource_ptr; // A resource that needs management
public:
    ResourceHandler() {
        actual_resource_ptr = new int(42); // Acquire a resource (allocate memory)
        std::cout << "Resource acquired." << std::endl;
    }

    ~ResourceHandler() {
        std::cout << "Resource released." << std::endl;
        // Semantic Error: Forgetting to delete the allocated memory, leading to a memory leak.
        // delete actual_resource_ptr; // This line is intentionally commented out
    }
};

int main() {
    ResourceHandler rh;
    return 0;
}