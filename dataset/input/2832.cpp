#include <fstream>
#include <string>
#include <iostream>
#include <cstdio> // For std::remove

class Logger {
public:
    // Constructor: Opens the specified log file in append mode.
    // SEMANTIC ERROR: Constructor does not check if the file opened successfully.
    Logger(const std::string& filename) : logFilename(filename) {
        outFile.open(logFilename, std::ios::app);
        // Missing check: if (!outFile.is_open()) { ... error handling ... }
        // This means subsequent calls to logMessage might silently fail if file opening failed.
    }

    // Destructor: Closes the log file.
    ~Logger() {
        if (outFile.is_open()) {
            outFile.close();
        }
    }

    // Logs a message to the file.
    // SEMANTIC ERROR: This method does not check if the file stream is valid before writing.
    void logMessage(const std::string& message) {
        // Missing check: if (outFile.is_open()) { ... }
        // If outFile failed to open in the constructor, this write operation will silently fail.
        outFile << message << std::endl;
    }

private:
    std::ofstream outFile;
    std::string logFilename;
};

int main() {
    std::string valid_file = "test_log_2832_valid.txt";
    std::string invalid_file = "/nonexistent_dir/test_log_2832_invalid.txt"; // Path likely to fail

    // Clean up any previous test files
    std::remove(valid_file.c_str());
    std::remove(invalid_file.c_str());

    std::cout << "--- Testing with valid file path ---" << std::endl;
    Logger validLogger(valid_file);
    validLogger.logMessage("This message should be logged.");
    validLogger.logMessage("Another valid message.");

    std::cout << "\n--- Testing with invalid file path ---" << std::endl;
    Logger invalidLogger(invalid_file); // This will likely fail to open silently
    invalidLogger.logMessage("This message will likely fail to log silently.");
    invalidLogger.logMessage("And this one too.");

    std::cout << "\n--- Reading valid log file content ---" << std::endl;
    std::ifstream validInFile(valid_file);
    if (validInFile.is_open()) {
        std::string line;
        while (std::getline(validInFile, line)) {
            std::cout << line << std::endl;
        }
        validInFile.close();
    } else {
        std::cerr << "Error: Valid log file could not be opened for reading." << std::endl;
    }
    std::remove(valid_file.c_str());

    std::cout << "\n--- Attempting to read invalid log file content (should be empty/non-existent) ---" << std::endl;
    std::ifstream invalidInFile(invalid_file);
    if (invalidInFile.is_open()) {
        std::string line;
        while (std::getline(invalidInFile, line)) {
            std::cout << line << std::endl;
        }
        invalidInFile.close();
        if (line.empty()) {
             std::cout << "Invalid log file was created but is empty (as expected due to silent failure)." << std::endl;
        }
    } else {
        std::cout << "Invalid log file was not created or could not be opened for reading (as expected due to silent failure)." << std::endl;
    }
    std::remove(invalid_file.c_str());

    return 0;
}