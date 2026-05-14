#include <iostream>

class Logger {
private: // SEMANTIC ERROR: Making constructor private prevents object creation from outside
    Logger() {
        std::cout << "Logger initialized" << std::endl;
    }

public:
    ~Logger() {
        std::cout << "Logger destroyed" << std::endl;
    }
};

int main() {
    std::cout << "Entering main scope" << std::endl;
    {
        std::cout << "Entering inner scope" << std::endl;
        // Attempting to create a Logger object will result in a semantic error
        // because its constructor is private.
        Logger myLogger; // This line will cause a compilation error (semantic)
        std::cout << "Exiting inner scope" << std::endl;
    }
    std::cout << "Exiting main scope" << std::endl;
    return 0;
}