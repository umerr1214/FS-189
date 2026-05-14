#include <iostream>

class Logger {
public:
    Logger() {
        std::cout << "Logger destroyed" << std::endl; // LOGICAL ERROR: Prints 'destroyed' instead of 'initialized'
    }

    ~Logger() {
        std::cout << "Logger initialized" << std::endl; // LOGICAL ERROR: Prints 'initialized' instead of 'destroyed'
    }
};

int main() {
    std::cout << "Entering main scope" << std::endl;
    {
        std::cout << "Entering inner scope" << std::endl;
        Logger myLogger; // Object created, constructor called (incorrect message)
        std::cout << "Exiting inner scope" << std::endl;
    } // Object destroyed, destructor called (incorrect message)
    std::cout << "Exiting main scope" << std::endl;
    return 0;
}