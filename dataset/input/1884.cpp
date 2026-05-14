#include <iostream>

class Logger {
private:
    static int logCount;
public:
    Logger() {
        logCount++;
    }

    static void displayTotalLogs() {
        std::cout << "Total logs: " << logCount << std::endl;
    }
};

// Definition and initialization of static member
int Logger::logCount = 0;

int main() {
    Logger l1;
    Logger l2;
    Logger l3;
    // Semantic Error: Attempting to access a private static member directly from main
    std::cout << "Current logs (attempted direct access): " << Logger::logCount << std::endl;
    Logger::displayTotalLogs(); 
    return 0;
}