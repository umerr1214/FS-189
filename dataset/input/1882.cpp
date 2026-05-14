#include <iostream>

class Logger {
private:
    static int logCount;
public:
    Logger() {
        logCount++;
    }

    static void displayTotalLogs() {
        // Syntax Error: Missing 'std::' for cout and endl
        cout << "Total logs: " << logCount << endl;
    }
};

// Definition and initialization of static member
int Logger::logCount = 0;

int main() {
    Logger l1;
    Logger l2;
    Logger l3;
    Logger::displayTotalLogs();
    return 0;
}