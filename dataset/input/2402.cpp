#include <iostream> // Include the iostream library for input/output operations.
#include <string>   // Include the string library for string manipulation (though not heavily used here).

// A global counter variable to keep track of active resources.
// This is generally considered bad practice as it introduces global mutable state,
// reduces encapsulation, and can lead to hard-to-debug issues, especially in concurrent environments.
int g_resource_count = 0; // Initialize the global counter to zero.

// Define the ResourceHandler class.
class ResourceHandler {
public:
    // Constructor for the ResourceHandler class.
    // This method is called automatically when an object of ResourceHandler is created.
    ResourceHandler() {
        // Increment the global resource counter. This operation is not thread-safe.
        g_resource_count++;
        // Print a message to the console indicating that a resource has been acquired.
        // Using std::flush after every output statement can be inefficient as it forces
        // a write to the underlying stream buffer immediately, potentially reducing performance
        // compared to letting the buffer fill up or using std::endl once per line.
        std::cout << "Resource acquired. Current active resources: " << g_resource_count << std::flush;
        // This is a separate output statement for the same logical message, which is redundant
        // and makes the output less concise and potentially less efficient.
        std::cout << " This resource is now ready for use." << std::endl;
    }

    // Destructor for the ResourceHandler class.
    // This method is called automatically when an object of ResourceHandler goes out of scope.
    ~ResourceHandler() {
        // Decrement the global resource counter. This operation is also not thread-safe.
        g_resource_count--;
        // Print a message to the console indicating that a resource has been released.
        // Again, using std::flush unnecessarily.
        std::cout << "Resource released. Remaining active resources: " << g_resource_count << std::flush;
        // Another redundant output statement.
        std::cout << " This resource is no longer active." << std::endl;
    }

    // A simple public method to simulate performing an action with the resource.
    // This method demonstrates basic functionality of the resource.
    void performAction() {
        // Output a message to the console.
        std::cout << "Performing some action using the resource." << std::endl;
    }
};

// A free function to demonstrate the usage of ResourceHandler within a local scope.
// This function creates a ResourceHandler object, uses it, and then allows it to be destroyed.
void demonstrateResourceUsage() {
    // Print a message indicating entry into the function.
    std::cout << "  Inside demonstrateResourceUsage()..." << std::endl;
    // Create a ResourceHandler object named 'handler_in_func'.
    ResourceHandler handler_in_func;
    // Call the performAction method on the created object.
    handler_in_func.performAction();
    // Print a message indicating exit from the function.
    std::cout << "  Exiting demonstrateResourceUsage()." << std::endl;
    // The destructor of 'handler_in_func' will be called automatically here.
}

// The main function where the program execution begins.
int main() {
    // Print a message to indicate the start of the program.
    std::cout << "Program started." << std::endl;

    // Create a ResourceHandler object named 'main_handler' in the main scope.
    ResourceHandler main_handler;
    // Call its performAction method.
    main_handler.performAction();

    // Call the demonstrateResourceUsage function to show resource handling in another scope.
    std::cout << "\nEntering function demonstrateResourceUsage()..." << std::endl;
    demonstrateResourceUsage();
    std::cout << "Exited function demonstrateResourceUsage()." << std::endl;

    // Create another ResourceHandler object in a nested block scope.
    { // Start of nested block scope.
        std::cout << "\n--- Entering nested block scope ---" << std::endl;
        ResourceHandler nested_handler; // Resource acquired.
        nested_handler.performAction();
        std::cout << "--- Exiting nested block scope ---" << std::endl;
    } // End of nested block scope; nested_handler's destructor is called here.

    // Print a message to indicate the end of the program.
    std::cout << "\nProgram finished." << std::endl;

    return 0; // Indicate successful program execution.
}