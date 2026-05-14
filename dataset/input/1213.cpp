#include <iostream>
#include <string>
#include <utility> // For std::move in case it's needed, though not directly for the issue here

// Class definition for ResourceHandler
class ResourceHandler {
public:
    std::string* resource_name_ptr; // Raw pointer to simulate a resource

    // Constructor: Simulates acquiring a resource
    ResourceHandler() : resource_name_ptr(new std::string("Critical System Resource")) {
        std::cout << "Resource " << *resource_name_ptr << " acquired." << std::endl;
    }

    // Destructor: Simulates releasing the resource
    ~ResourceHandler() {
        if (resource_name_ptr) { // Check to prevent deleting a nullptr, but doesn't prevent double-delete
            std::cout << "Resource " << *resource_name_ptr << " released." << std::endl;
            delete resource_name_ptr;
            resource_name_ptr = nullptr; // Set to nullptr after deletion
        } else {
            std::cout << "Attempted to release an already released or unacquired resource." << std::endl;
        }
    }

    // Note: Default copy constructor and assignment operator are implicitly generated,
    // performing shallow copies of resource_name_ptr, leading to a double-free issue.
};

int main() {
    std::cout << "Main function started." << std::endl;
    { // Scope to ensure destructors are called
        ResourceHandler handler1;
        std::cout << "Original ResourceHandler object created." << std::endl;

        // Creating a copy using the default copy constructor
        // This is where the robustness issue becomes apparent:
        // handler2 now points to the same memory as handler1.
        ResourceHandler handler2 = handler1;
        std::cout << "Copied ResourceHandler object created." << std::endl;

        // When handler1 and handler2 go out of scope, both will attempt to delete
        // the same resource_name_ptr, leading to a double-free.
    } // handler1 and handler2 go out of scope, destructors are called
    std::cout << "Main function finished." << std::endl;
    return 0;
}