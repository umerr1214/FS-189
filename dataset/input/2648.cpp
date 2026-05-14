#include <iostream>

class Logger {
public:
    Logger() {
        logCount++;
    }

    ~Logger() {
        // Readability / Efficiency Issue:
        // The check `if (logCount > 0)` before decrementing is largely redundant and adds minor overhead.
        // In a correctly functioning program, `logCount` should only be incremented in constructors
        // and decremented in destructors, starting from 0. Therefore, `logCount` should never
        // be 0 or less when a valid `Logger` object's destructor is called.
        // This check can be omitted for cleaner, slightly more efficient code.
        if (logCount > 0) { // This condition is generally unnecessary
            logCount--;
        }
    }

    static int getTotalLogs() {
        return logCount;
    }

private:
    static int logCount;
};

// Initialize static member
int Logger::logCount = 0;

int main() {
    std::cout << "Initial log count: " << Logger::getTotalLogs() << std::endl;

    {
        Logger log1;
        std::cout << "After log1 creation: " << Logger::getTotalLogs() << std::endl;
        Logger log2;
        std::cout << "After log2 creation: " << Logger::getTotalLogs() << std::endl;
    } // log1 and log2 are destroyed here
    std::cout << "After log1 and log2 destruction: " << Logger::getTotalLogs() << std::endl;

    Logger log3;
    std::cout << "After log3 creation: " << Logger::getTotalLogs() << std::endl;

    Logger* logPtr = new Logger();
    std::cout << "After logPtr creation: " << Logger::getTotalLogs() << std::endl;
    delete logPtr; // Manual destruction
    std::cout << "After logPtr destruction: " << Logger::getTotalLogs() << std::endl;

    return 0;
}