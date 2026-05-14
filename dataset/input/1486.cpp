#include <iostream>

class Logger {
public:
    Logger() {
        std::cout << "Logger initialized." << std::endl;
    }

    ~Logger() {
        std::cout << "Logger destroyed." << std::endl;
    }
} // Missing semicolon here

int main() {
    Logger myLogger;
    return 0;
}