#include <iostream>
#include <string>

class Logger {
public:
    void logMessage(std::string msg) {
        std::cout << "Logger (string): " << msg << std::endl;
    }
    void logMessage(int num) { // This will be hidden by ConsoleLogger's logMessage(string)
        std::cout << "Logger (int): " << num << std::endl;
    }
};

class ConsoleLogger : public Logger {
public:
    void logMessage(std::string msg) { // This hides Logger's logMessage(string) and logMessage(int)
        std::cout << "ConsoleLogger (string): " << msg << std::endl;
    }
    // No 'using Logger::logMessage;' here, so method hiding occurs as expected.
};

int main() {
    ConsoleLogger cl;
    std::cout << "Demonstrating method hiding:\n" << std::endl;
    
    std::cout << "Calling logMessage(\"string\") on ConsoleLogger object:" << std::endl;
    cl.logMessage("This calls ConsoleLogger's string method."); // Calls ConsoleLogger's string method

    std::cout << "\nAttempting to call logMessage(int) on ConsoleLogger object:" << std::endl;
    // SEMANTIC ERROR: ConsoleLogger::logMessage(std::string) hides all base class
    // methods named 'logMessage'. Since ConsoleLogger itself does not provide
    // a logMessage(int) overload, this call results in a compile-time error
    // "no matching function for call to 'ConsoleLogger::logMessage(int)'".
    cl.logMessage(123); 

    // To explicitly call the hidden base method:
    // cl.Logger::logMessage(123);
    // Or via a base pointer (static dispatch):
    // Logger* basePtr = &cl;
    // basePtr->logMessage(456);

    return 0;
}