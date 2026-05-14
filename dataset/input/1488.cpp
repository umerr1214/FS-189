#include <iostream>

class Logger {
private: // Semantic error: Constructor is private
    Logger() {
        std::cout << "Logger initialized." << std::endl;
    }

public:
    ~Logger() {
        std::cout << "Logger destroyed." << std::endl;
    }
    
    // A factory method would be needed to create Logger objects if constructor is private
    static Logger createLogger() {
        return Logger(); // This would call the private constructor from within the class
    }
};

int main() {
    // Attempting to instantiate Logger directly, but its constructor is private
    Logger myLogger; 
    return 0;
}