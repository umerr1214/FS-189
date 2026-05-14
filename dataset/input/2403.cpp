#include <iostream> // Required for input/output operations (std::cout, std::endl).
#include <string>   // Not strictly necessary for this minimal example, but often useful.

// The ResourceHandler class encapsulates resource acquisition and release.
// It follows the Resource Acquisition Is Initialization (RAII) principle.
class ResourceHandler {
public:
    // Constructor: This method is called when an object of ResourceHandler is created.
    // It simulates the acquisition of a resource.
    ResourceHandler() {
        std::cout << "Resource acquired." << std::endl;
    }

    // Destructor: This method is called automatically when an object of ResourceHandler
    // goes out of scope or is explicitly destroyed.
    // It ensures the release of the resource, making the class exception-safe.
    ~ResourceHandler() {
        std::cout << "Resource released." << std::endl;
    }

    // Deleted copy constructor and copy assignment operator.
    // For classes managing unique resources (like a file handle or a network connection),
    // copying often doesn't make sense or leads to complex ownership issues (e.g., double-free).
    // Deleting these prevents accidental shallow copies and enforces unique ownership,
    // adhering to the Rule of Zero/Five for unique resource management.
    ResourceHandler(const ResourceHandler&) = delete;
    ResourceHandler& operator=(const ResourceHandler&) = delete;

    // A const member function to simulate performing work with the resource.
    // 'const' indicates that this method does not modify the object's state.
    void do_work() const {
        std::cout << "Resource is performing work." << std::endl;
    }
};

// A free function to demonstrate the RAII principle in action within a local scope.
void manage_resource_in_scope() {
    std::cout << "\n--- Entering manage_resource_in_scope() ---" << std::endl;
    ResourceHandler handler_in_func; // Resource is acquired here.
    handler_in_func.do_work();       // Use the resource.
    std::cout << "--- Exiting manage_resource_in_scope() ---" << std::endl;
    // 'handler_in_func' goes out of scope here, and its destructor is automatically called,
    // ensuring the resource is released.
}

// The main function, the entry point of the program.
int main() {
    std::cout << "--- Main Program Start ---" << std::endl;

    // Create a ResourceHandler object in the main function's scope.
    ResourceHandler main_handler; // Resource acquired.
    main_handler.do_work();       // Use the resource.

    // Call the helper function to demonstrate resource management in a nested scope.
    manage_resource_in_scope();

    // Demonstrate resource management within an explicit nested block scope.
    {
        std::cout << "\n--- Entering nested block scope ---" << std::endl;
        ResourceHandler nested_handler; // Resource acquired.
        nested_handler.do_work();       // Use the resource.
        std::cout << "--- Exiting nested block scope ---" << std::endl;
    } // 'nested_handler' goes out of scope here, its destructor is called.

    std::cout << "\n--- Main Program End ---" << std::endl;
    // 'main_handler' goes out of scope here, and its destructor is automatically called.

    return 0; // Indicate successful program termination.
}