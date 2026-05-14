#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> // For reading file content
#include <chrono>  // For unique filename
#include <cstdio>  // For std::remove

// Readability / Efficiency Issue:
// - logMessage takes std::string by value, causing unnecessary copies.
// - logMessage uses std::endl, which flushes the stream on every write,
//   potentially impacting performance for high-volume logging.
class Logger {
public:
    Logger(const std::string& filename) : _filename(filename) {
        _logFile.open(_filename, std::ios::app);
        if (!_logFile.is_open()) {
            std::cerr << "Logger: Could not open log file: " << _filename << std::endl;
            // A correct version might throw or set a flag, but for this error type,
            // we're focusing on the logMessage method.
        }
    }

    ~Logger() {
        if (_logFile.is_open()) {
            _logFile.close();
        }
    }

    // Efficiency Issue: Takes std::string by value, causing a copy for every message.
    // Readability Issue: Could be const, but isn't. (Minor)
    void logMessage(std::string message) { // Pass by value
        if (_logFile.is_open()) {
            // Efficiency Issue: Uses std::endl, which flushes the buffer.
            // For frequent logging, '\n' is generally more efficient.
            _logFile << message << std::endl;
        } else {
            std::cerr << "Logger: Cannot log, file not open: " << message << std::endl;
        }
    }

private:
    std::string _filename;
    std::ofstream _logFile;
};

// Driver function to run test cases
std::string run_test(const std::vector<std::string>& messages, const std::string& filename) {
    // Ensure the file is clean before starting
    std::ofstream clear_file(filename, std::ios::trunc);
    clear_file.close();

    // Create Logger instance
    Logger logger(filename);

    // Log messages
    for (const std::string& msg : messages) {
        logger.logMessage(msg);
    }

    // Logger destructor called here as it goes out of scope

    // Read back the file content
    std::ifstream infile(filename);
    std::stringstream buffer;
    if (infile.is_open()) {
        buffer << infile.rdbuf();
        infile.close();
    } else {
        return "ERROR: Could not read log file: " + filename + "\n";
    }

    return buffer.str();
}

int main() {
    // Example test messages
    std::vector<std::string> test_messages = {
        "First log entry.",
        "Second log entry.",
        "A third message, perhaps longer than the others."
    };

    // Use a unique temporary filename for each run
    std::string temp_log_filename = "temp_log_" + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) + ".txt";

    // Run the test
    std::string actual_output = run_test(test_messages, temp_log_filename);

    // Print the actual output to stdout
    std::cout << actual_output;

    // Optional: clean up the file
    std::remove(temp_log_filename.c_str());

    return 0;
}