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
        std::string severityStr;
        switch (severityLevel) {
            case 'D': severityStr = "DEBUG"; break;
            case 'I': severityStr = "INFO"; break;
            case 'W': severityStr = "WARNING"; break;
            case 'E': severityStr = "ERROR"; break;
            case 'F': severityStr = "FATAL"; break;
            default: severityStr = "UNKNOWN"; break;
        }
        std::cout << "[" << severityStr << "] Severity: " << severityLevel << std::endl
    } // SYNTAX ERROR: Missing semicolon here
};

int main() {
    Logger logger;
    logger.log("System initialization complete.");
    logger.log(101);
    logger.log('I'); // Info
    logger.log('E'); // Error
    logger.log("User authentication failed.");
    logger.log(403);
    logger.log('D'); // Debug
    return 0;
}