#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> // For reading file content
#include <chrono>  // For unique filename
#include <cstdio>  // For std::remove

// Robustness Issue:
// - The constructor does not check if the log file was successfully opened.
// - The logMessage method does not check the stream's state before writing.
//   This means if the file fails to open, subsequent logMessage calls will
//   attempt to write to a bad stream, leading to silent failures or undefined behavior.
class Logger {
public:
    Logger(const std::string& filename) : _filename(filename) {
        _logFile.open(_filename, std::ios::app); // Opens the file
        // CRITICAL ROBUSTNESS FLAW: No check for _logFile.is_open() here.
        // If file opening fails (e.g., bad path, permissions), the object
        // is in a bad state but continues as if successful.
    }

    ~Logger() {
        if (_logFile.is_open()) {
            _logFile.close();
        }
    }

    void logMessage(const std::string& message) {
        // CRITICAL ROBUSTNESS FLAW: No check for _logFile.is_open() or _logFile.good() here.
        // If the file was never opened successfully or encountered an error later,
        // this write operation will fail silently or cause undefined behavior.
        _logFile << message << '\n';
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