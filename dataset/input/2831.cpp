#include <fstream>
#include <string>
#include <iostream>
#include <cstdio> // For std::remove

class Logger {
public:
    // Constructor: Opens the specified log file in append mode.
    Logger(const std::string& filename) : logFilename(filename) {
        outFile.open(logFilename, std::ios::app);
        if (!outFile.is_open()) {
            std::cerr << "Error: Could not open log file " << logFilename << std::endl;
        }
    }

    // Destructor: Closes the log file.
    ~Logger() {
        if (outFile.is_open()) {
            outFile.close();
        }
    }

    // Logs a message to the file.
    // LOGICAL ERROR: This method always logs a fixed string instead of the actual message.
    void logMessage(const std::string& message) {
        if (outFile.is_open()) {
            outFile << "LOGGED MESSAGE\n"; // Should be 'outFile << message << std::endl;'
        } else {
            std::cerr << "Error: Log file is not open. Message not logged." << std::endl;
        }
    }

private:
    std::ofstream outFile;
    std::string logFilename;
};

int main() {
    std::string test_file = "test_log_2831.txt";

    // Clean up any previous test file
    std::remove(test_file.c_str());

    Logger logger(test_file);
    logger.logMessage("Application started.");
    logger.logMessage("Processing data...");
    logger.logMessage("Application finished.");

    std::cout << "Messages logged. Reading file content:" << std::endl;

    std::ifstream inFile(test_file);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Error: Log file could not be opened for reading." << std::endl;
    }
    std::remove(test_file.c_str());
    return 0;
}