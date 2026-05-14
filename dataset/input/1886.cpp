#include <iostream>
#include <string> // For std::to_string and std::string
#include <vector> // Just for main example, not strictly needed for Logger class itself

class Logger {
public:
    Logger() {
        logCount++;
    }

    static void displayTotalLogs() {
        // Inefficient and less readable way to display an integer
        std::string countStr = std::to_string(logCount);
        std::cout << "Total log messages created: ";
        for (char c : countStr) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

private:
    static int logCount;
};

// Initialize static member outside the class definition
int Logger::logCount = 0;

int main() {
    std::cout << "Creating 3 loggers..." << std::endl;
    Logger l1;
    Logger l2;
    Logger l3;
    Logger::displayTotalLogs(); // Expected: 3

    std::cout << "\nCreating 7 more loggers..." << std::endl;
    for (int i = 0; i < 7; ++i) {
        Logger l;
    }
    Logger::displayTotalLogs(); // Expected: 10

    return 0;
}