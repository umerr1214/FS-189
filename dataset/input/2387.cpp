#include <iostream>

class Logger {
public:
    Logger() {
        std::cout << "Logger destroyed." << std::endl; // Logical error: prints 'destroyed' on creation
    }
    ~Logger() {
        std::cout << "Logger created." << std::endl;   // Logical error: prints 'created' on destruction
    }
};

int main() {
    Logger log_obj;
    return 0;
}