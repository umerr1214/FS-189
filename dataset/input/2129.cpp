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
        // Logical Error: This method always prints "Failure", regardless of the 'status' boolean value.
        std::cout << "[STATUS] Failure" << std::endl;
    }
};

int main() {
    Logger logger;
    logger.log("Application started.");
    logger.log(500);
    logger.log(true); // This call will incorrectly print "Failure"
    logger.log(false);
    return 0;
}