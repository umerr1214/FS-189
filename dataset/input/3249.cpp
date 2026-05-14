#include <iostream>
#include <string>

// Base class: Logger
// Provides a basic logging mechanism.
class Logger {
public:
    // Method to log a message.
    // Takes a constant reference to a string to avoid unnecessary copying (efficiency).
    void logMessage(const std::string& msg) {
        std::cout << "[Logger Base] " << msg << std::endl;
    }
};

// Derived class: ConsoleLogger
// Specializes Logger to output messages to the console.
class ConsoleLogger : public Logger {
public:
    // This method hides the base class's logMessage method.
    // It has the same name and parameter list as the base method but is not virtual.
    // Takes a constant reference to a string for efficiency.
    void logMessage(const std::string& msg) {
        std::cout << "[ConsoleLogger Derived] " << msg << std::endl;
    }
};

int main() {
    // 1. Create a ConsoleLogger object.
    ConsoleLogger myConsoleLogger;

    // 2. Create a base class pointer pointing to the ConsoleLogger object.
    Logger* baseLoggerPtr = &myConsoleLogger;

    // 3. Create a base class reference referring to the ConsoleLogger object.
    Logger& baseLoggerRef = myConsoleLogger;

    std::cout << "--- Demonstrating Method Hiding (Correct Version) ---" << std::endl;

    // Scenario A: Calling logMessage directly on a ConsoleLogger object.
    // The compiler finds ConsoleLogger::logMessage first, so the derived method is called.
    myConsoleLogger.logMessage("Message 1: Called directly on ConsoleLogger object.");

    // Scenario B: Calling logMessage via a base class pointer pointing to ConsoleLogger.
    // Due to method hiding (and no 'virtual' keyword), the compiler uses the static type
    // of the pointer (Logger*), so Logger::logMessage is called, not ConsoleLogger::logMessage.
    baseLoggerPtr->logMessage("Message 2: Called via Logger* pointing to ConsoleLogger.");

    // Scenario C: Calling logMessage via a base class reference referring to ConsoleLogger.
    // Similar to the pointer, the static type of the reference (Logger&) is used,
    // resulting in Logger::logMessage being called.
    baseLoggerRef.logMessage("Message 3: Called via Logger& referring to ConsoleLogger.");

    // Scenario D: Explicitly calling the hidden base method on a ConsoleLogger object.
    // This demonstrates how to access the hidden base method when needed, despite it being hidden.
    myConsoleLogger.Logger::logMessage("Message 4: Explicitly called Logger::logMessage on ConsoleLogger object.");

    std::cout << "--- End Demonstration ---" << std::endl;

    return 0;
}