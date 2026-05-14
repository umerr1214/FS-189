#include <iostream>

class Logger {
public:
    static int logCount;

    Logger() {
        logCount++;
    }

    ~Logger() {
        // As per question, decrement if applicable.
        // For 'total ever created', it's usually not decremented.
        // But following the prompt's contradictory instruction for this example.
        if (logCount > 0) {
            logCount--;
        }
    }

    static int getTotalLogs() {
        return logCount;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

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