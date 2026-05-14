#include <iostream>
#include <string>
#include <vector> // For test driver

// Logger class definition
class Logger {
public:
    // Method to log a message and increment the counter
    // Efficiency issue: 'message' is passed by value, causing an unnecessary copy
    void logMessage(std::string message) { // Pass by value
        // Readability issue: overly verbose incrementation
        int tempCount = messageCount;
        tempCount = tempCount + 1;
        messageCount = tempCount;
        // std::cout << "Processed log: " << message << std::endl; // For debugging
    }

    // Static method to get the total number of messages
    // Readability issue: uses an unnecessary temporary variable
    static int getTotalMessages() {
        int finalCount = messageCount; // Unnecessary temporary variable
        return finalCount;
    }

private:
    static int messageCount; // Static member declaration
};

// Static member definition (must be outside the class definition)
int Logger::messageCount = 0;

int main() {
    Logger logger1;
    logger1.logMessage("First log message.");
    logger1.logMessage("Second log message.");

    Logger logger2; // Another instance, shares the same static messageCount
    logger2.logMessage("Third log message from another instance.");

    std::cout << "Current message count: " << Logger::getTotalMessages() << std::endl;

    logger1.logMessage("Fourth log message.");
    logger2.logMessage("Fifth log message.");

    std::cout << "Final message count: " << Logger::getTotalMessages() << std::endl;

    // Expected output:
    // Current message count: 3
    // Final message count: 5

    if (Logger::getTotalMessages() == 5) {
        std::cout << "Test passed: Total messages count is correct." << std::endl;
        return 0;
    } else {
        std::cout << "Test failed: Total messages count is incorrect." << std::endl;
        return 1;
    }
}