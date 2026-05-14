#include <iostream>
#include <string>

class Logger {
public:
    void log(const char* message) {
        std::cout << "[INFO] Message: " << message << std::endl;
    }

    void log(int errorCode) {
        // Semantic Error: The log message for an integer error code incorrectly
        // adds an interpretation of 'Success' or 'Failure' based on the truthiness
        // of the error code, which misrepresents the purpose of logging an error code.
        if (errorCode != 0) {
            std::cout << "[ERROR] Code: " << errorCode << " (interpreted as Non-Zero/Success)" << std::endl;
        } else {
            std::cout << "[ERROR] Code: " << errorCode << " (interpreted as Zero/Failure)" << std::endl;
        }
    }

    void log(bool status) {
        std::cout << "[STATUS] " << (status ? "Success" : "Failure") << std::endl;
    }
};

int main() {
    Logger logger;
    logger.log("Application started.");
    logger.log(500); // Will print "Code: 500 (interpreted as Non-Zero/Success)"
    logger.log(0);   // Will print "Code: 0 (interpreted as Zero/Failure)"
    logger.log(true);
    return 0;
}