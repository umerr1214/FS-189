#include <iostream>
#include <string>
#include <sstream> // For inefficient string concatenation

// base class
class Logger {
public:
    // Method to log a message.
    // Readability/Efficiency Issue: 'msg' is passed by value, creating an unnecessary copy.
    void logMessage(std::string msg) {
        std::cout << "Base logger msg: " << msg << std::endl;
    }
};

// derived class
class ConsoleLogger : public Logger {
public:
    // This method hides the base class's logMessage method.
    // Readability/Efficiency Issue:
    // 1. 'msg' is passed by value, creating an unnecessary copy.
    // 2. Uses `std::stringstream` for simple string concatenation, which is less efficient
    //    and more verbose than direct `std::string` concatenation (`+` operator) for this case.
    // 3. Poor variable names (`ss`, `_m`) reduce readability.
    // 4. Lack of comments explaining the logic or intent.
    void logMessage(std::string msg) {
        std::stringstream ss; // Inefficient for simple concatenation
        ss << "Derived logger output: " << msg;
        std::string _m = ss.str(); // Poor variable name
        std::cout << _m << std::endl;
    }
};

int main() {
    ConsoleLogger clObj; // Poor variable name
    Logger* lPtr = &clObj; // Poor variable name
    Logger& lRef = clObj; // Poor variable name

    std::cout << "--- Method Hiding Demo (Inefficient/Unreadable) ---" << std::endl;

    // Calling logMessage directly on ConsoleLogger object (calls derived)
    clObj.logMessage("First message from derived.");

    // Calling logMessage via base pointer (calls base)
    lPtr->logMessage("Second message from base via pointer.");

    // Calling logMessage via base reference (calls base)
    lRef.logMessage("Third message from base via reference.");

    std::cout << "--- End Demo ---" << std::endl;

    return 0;
}