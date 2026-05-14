#include <iostream>
#include <string>
#include <fstream> // For file operations
#include <chrono>  // For timestamp
#include <ctime>   // For timestamp utilities

// Base class: Logger
// Provides a basic logging mechanism.
class Logger {
public:
    // Method to log a message.
    // Passes string by value, which is less efficient than const reference,
    // but not the primary robustness issue here.
    void logMessage(std::string msg) {
        std::cout << "[Logger Base] " << msg << std::endl;
    }
};

// Derived class: ConsoleLogger
// Specializes Logger to output messages to the console and a file.
class ConsoleLogger : public Logger {
public:
    // This method hides the base class's logMessage method.
    // It has the same name and parameter list as the base method but is not virtual.
    void logMessage(std::string msg) {
        // Robustness Issue:
        // Attempting to write to a file without proper error checking.
        // If "log.txt" cannot be opened (e.g., due to permissions, disk full,
        // invalid path), the `ofstream` object will be in a bad state.
        // Subsequent writes to `logFile` will fail silently without an explicit
        // check like `if (logFile.is_open())` or `if (logFile.good())`.
        // This can lead to lost log messages or unexpected program behavior.
        std::ofstream logFile("log.txt", std::ios_base::app); // Open for appending

        // Get current time for a simple timestamp
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::string timeStr = std::ctime(&currentTime);
        if (!timeStr.empty()) {
            timeStr.pop_back(); // Remove trailing newline from ctime output
        }

        std::cout << "[ConsoleLogger Derived] " << msg << std::endl;
        logFile << "[" << timeStr << "] " << msg << std::endl; // Writing without checking stream state
        // The file stream will be closed automatically when `logFile` goes out of scope.
    }
};

int main() {
    ConsoleLogger myConsoleLogger;
    Logger* basePtr = &myConsoleLogger;
    Logger& baseRef = myConsoleLogger;

    std::cout << "--- Demonstrating Method Hiding (Robustness Issue) ---" << std::endl;

    // 1. Calling logMessage directly on a ConsoleLogger object.
    // The derived method (ConsoleLogger::logMessage) is called.
    myConsoleLogger.logMessage("Message 1: Called directly on ConsoleLogger object.");

    // 2. Calling logMessage via a base class pointer pointing to ConsoleLogger.
    // Due to method hiding (and no 'virtual' keyword), the static type of the pointer
    // (Logger*) determines which method is called, so Logger::logMessage is executed.
    basePtr->logMessage("Message 2: Called via Logger* pointing to ConsoleLogger.");

    // 3. Calling logMessage via a base class reference referring to ConsoleLogger.
    // Similar to the pointer, the static type of the reference (Logger&) is used,
    // resulting in Logger::logMessage being called.
    baseRef.logMessage("Message 3: Called via Logger& referring to ConsoleLogger.");

    std::cout << "--- End Demonstration ---" << std::endl;

    return 0;
}