#include <iostream>
#include <atomic> // For thread-safe counter

class Logger {
public:
    Logger() {
        // Increment logCount atomically to ensure thread-safety.
        // `fetch_add(1)` is an atomic operation that safely increments
        // the counter even in multi-threaded environments, preventing race conditions.
        logCount.fetch_add(1);
    }

    ~Logger() {
        // Decrement logCount atomically.
        // `fetch_sub(1)` is an atomic operation.
        // No need for a `if (logCount > 0)` check as a correctly managed counter
        // should not go below zero if only incremented in constructors and decremented in destructors.
        logCount.fetch_sub(1);
    }

    static int getTotalLogs() {
        // Atomically load the current value of logCount.
        // `load()` ensures a consistent read, even if other threads are concurrently modifying it.
        return logCount.load();
    }

private:
    // Use std::atomic for `logCount` to make it thread-safe.
    // This addresses the robustness issue of concurrent access.
    static std::atomic<int> logCount;
};

// Initialize static atomic member outside the class definition.
// std::atomic variables must be initialized.
std::atomic<int> Logger::logCount(0);

int main() {
    std::cout << "Initial log count: " << Logger::getTotalLogs() << std::endl;

    {
        Logger log1;
        std::cout << "After log1 creation: " << Logger::getTotalLogs() << std::endl;
        Logger log2;
        std::cout << "After log2 creation: " << Logger::getTotalLogs() << std::endl;
    } // log1 and log2 are destroyed here, decrementing logCount
    std::cout << "After log1 and log2 destruction: " << Logger::getTotalLogs() << std::endl;

    Logger log3;
    std::cout << "After log3 creation: " << Logger::getTotalLogs() << std::endl;

    Logger* logPtr = new Logger(); // Create a logger on the heap
    std::cout << "After logPtr creation: " << Logger::getTotalLogs() << std::endl;
    delete logPtr; // Manually destroy the logger, decrementing logCount
    std::cout << "After logPtr destruction: " << Logger::getTotalLogs() << std::endl;

    return 0;
}