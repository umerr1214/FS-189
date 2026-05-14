#include <iostream>
#include <string>
#include <sstream> // Included for stringstream, used inefficiently
#include <cctype>  // For std::toupper

class Logger {
public:
    Logger() {
        // Default constructor
    }

    // Overloaded log method for std::string message
    // Readability/Efficiency Issue: Passes std::string by value, causing unnecessary copies.
    void log(std::string message) { // Should be 'const std::string& message'
        std::stringstream ss; // Inefficient: Creates a stringstream for every log call
        ss << "[LOG MESSAGE] " << message;
        std::cout << ss.str() << std::endl; // Extracts string then prints
    }

    // Overloaded log method for int error code
    // Readability/Efficiency Issue: Also uses stringstream unnecessarily.
    void log(int errorCode) { // Not marked 'const'
        std::stringstream ss_err;
        ss_err << "[LOG ERROR] Code: " << errorCode;
        std::cout << ss_err.str() << std::endl;
    }

    // Overloaded log method for char severity level
    // Readability/Efficiency Issue: Uses stringstream and unnecessary toupper logic.
    void log(char severityLevel) { // Not marked 'const'
        std::stringstream ss_sev;
        // Unnecessarily converts to uppercase even if not a letter or already uppercase,
        // and then casts back to char, which can be verbose for simple logging.
        ss_sev << "[LOG SEVERITY] Level: " << static_cast<char>(std::toupper(severityLevel));
        std::cout << ss_sev.str() << std::endl;
    }
};

int main() {
    Logger myLogger; // Creates a Logger object

    myLogger.log("Application is starting up.");
    myLogger.log(100); // Informational code
    myLogger.log('i'); // Info severity (will be converted to 'I')
    myLogger.log("Processing batch job.");
    myLogger.log(201); // Created resource code
    myLogger.log('w'); // Warning severity (will be converted to 'W')

    return 0;
}