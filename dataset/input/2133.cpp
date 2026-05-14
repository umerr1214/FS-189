#include <iostream>
#include <string> // Not strictly used, but good practice for C++ string ops
#include <iomanip> // Required for std::boolalpha

class Logger {
public:
    void log(const char* message) {
        // Robustness: Check for nullptr message to prevent undefined behavior
        // and provide a clear message in such cases.
        if (message == nullptr) {
            std::cout << "[INFO] Message: (nullptr received)\n";
        } else {
            // Efficiency: Use '\n' instead of std::endl to avoid frequent buffer flushes.
            std::cout << "[INFO] Message: " << message << "\n";
        }
    }

    void log(int errorCode) {
        // Efficiency: Use '\n' instead of std::endl.
        std::cout << "[ERROR] Code: " << errorCode << "\n";
    }

    void log(bool status) {
        // Readability: Use std::boolalpha for clear 'true'/'false' output.
        // Efficiency: Use '\n' instead of std::endl.
        // Note: std::boolalpha is sticky; for a simple logger like this, it's fine.
        // In more complex scenarios, one might save/restore stream flags.
        std::cout << "[STATUS] Success: " << std::boolalpha << status << "\n";
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
    logger.log(true); // Will print 'true'
    logger.log("Processing data...");
    logger.log(200);
    logger.log(false); // Will print 'false'
    logger.log("Shutdown initiated.");
    logger.log((const char*)nullptr); // Test nullptr handling

    std::cout.rdbuf(oldCout);
    std::cout << ss.str();

    return 0;
}