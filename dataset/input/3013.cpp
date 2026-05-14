#include <iostream>
#include <memory> // For std::unique_ptr, though not used for the error

class Logger {
public:
    Logger() {
        std::cout << "Logger initialized\n";
    }

    ~Logger() {
        std::cout << "Logger destroyed\n";
    }

    void logMessage(const std::string& msg) {
        std::cout << "Log: " << msg << "\n";
    }
};

void createAndDestroyScopedLogger() {
    std::cout << "Entering createAndDestroyScopedLogger function...\n";
    Logger functionLogger; // This logger will be destroyed when function exits
    functionLogger.logMessage("Inside function scope.");
    std::cout << "Exiting createAndDestroyScopedLogger function...\n";
}

int main() {
    std::cout << "Main function started.\n";

    // Demonstrating automatic destruction for stack-allocated objects
    {
        std::cout << "Entering inner block 1...\n";
        Logger blockLogger; // This logger will be destroyed when block 1 exits
        blockLogger.logMessage("Inside inner block 1.");
        std::cout << "Exiting inner block 1...\n";
    } // blockLogger is destroyed here

    createAndDestroyScopedLogger();

    // Robustness Issue: Dynamically allocating a Logger object but forgetting to delete it.
    // This demonstrates a memory leak, as the destructor for this object will not be called
    // automatically, bypassing the intended RAII demonstration for dynamically allocated objects.
    std::cout << "Creating a dynamically allocated Logger (memory leak intended for demonstration)...\n";
    Logger* heapLogger = new Logger(); // Object created on heap
    heapLogger->logMessage("This logger is on the heap and will leak.");
    // No 'delete heapLogger;' here, leading to a memory leak and the destructor not being called.

    std::cout << "Main function finished.\n";
    return 0;
} // blockLogger (if any) and functionLogger (if any) are destroyed here. heapLogger is NOT.