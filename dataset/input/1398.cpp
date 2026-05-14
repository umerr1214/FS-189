#include <iostream>
#include <string>

class Logger {
public:
    int messageCount; // SEMANTIC ERROR: Should be static, but declared as non-static

    Logger() {
        messageCount = 0; // Initialize for each instance (incorrect for shared count)
    }

    void logMessage(std::string message) {
        std::cout << "Logging: " << message << std::endl;
        this->messageCount++; // Increments instance's count
    }

    static int getTotalMessages() {
        // SEMANTIC ERROR: Static method cannot access non-static member 'messageCount'
        return messageCount; 
    }
};

// No out-of-class definition for messageCount because it's non-static

int main() {
    // This code will not compile due to the semantic error in getTotalMessages
    Logger l1;
    l1.logMessage("First message.");
    l1.logMessage("Second message.");

    Logger l2;
    l2.logMessage("Third message.");

    // This line will cause a compile-time error
    // std::cout << "Total messages: " << Logger::getTotalMessages() << std::endl;

    return 0;
}