#include <iostream>
#include <string>

class Logger {
public:
    void log(const char* message) {
        // Efficiency issue: Uses std::endl which flushes the output buffer
        // on every call. For frequent logging, using '\n' and letting the
        // buffer flush periodically or explicitly is more efficient.
        std::cout << "[INFO] Message: " << message << std::endl;
    }

    void log(int errorCode) {
        // Efficiency issue: Uses std::endl
        std::cout << "[ERROR] Code: " << errorCode << std::endl;
    }

    void log(bool status) {
        // Readability issue: Prints '1' for true and '0' for false.
        // While technically correct, using `std::boolalpha` to print
        // 'true' or 'false' would significantly improve readability for
        // human-readable boolean status messages.
        // Efficiency issue: Uses std::endl
        std::cout << "[STATUS] Success: " << status << std::endl;
    }
};

// Driver code for testing
#include <sstream> // For capturing output

int main() {
    Logger logger;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    logger.log("Application started.");
    logger.log(101);
    logger.log(true); // Will print 1
    logger.log("Processing data...");
    logger.log(200);
    logger.log(false); // Will print 0
    logger.log("Shutdown initiated.");
    
    std::cout.rdbuf(oldCout);
    std::cout << ss.str();

    return 0;
}