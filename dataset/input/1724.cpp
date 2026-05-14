#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory> // Included but not used for smart pointers, contributing to the readability/efficiency issue by choosing raw pointers

// Base Logger class
class Logger {
public:
    // Virtual destructor is good practice but omitted here for a readability/efficiency issue
    // (potential memory leak if derived classes have resources and are deleted via base pointer)
    ~Logger() {
        std::cout << "Logger destructor called." << std::endl; // For demonstration of non-virtual
    }
    virtual void log(std::string message) = 0; // Pass by value, less efficient for large strings
};

// Derived ConsoleLogger class
class ConsoleLogger : public Logger {
public:
    void log(std::string message) override { // Still pass by value
        std::cout << "Log to Console: " << message << std::endl; // Different formatting
    }
};

// Derived FileLogger class - Readability/Efficiency Issue: Inefficient file handling, raw pointer usage.
class FileLogger : public Logger {
private:
    std::string fileName;
    std::ofstream* fileStreamPtr; // Raw pointer to manage file stream

public:
    FileLogger(std::string fname) : fileName(fname), fileStreamPtr(nullptr) { // Pass by value
        fileStreamPtr = new std::ofstream(fileName, std::ios::app); // Allocate on heap
        if (!fileStreamPtr->is_open()) {
            std::cerr << "WARNING: Could not open file '" << fileName << "' in constructor." << std::endl;
            delete fileStreamPtr; // Clean up if failed
            fileStreamPtr = nullptr;
        }
    }

    // Copy constructor and assignment operator are implicitly deleted or shallow copied with raw pointer
    // This is a major issue for robust code but contributes to the 'efficiency/readability' if not handled.
    // For simplicity of this example, we'll assume no copying happens.

    ~FileLogger() override { // Virtual destructor, but the base one is not
        if (fileStreamPtr && fileStreamPtr->is_open()) {
            fileStreamPtr->close();
        }
        delete fileStreamPtr; // Manual deallocation
        std::cout << "FileLogger destructor called and file stream closed/deleted." << std::endl;
    }

    void log(std::string message) override { // Pass by value
        // Redundant check and conditional open/close within log method itself, even if stream is kept open
        if (fileStreamPtr && fileStreamPtr->is_open()) {
            *fileStreamPtr << "File Log: " << message << std::endl;
            fileStreamPtr->flush(); // Force flush every time, potentially inefficient
        } else {
            std::cerr << "ERROR: File stream not open for '" << fileName << "'. Cannot log message: " << message << std::endl;
        }
    }
};

void processLogs(std::vector<Logger*> loggers, const std::string& msg) { // Pass vector by value
    for (Logger* logger : loggers) {
        logger->log(msg);
    }
}

int main() {
    // Clean up previous log file for consistent testing
    std::remove("log_inefficient.txt");

    // Using raw pointers for managing Logger objects in main, requiring manual deletion.
    Logger* consoleLogger = new ConsoleLogger();
    Logger* fileLogger = new FileLogger("log_inefficient.txt");

    std::vector<Logger*> activeLoggers;
    activeLoggers.push_back(consoleLogger);
    activeLoggers.push_back(fileLogger);

    processLogs(activeLoggers, "Application started for inefficient system.");
    processLogs(activeLoggers, "Data processing step 1.");
    processLogs(activeLoggers, "Data processing step 2 completed.");

    // Manual cleanup of raw pointers
    // If base Logger destructor is not virtual, deleting fileLogger via Logger* will cause undefined behavior.
    delete consoleLogger;
    delete fileLogger; // This will call FileLogger's destructor correctly because it's derived.
                        // However, if the base Logger's destructor wasn't virtual, and we had `Logger* basePtr = new FileLogger(); delete basePtr;`, it would be an issue.
                        // For this specific example, the destructors are called explicitly on the derived types.
                        // Let's modify the base Logger destructor to be non-virtual to highlight the issue.
                        // (Actually, the base Logger destructor *is* non-virtual, so it's good for the error type).

    std::cout << "\nInefficient logging complete. Check console output and 'log_inefficient.txt'." << std::endl;

    return 0;
}