#include <iostream>
#include <string>
#include <cctype> // For std::toupper, though not strictly used robustly here

class Logger {
private:
    std::string* log_prefix; // This will be leaked if not handled by destructor

public:
    Logger() {
        // Dynamically allocating memory but no corresponding 'delete' in a destructor.
        // This leads to a memory leak when Logger objects are destroyed.
        log_prefix = new std::string("[APP_LOG] ");
    }

    // Overloaded log method for std::string message
    void log(const std::string& message) {
        std::cout << *log_prefix << "MESSAGE: " << message << std::endl;
    }

    // Overloaded log method for int error code
    void log(int errorCode) {
        std::cout << *log_prefix << "ERROR CODE: " << errorCode << std::endl;
    }

    // Overloaded log method for char severity level
    void log(char severityLevel) {
        // This method doesn't robustly handle all possible char inputs.
        // It prints potentially unreadable characters directly if not 'I', 'W', 'E', 'D',
        // without providing more context or converting them to a known string.
        if (severityLevel == 'I' || severityLevel == 'W' || severityLevel == 'E' || severityLevel == 'D') {
            std::cout << *log_prefix << "SEVERITY: " << severityLevel << std::endl;
        } else {
            std::cout << *log_prefix << "UNKNOWN SEVERITY CHAR (raw): " << severityLevel << std::endl;
        }
    }
};

int main() {
    Logger loggerInstance; // Logger object created

    loggerInstance.log("System initialization started.");
    loggerInstance.log(1001); // A custom error code
    loggerInstance.log('I');  // Info severity
    loggerInstance.log("User 'admin' logged in.");
    loggerInstance.log(404);  // Not Found error code
    loggerInstance.log('W');  // Warning severity
    loggerInstance.log('Z');  // An unhandled char severity

    // When loggerInstance goes out of scope here, its destructor (if any) would be called.
    // However, since there is no custom destructor, 'log_prefix' memory is leaked.

    return 0;
}