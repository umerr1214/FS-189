#include <iostream>

class Logger {
public:
    static int logCount;

    Logger() {
        logCount++;
    }

    ~Logger() {
        // SEMANTIC ERROR: The condition for 'applicable' is arbitrary and semantically meaningless
        // for tracking object lifetime or total objects created. It compiles, but its logic
        // does not serve the intended purpose of decrementing based on object destruction.
        if (logCount % 2 == 0) { // This condition is nonsensical for 'decrement if applicable'
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