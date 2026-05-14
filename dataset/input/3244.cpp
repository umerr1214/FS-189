#include <iostream>
#include <string>

class Logger {
public:
    void logMessage(std::string msg) {
        std::cout << "Logger (string): " << msg << std::endl;
    }
    void logMessage(int num) {
        std::cout << "Logger (int): " << num << std::endl;
    }
};

class ConsoleLogger : public Logger {
public:
    void logMessage(std::string msg) { // This hides Logger's logMessage(string) and logMessage(int)
        std::cout << "ConsoleLogger (string): " << msg << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    ConsoleLogger cl;
    cl.logMessage("Hello from ConsoleLogger"); // Calls ConsoleLogger's string method
    // If the semicolon were present, the following line would cause a semantic error (no matching function)
    // cl.logMessage(123);
    return 0;
}