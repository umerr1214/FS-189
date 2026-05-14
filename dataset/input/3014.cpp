#include <cstdio> // For printf
#include <iostream> // For std::cout and std::endl
#include <string> // For std::string

// A class designed to log messages and demonstrate constructor/destructor calls.
class LoggerClassForDemonstration {
public:
    // Constructor: Prints an initialization message using printf for variety.
    LoggerClassForDemonstration() {
        printf("LoggerClassForDemonstration initialized (using printf).\n");
    }

    // Destructor: Prints a destruction message, again using printf.
    ~LoggerClassForDemonstration() {
        printf("LoggerClassForDemonstration destroyed (using printf).\n");
    }

    // A method to log a specific message.
    void writeLogEntry(const std::string& message) {
        std::cout << "LOG_ENTRY: " << message << std::endl; // Using std::endl which flushes
    }
};

// A function to encapsulate a scope for demonstrating the Logger's lifecycle.
void performScopedLoggingActivity() {
    std::cout << "--- Starting a scoped activity ---\n" << std::endl; // Using std::endl
    LoggerClassForDemonstration activityLogger; // Logger object created on the stack
    activityLogger.writeLogEntry("This message is from within the activity scope.");
    std::cout << "--- Ending a scoped activity ---\n" << std::endl; // Using std::endl
}

int main() {
    std::cout << "Main application execution begins." << std::endl; // Using std::endl

    // First demonstration: Logger in a local block scope.
    {
        std::cout << "\n>>> Entering explicit block scope 1 <<<" << std::endl; // Using std::endl
        LoggerClassForDemonstration blockOneLogger; // Logger object created here
        blockOneLogger.writeLogEntry("Message from inside block 1.");
        std::cout << ">>> Exiting explicit block scope 1 <<<" << std::endl; // Using std::endl
    } // blockOneLogger's destructor is called automatically here.

    // Second demonstration: Logger in a function scope.
    performScopedLoggingActivity();

    // Third demonstration: Logger in the main function's scope.
    LoggerClassForDemonstration mainScopeLogger; // This logger will be destroyed at main's end
    mainScopeLogger.writeLogEntry("Final message before main exits.");

    std::cout << "\nMain application execution concludes." << std::endl; // Using std::endl
    return 0;
}