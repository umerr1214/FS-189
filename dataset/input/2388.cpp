#include <iostream>

class Logger {
public:
    Logger() {
        std::cout << "Logger created." << std::endl;
    }
    ~Logger() {
        std::cout << "Logger destroyed." << std::endl;
    }
};

int main() {
    // Logger log_obj; // Semantic error: No Logger object is created, failing to demonstrate its usage.
    return 0;
}