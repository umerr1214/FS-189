#include <iostream>
#include <string>

class Logger {
public:
    static int messageCount;

    Logger() {}

    void logMessage(std::string message) {
        std::cout << "Logging: " << message << std::endl;
        // LOGICAL ERROR: messageCount is not incremented here
    }

    static int getTotalMessages() {
        return messageCount;
    }
};

int Logger::messageCount = 0;

int main() {
    Logger l1;
    l1.logMessage("First message.");
    l1.logMessage("Second message.");

    Logger l2;
    l2.logMessage("Third message.");

    std::cout << "Total messages: " << Logger::getTotalMessages() << std::endl;

    return 0;
}