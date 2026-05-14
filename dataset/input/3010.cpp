#include <iostream>

class Logger {
public:
    Logger() {
        std::cout << "Logger initialized" << std::endl
    } // SYNTAX ERROR: Missing semicolon here

    ~Logger() {
        std::cout << "Logger destroyed" << std::endl;
    }
};

int main() {
    std::cout << "Entering main scope" << std::endl;
    {
        std::cout << "Entering inner scope" << std::endl;
        Logger myLogger; // Object created, constructor called
        std::cout << "Exiting inner scope" << std::endl;
    } // Object destroyed, destructor called
    std::cout << "Exiting main scope" << std::endl;
    return 0;
}