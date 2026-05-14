#include <iostream>

class Logger {
private:
    static int logCount;
public:
    Logger() {
        logCount++; // Correctly increments logCount
    }

    static void displayTotalLogs() {
        // Logical Error: Always prints a fixed value instead of the actual logCount
        std::cout << "Total logs: 10" << std::endl;
    }
};

// Definition and initialization of static member
int Logger::logCount = 0;

int main() {
    Logger l1;
    Logger l2;
    Logger l3;
    Logger::displayTotalLogs(); // This will output "Total logs: 10"
    return 0;
}