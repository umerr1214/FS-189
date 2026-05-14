#include <iostream>
#include <string> // Not strictly used in log methods, but common for string ops

class Logger {
public:
    void log(const char* message) {
        // Robustness issue: Does not check if 'message' is nullptr.
        // Directly printing a nullptr const char* can lead to undefined behavior
        // or print a platform-dependent string like "(null)". A robust solution
        // would check for nullptr and handle it gracefully.
        std::cout << "[INFO] Message: " << message << std::endl;
    }

    void log(int errorCode) {
        std::cout << "[ERROR] Code: " << errorCode << std::endl;
    }

    void log(bool status) {
        // Using a ternary operator for bool is functional, but could be
        // made more idiomatic with std::boolalpha for readability.
        // This is not the primary robustness issue for this example.
        std::cout << "[STATUS] Success: " << (status ? "true" : "false") << std::endl;
    }
};

// Driver code for testing
#include <sstream> // For capturing output

int main() {
    Logger logger;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf(); // Save old cout buffer
    std::cout.rdbuf(ss.rdbuf()); // Redirect cout to stringstream

    logger.log("Application started.");
    logger.log(101);
    logger.log(true);
    logger.log("Processing data...");
    logger.log(200);
    logger.log(false);
    logger.log("Shutdown initiated.");
    
    // This call exposes the robustness issue:
    // Printing nullptr const char* might output "(null)" or cause a crash.
    logger.log((const char*)nullptr); 

    std::cout.rdbuf(oldCout); // Restore cout buffer
    std::cout << ss.str(); // Print captured output

    return 0;
}