#include <iostream>
#include <thread>
#include <vector>
#include <chrono> // For std::this_thread::sleep_for

class Logger {
public:
    Logger() {
        // Robustness Issue:
        // Incrementing a simple `int` static member is not thread-safe.
        // In a multi-threaded environment, this read-modify-write operation
        // can lead to race conditions and incorrect counts if multiple threads
        // try to modify `logCount` concurrently.
        logCount++;
    }

    ~Logger() {
        // Robustness Issue:
        // Decrementing is also not thread-safe for the same reasons.
        logCount--;
    }

    static int getTotalLogs() {
        // Robustness Issue:
        // Reading `logCount` while it's being modified by other threads
        // can also lead to inconsistent or torn reads.
        return logCount;
    }

private:
    static int logCount;
};

// Initialize static member
int Logger::logCount = 0;

// Function to be run by threads to demonstrate the issue
void create_and_destroy_loggers(int num_loggers) {
    for (int i = 0; i < num_loggers; ++i) {
        Logger l; // Constructor increments, destructor decrements
        // A small sleep can increase the likelihood of a race condition
        // std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
}

int main() {
    // --- Basic functionality check (single-threaded) ---
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

    // --- Robustness Issue Demonstration (Multi-threaded) ---
    std::cout << "\n--- Multi-Threaded Test (Demonstrating Robustness Issue) ---" << std::endl;
    int num_threads = 4;
    int loggers_per_thread = 10000; // Create and destroy many loggers per thread

    std::cout << "Starting multi-threaded logger creation/destruction. Expected final count: 0" << std::endl;
    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(create_and_destroy_loggers, loggers_per_thread);
    }

    for (auto& t : threads) {
        t.join();
    }

    // The actual final log count is highly likely to be incorrect (not 0)
    // due to race conditions on the non-atomic `logCount`.
    std::cout << "Actual final log count after multi-threaded operations: " << Logger::getTotalLogs() << std::endl;

    return 0;
}