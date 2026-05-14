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
    // LOGICAL ERROR: The 'using' declaration prevents method hiding for overloaded base methods.
    // The question asks to "demonstrate that calling logMessage on a ConsoleLogger object hides the base class method".
    // By bringing Logger's overloads into scope, ConsoleLogger::logMessage(std::string) no longer hides
    // Logger::logMessage(int), thus failing to demonstrate the hiding aspect for the int overload.
    using Logger::logMessage; 

    void logMessage(std::string msg) { 
        std::cout << "ConsoleLogger (string): " << msg << std::endl;
    }
};

int main() {
    ConsoleLogger cl;
    std::cout << "Calling logMessage(\"string\") on ConsoleLogger object:" << std::endl;
    cl.logMessage("Hello from ConsoleLogger"); // Calls ConsoleLogger's string method

    std::cout << "\nCalling logMessage(int) on ConsoleLogger object:" << std::endl;
    // Due to 'using Logger::logMessage;', this now calls Logger::logMessage(int),
    // instead of being a compile error (which would demonstrate hiding).
    cl.logMessage(123); 

    std::cout << "\nCalling logMessage via base pointer (static dispatch):" << std::endl;
    Logger* basePtr = &cl;
    basePtr->logMessage("Hello via base ptr");
    basePtr->logMessage(456);

    return 0;
}