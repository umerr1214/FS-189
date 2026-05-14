#include <iostream>
#include <string>

class Logger {
public:
    void log(const std::string& message) {
        std::cout << "[INFO] Message: " << message << std::endl;
    }

    void log(int errorCode) {
        // This method will be semantically misused when a char is passed
        // because the specific char overload is missing.
        std::cout << "[ERROR] Code: " << errorCode << std::endl;
    }

    // SEMANTIC ERROR: The 'log' method for char severity level is MISSING.
    // This violates the question's requirement to have a specific overload for char.
    // Calls like logger.log('I') will implicitly convert 'I' to its ASCII int value
    // and call log(int), which is semantically incorrect for logging severity.
};

int main() {
    Logger logger;
    logger.log("System initialization complete.");
    logger.log(101);
    logger.log('I'); // Calls log(int) due to implicit char-to-int conversion
    logger.log('E'); // Calls log(int) due to implicit char-to-int conversion
    logger.log("User authentication failed.");
    logger.log(403);
    logger.log('D'); // Calls log(int) due to implicit char-to-int conversion
    return 0;
}