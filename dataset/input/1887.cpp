#include <iostream>
#include <vector>
#include <thread>
#include <mutex> // For thread safety
#include <chrono> // For sleep, optional for demo clarity

class Logger {
public:
    Logger() {
        // Protect increment with a mutex for thread safety
        std::lock_guard<std::mutex> lock(logMutex);
        logCount++; 
    }

    static void displayTotalLogs() {
        // Protect access with a mutex for thread safety
        std::lock_guard<std::mutex> lock(logMutex);
        std::cout << "Total log messages created: " << logCount << std::endl;
    }

private:
    static int logCount;
    static std::mutex logMutex; // Mutex for protecting logCount
};

// Initialize static members outside the class definition
int Logger::logCount = 0;
std::mutex Logger::logMutex;

// Function to be executed by threads
void createLoggersThreadSafe(int num_logs) {
    for (int i = 0; i < num_logs; ++i) {
        Logger l; // Creates a Logger object, increments logCount safely
    }
}

int main() {
    // --- Single-threaded test ---
    std::cout << "--- Single-threaded test ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Logger l;
    }
    Logger::displayTotalLogs(); // Expected: Total log messages created: 5

    // Reset logCount for the multi-threaded test (for demonstration purposes)
    // This reset itself is a modification of shared state and should be protected.
    {
        std::lock_guard<std::mutex> lock(Logger::logMutex);
        Logger::logCount = 0; 
    }
    std::cout << "\n--- Multi-threaded test (thread-safe) ---" << std::endl;

    const int num_threads = 10;
    const int logs_per_thread = 1000;
    std::vector<std::thread> threads;

    // Create and launch threads
    for (int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(createLoggersThreadSafe, logs_per_thread));
    }

    // Join threads to ensure all operations are complete
    for (std::thread& t : threads) {
        t.join();
    }

    // Display the final count. This should now be correct due to mutex.
    Logger::displayTotalLogs(); 
    std::cout << "Expected total: " << num_threads * logs_per_thread << std::endl;

    return 0;
}