#include <iostream>
#include <string>

class Logger {
public:
    void log(const char* message) {
        std::cout << "[INFO] Message: " << message << std::endl;
    }

    void log(int errorCode) {
        std::cout << "[ERROR] Code: " << errorCode << std::endl;
    }

    void log(bool status) {
        std::cout << "[STATUS] " << (status ? "Success" : "Failure") << std::endl;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Logger logger;
    logger.log("Application started.");
    logger.log(500);
    logger.log(true);
    return 0;
}