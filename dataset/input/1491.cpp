#include <iostream> // Required for standard input/output operations (std::cout)

// Definition of the Logger class.
// This class is designed to demonstrate its lifecycle by printing messages
// when its constructor and destructor are called.
class Logger {
public:
    // Constructor for the Logger class.
    // This method is automatically called when a Logger object is created.
    Logger() {
        // Prints the initialization message to standard output.
        // Using '\n' is generally more efficient than std::endl as it doesn't force a buffer flush.
        std::cout << "Logger initialized.\n";
    }

    // Destructor for the Logger class.
    // This method is automatically called when a Logger object is destroyed
    // (i.e., goes out of scope or is explicitly deleted).
    ~Logger() {
        // Prints the destruction message to standard output.
        std::cout << "Logger destroyed.\n";
    }
};

// A helper function to demonstrate the Logger's lifecycle within a function's scope.
void demonstrate_scoped_logger() {
    std::cout << "Entering demonstrate_scoped_logger function.\n";
    Logger func_logger; // A Logger object created on the stack within this function's scope.
                        // Its constructor is called here.
    std::cout << "Exiting demonstrate_scoped_logger function.\n";
} // 'func_logger' goes out of scope here, and its destructor is called.

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is good practice for performance-critical applications, though optional for this simple case.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << "Main function started.\n";

    // 1. Demonstrate Logger lifecycle in the main function's scope.
    Logger main_scope_logger; // 'main_scope_logger' is created. Constructor called.

    // 2. Demonstrate Logger lifecycle within a nested block scope.
    {
        std::cout << "Entering nested block scope.\n";
        Logger block_scope_logger; // 'block_scope_logger' is created. Constructor called.
        std::cout << "Exiting nested block scope.\n";
    } // 'block_scope_logger' goes out of scope here. Destructor called.

    // 3. Demonstrate Logger lifecycle within a separate function's scope.
    demonstrate_scoped_logger();

    std::cout << "Main function finished.\n";
    return 0;
} // 'main_scope_logger' goes out of scope here. Destructor called.