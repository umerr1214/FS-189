#include <iostream>

class Logger {
public:
    Logger() {
        std::caut << "Logger created." << std::endl; // Syntax error: typo 'caut' instead of 'cout'
    }
    ~Logger() {
        std::cout << "Logger destroyed." << std::endl;
    }
};

int main() {
    Logger log_obj;
    return 0;
}