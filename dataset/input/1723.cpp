#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept> // Although not used for error handling in this version

// Base Logger class
class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& message) = 0;
};

// Derived ConsoleLogger class
class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "[CONSOLE] " << message << std::endl;
    }
};

// Derived FileLogger class - Robustness Issue: Lacks proper error handling for file operations.
// Opens and closes the file for every log, which is inefficient and can lead to issues.
class FileLogger : public Logger {
private:
    std::string filename;

public:
    FileLogger(const std::string& fname) : filename(fname) {
        // No error checking during construction if file path is valid or writable.
        // The file is not kept open, leading to repeated open/close operations.
    }

    void log(const std::string& message) override {
        std::ofstream outFile(filename, std::ios::app); // Opens file
        if (outFile.is_open()) {
            outFile << "[FILE] " << message << std::endl;
            // No check for write errors
            outFile.close(); // Closes file
        } else {
            // No explicit error message or handling if file fails to open.
            // The message is just silently dropped.
            std::cerr << "ERROR: Could not open file '" << filename << "' for logging." << std::endl;
        }
    }
};

int main() {
    // Clean up previous log file for consistent testing
    std::remove("log_robust.txt");

    ConsoleLogger consoleLogger;
    FileLogger fileLogger("log_robust.txt");

    std::vector<Logger*> loggers;
    loggers.push_back(&consoleLogger);
    loggers.push_back(&fileLogger);

    for (Logger* logger : loggers) {
        logger->log("Application started.");
        logger->log("Processing data item 123.");
    }

    // Demonstrate a case where file logging might silently fail (e.g., if path was invalid)
    // For this simple example, we can't easily simulate an invalid path that `ofstream` would fail on
    // without OS-specific tricks or permissions issues. The issue here is the LACK of explicit handling.
    // However, if the file cannot be opened for any reason, the message will be lost, and only a silent
    // error message to cerr is printed, but the program continues without explicit action.

    // Try logging to a non-existent directory (this won't create it and will fail silently)
    // FileLogger badFileLogger("non_existent_dir/log_robust_bad.txt");
    // badFileLogger.log("Attempting to log to a bad path."); // This log will likely fail silently

    std::cout << "\nLogging complete. Check console output and 'log_robust.txt' for file logs." << std::endl;

    return 0;
}