#include <iostream>
#include <vector>
#include <thread>
#include <chrono> // Not strictly needed, but often used with threads

class Logger {
public:
    Logger() {
        // This increment is not thread-safe and can lead to a race condition
        logCount++; 
    }

    static void displayTotalLogs() {
        std::cout << "Total log messages created: " << logCount << std::endl;
    }

private:
    static int logCount;
};

// Initialize static member outside the class definition
int Logger::logCount = 0;

// Function to be executed by threads
void createLoggersInThread(int num_logs) {
    for (int i = 0; i < num_logs; ++i) {
        Logger l; // Creates a Logger object, increments logCount
    }
}

int main() {
    // --- Single-threaded test to verify basic functionality ---
    std::cout << "--- Single-threaded test ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Logger l;
    }
    Logger::displayTotalLogs(); // Expected: Total log messages created: 5

    // Reset logCount for the multi-threaded test
    // In a real application, resetting a static counter like this would need protection too.
    Logger::logCount = 0; 
    std::cout << "\n--- Multi-threaded test (demonstrating robustness issue) ---" << std::endl;

    const int num_threads = 10;
    const int logs_per_thread = 1000;
    std::vector<std::thread> threads;

    // Create and launch threads
    for (int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(createLoggersInThread, logs_per_thread));
    }

    // Join threads to ensure all operations are complete
    for (std::thread& t : threads) {
        t.join();
    }

    // Display the final count. Due to the race condition, this will likely be incorrect.
    Logger::displayTotalLogs(); 
    std::cout << "Expected total if correct: " << num_threads * logs_per_thread << std::endl;

    return 0;
}