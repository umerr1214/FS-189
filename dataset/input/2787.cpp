#include <iostream>
#include <string>

// A Logger class to demonstrate overloaded log methods
class Logger {
public:
    // Overloaded log method for std::string messages
    // Takes a const reference for efficiency and correctness.
    // Marked const as it does not modify the Logger object's state.
    void log(const std::string& message) const {
        std::cout << "[INFO] Message: " << message << std::endl;
    }

    // Overloaded log method for int error codes
    // Marked const as it does not modify the Logger object's state.
    void log(int errorCode) const {
        std::cout << "[ERROR] Code: " << errorCode << std::endl;
    }

    // Overloaded log method for char severity levels
    // Marked const as it does not modify the Logger object's state.
    void log(char severityLevel) const {
        std::cout << "[SEVERITY] Level: " << severityLevel << std::endl;
    }
};

int main() {
    Logger appLogger; // Create an instance of the Logger class

    // Use the overloaded log method for a string message
    appLogger.log("System startup complete.");

    // Use the overloaded log method for an integer error code
    appLogger.log(200); // HTTP OK-like status

    // Use the overloaded log method for a character severity level
    appLogger.log('I'); // 'I' for Information

    appLogger.log("User 'guest' accessed public page.");
    appLogger.log(401); // Unauthorized access attempt
    appLogger.log('W'); // 'W' for Warning

    appLogger.log("Critical database connection failed.");
    appLogger.log(500); // Internal Server Error
    appLogger.log('E'); // 'E' for Error

    return 0;
}