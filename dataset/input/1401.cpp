#include <iostream>
#include <string>
#include <atomic> // For thread-safe static counter
#include <thread> // For multi-threading test
#include <vector>
#include <chrono> // For std::this_thread::sleep_for

// Logger class definition
class Logger {
public:
    // Method to log a message and increment the counter
    // Uses const std::string& for efficiency and std::atomic for thread-safety.
    void logMessage(const std::string& message) {
        messageCount.fetch_add(1); // Atomically increments messageCount
        // std::cout << "Logged: " << message << std::endl; // For debugging
    }

    // Static method to get the total number of messages
    // Uses std::atomic for thread-safe reading.
    static int getTotalMessages() {
        return messageCount.load(); // Atomically loads the current value
    }

private:
    // Static atomic integer to ensure thread-safe tracking of messages
    static std::atomic<int> messageCount;
};

// Static member definition and initialization (must be outside the class definition)
std::atomic<int> Logger::messageCount(0);

// Worker function for threads to simulate concurrent logging
void thread_logger_worker_correct(Logger& logger_instance, int messages_per_thread, int thread_id) {
    for (int i = 0; i < messages_per_thread; ++i) {
        logger_instance.logMessage("Thread " + std::to_string(thread_id) + " message " + std::to_string(i));
        // std::this_thread::sleep_for(std::chrono::microseconds(1)); // Optional: simulate work
    }
}

int main() {
    Logger logger; // Create a logger instance

    const int num_threads = 5;
    const int messages_per_thread = 10000;
    const int expected_total_messages = num_threads * messages_per_thread;

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(thread_logger_worker_correct, std::ref(logger), messages_per_thread, i);
    }

    for (std::thread& t : threads) {
        t.join();
    }

    int final_count = Logger::getTotalMessages();
    std::cout << "Expected total messages: " << expected_total_messages << std::endl;
    std::cout << "Actual total messages: " << final_count << std::endl;

    if (final_count == expected_total_messages) {
        std::cout << "Test passed: Total messages count is correct and thread-safe." << std::endl;
        return 0;
    } else {
        std::cout << "Test failed: Total messages count is incorrect." << std::endl;
        return 1;
    }
}