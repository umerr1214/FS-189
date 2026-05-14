#include <iostream>
#include <string>
#include <thread> // For multi-threading simulation
#include <vector>
#include <chrono> // For std::this_thread::sleep_for

// Logger class definition
class Logger {
public:
    // Method to log a message and increment the counter
    // This method has a robustness issue: it's not thread-safe.
    // If multiple threads call this simultaneously, messageCount can be incorrect due to race conditions.
    void logMessage(std::string message) {
        // In a real logger, this would typically write the message to a file or console.
        // For this problem, we focus on the counter logic.
        messageCount++; // This increment is not atomic/protected, leading to a race condition
        // std::cout << "Logged: " << message << " (Current count: " << messageCount << ")" << std::endl; // For debugging
    }

    // Static method to get the total number of messages
    static int getTotalMessages() {
        return messageCount;
    }

private:
    static int messageCount; // Static member declaration
};

// Static member definition (must be outside the class definition)
int Logger::messageCount = 0;

// Worker function for threads to simulate concurrent logging
void thread_logger_worker(Logger& logger_instance, int messages_per_thread, int thread_id) {
    for (int i = 0; i < messages_per_per_thread; ++i) {
        logger_instance.logMessage("Thread " + std::to_string(thread_id) + " message " + std::to_string(i));
        // Adding a small sleep can sometimes make race conditions more apparent
        // std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
}

int main() {
    Logger logger; // Create a logger instance (not strictly necessary for static members, but common usage)

    const int num_threads = 5;
    const int messages_per_thread = 10000;
    const int expected_total_messages = num_threads * messages_per_thread;

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(thread_logger_worker, std::ref(logger), messages_per_thread, i);
    }

    for (std::thread& t : threads) {
        t.join();
    }

    int final_count = Logger::getTotalMessages();
    std::cout << "Expected total messages: " << expected_total_messages << std::endl;
    std::cout << "Actual total messages: " << final_count << std::endl;

    // The output will likely be less than expected due to race conditions.
    if (final_count != expected_total_messages) {
        std::cout << "Error: Message count is incorrect due to race conditions." << std::endl;
        return 1; // Indicate failure
    } else {
        std::cout << "Success: Message count matches expected (this might be rare due to race conditions)." << std::endl;
        return 0; // Indicate success (though it's a false positive if race condition actually occurred but result happened to be correct)
    }
}