#include <iostream>
#include <string>

// Class definition for ResourceHandler
class ResourceHandler {
private:
    bool m_is_resource_acquired; // Simple flag to indicate resource status

public:
    // Constructor: Simulates acquiring a resource
    ResourceHandler() : m_is_resource_acquired(true) {
        std::cout << "System resource acquired.\n";
    }

    // Destructor: Prints a message indicating the resource has been released
    ~ResourceHandler() {
        if (m_is_resource_acquired) {
            std::cout << "System resource released.\n";
            m_is_resource_acquired = false; // Mark as released
        } else {
            // This path should ideally not be hit if resource management is correct
            std::cout << "Attempted to release a resource that was not acquired.\n";
        }
    }

    // Optional: Method to check resource status
    bool isAcquired() const {
        return m_is_resource_acquired;
    }
};

int main() {
    std::cout << "Main function started.\n";
    { // Scope to ensure destructor is called
        ResourceHandler handler;
        std::cout << "ResourceHandler object created in inner scope.\n";
        // Optionally, interact with the handler
        if (handler.isAcquired()) {
            std::cout << "Resource is currently active.\n";
        }
    } // handler goes out of scope, destructor is called
    std::cout << "Main function finished.\n";
    return 0;
}