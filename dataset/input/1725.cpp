#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr
#include <stdexcept> // For custom exceptions

// Base Logger class
class Logger {
public:
    // Virtual destructor is crucial for proper polymorphic cleanup
    virtual ~Logger() = default;
    // Log method takes message by const reference for efficiency
    virtual void log(const std::string& message) const = 0;
};

// Derived ConsoleLogger class
class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) const override {
        std::cout << "[INFO] [Console] " << message << std::endl;
    }
};

// Custom exception for file logger errors
class FileLoggerError : public std::runtime_error {
public:
    explicit FileLoggerError(const std::string& message)
        : std::runtime_error("FileLogger Error: " + message) {}
};

// Derived FileLogger class - Correct Version: Uses RAII, proper error handling, efficient.
class FileLogger : public Logger {
private:
    std::string filename;
    std::ofstream outFile; // Uses RAII: file opened in constructor, closed in destructor

public:
    // Constructor: Opens file and checks for errors
    FileLogger(const std::string& fname) : filename(fname) {
        outFile.open(filename, std::ios::app);
        if (!outFile.is_open()) {
            throw FileLoggerError("Failed to open log file: " + filename);
        }
        outFile << "--- Log Session Started ---" << std::endl; // Initial log entry
    }

    // Destructor: Automatically closes file via RAII (outFile's destructor)
    ~FileLogger() override {
        if (outFile.is_open()) {
            outFile << "--- Log Session Ended ---" << std::endl;
            // outFile.close() will be called automatically by std::ofstream's destructor
        }
    }

    // Log method: Writes to file, checks for write errors
    void log(const std::string& message) const override {
        if (outFile.is_open()) {
            outFile << "[INFO] [File] " << message << std::endl;
            if (!outFile) { // Check for write errors
                // This const_cast is generally not ideal, but for error handling in a const method,
                // and assuming the underlying stream state can be reset, it's sometimes used.
                // A better design might involve making log non-const if it modifies stream state for error handling,
                // or returning an error status. For simplicity and to fit `const` on `log`, we log to cerr.
                std::cerr << "ERROR: Failed to write to file '" << filename << "' for message: " << message << std::endl;
                // Optionally, clear error flags to allow further writes if the error was transient
                // const_cast<std::ofstream&>(outFile).clear();
            }
        } else {
            std::cerr << "ERROR: File '" << filename << "' is not open. Cannot log message: " << message << std::endl;
        }
    }
};

// Function to process logs, takes vector of unique_ptr by const reference
void processLogs(const std::vector<std::unique_ptr<Logger>>& loggers, const std::string& msg) {
    for (const auto& logger : loggers) {
        logger->log(msg);
    }
}

int main() {
    // Clean up previous log file for consistent testing
    std::remove("log_correct.txt");

    std::vector<std::unique_ptr<Logger>> loggers;

    try {
        loggers.push_back(std::make_unique<ConsoleLogger>());
        loggers.push_back(std::make_unique<FileLogger>("log_correct.txt"));

        processLogs(loggers, "Application initialized successfully.");
        processLogs(loggers, "User 'admin' logged in.");
        processLogs(loggers, "Data backup started.");
        processLogs(loggers, "Data backup completed with 100 files.");

    } catch (const FileLoggerError& e) {
        std::cerr << "Critical Error: " << e.what() << std::endl;
        return 1; // Indicate failure
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nLogging complete. Check console output and 'log_correct.txt' for file logs." << std::endl;

    return 0;
}