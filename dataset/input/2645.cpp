#include <iostream>

class Logger {
public:
    static int logCount;

    Logger() {
        logCount++; // Correct: Increments for every object created
    }

    ~Logger() {
        // LOGICAL ERROR: The question asks for 'total number of Logger objects *ever created*'.
        // Decrementing in the destructor causes logCount to track *active* objects,
        // not the total number ever created. If it's 'total ever created', it should not decrement.
        if (logCount > 0) { // Condition is fine, but the action itself is logically incorrect for 'total ever created'
            logCount--;
        }
    }

    static int getTotalLogs() {
        return logCount;
    }
};

int Logger::logCount = 0;

int main() {
    std::cout << "Initial log count: " << Logger::getTotalLogs() << std::endl;
    Logger l1;
    std::cout << "After l1 creation: " << Logger::getTotalLogs() << std::endl;
    {
        Logger l2;
        std::cout << "After l2 creation: " << Logger::getTotalLogs() << std::endl;
    } // l2 goes out of scope, destructor called
    std::cout << "After l2 destruction: " << Logger::getTotalLogs() << std::endl;
    Logger l3;
    std::cout << "After l3 creation: " << Logger::getTotalLogs() << std::endl;
    return 0;
}