#include <iostream>
#include <string>

// Define the Logger class
class Logger {
public:
    // Constructor: Called when a Logger object is created.
    Logger() {
        std::cout << "Logger initialized\n";
    }

    // Destructor: Called when a Logger object goes out of scope.
    ~Logger() {
        std::cout << "Logger destroyed\n";
    }

    // A simple method to log a message (optional, but good for demonstration).
    void log(const std::string& message) const {
        std::cout << "Log message: " << message << "\n";
    }
};

// Function to demonstrate Logger's scope within a function.
void demonstrateFunctionScopeLogger() {
    std::cout << "\n--- Entering demonstrateFunctionScopeLogger() ---\n";
    Logger funcLogger; // funcLogger is created here
    funcLogger.log("This log is from inside the function.");
    std::cout << "--- Exiting demonstrateFunctionScopeLogger() ---\n";
} // funcLogger is automatically destroyed here

int main() {
    std::cout << "Main program started.\n";

    // Demonstrate Logger's scope within an explicit block.
    {
        std::cout << "\n--- Entering explicit block scope ---\n";
        Logger blockLogger; // blockLogger is created here
        blockLogger.log("This log is from inside the explicit block.");
        std::cout << "--- Exiting explicit block scope ---\n";
    } // blockLogger is automatically destroyed here

    // Call the function to demonstrate Logger's scope within a function.
    demonstrateFunctionScopeLogger();

    // Demonstrate Logger's scope within the main function itself.
    std::cout << "\n--- Back in main function scope ---\n";
    Logger mainLogger; // mainLogger is created here
    mainLogger.log("This log is from the main function's scope.");
    std::cout << "--- Main program about to end ---\n";

    return 0;
} // mainLogger is automatically destroyed here, then program exits.