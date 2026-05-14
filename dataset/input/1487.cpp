#include <iostream>

class Logger {
public:
    Logger() {
        std::cout << "Logger initialized." << std::endl;
    }

    ~Logger() {
        // Logical error: Destructor prints the wrong message
        std::cout << "Logger initialized." << std::endl; 
    }
};

int main() {
    Logger myLogger;
    return 0;
}