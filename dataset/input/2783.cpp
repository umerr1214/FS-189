#include <iostream>
#include <string>

class Logger {
public:
    void log(const std::string& message) {
        std::cout << "[INFO] Message: " << message << std::endl;
    }

    void log(int errorCode) {
        std::cout << "[ERROR] Code: " << errorCode << std::endl;
    }

    void log(char severityLevel) {
        // LOGICAL ERROR: This method always prints "LOGICAL_ERROR" as prefix
        // regardless of the actual severityLevel character, violating "appropriate formatted message".
        std::string severityStr = "LOGICAL_ERROR"; // Should be determined by switch/if
        std::cout << "[" << severityStr << "] Severity: " << severityLevel << std::endl;
    }
};

int main() {
    Logger logger;
    logger.log("System initialization complete.");
    logger.log(101);
    logger.log('I'); // Info - will be logged as LOGICAL_ERROR
    logger.log('E'); // Error - will be logged as LOGICAL_ERROR
    logger.log("User authentication failed.");
    logger.log(403);
    logger.log('D'); // Debug - will be logged as LOGICAL_ERROR
    return 0;
}