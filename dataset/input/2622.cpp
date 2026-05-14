#include <iostream>
#include <iomanip> // For std::setw and std::setfill

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor 1: Default
    Time() : hours(0), minutes(0), seconds(0) {}

    // Constructor 2: Hours only - Semantic Error: minutes and seconds are not initialized
    Time(int h) : hours(h) { // minutes and seconds are left uninitialized, will contain garbage values
        if (hours < 0 || hours > 23) hours = 0;
    }

    // Constructor 3: Hours, minutes, seconds
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        if (hours < 0 || hours > 23) hours = 0;
        if (minutes < 0 || minutes > 59) minutes = 0;
        if (seconds < 0 || seconds > 59) seconds = 0;
    }

    void display() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":" // Accessing uninitialized minutes (UB)
                  << std::setw(2) << std::setfill('0') << seconds << std::endl; // Accessing uninitialized seconds (UB)
    }
};

int main() {
    Time t1;
    std::cout << "Default Time: ";
    t1.display(); // Expected: 00:00:00

    Time t2(10); // Object created with the problematic constructor
    std::cout << "Time with hours (semantic error): ";
    t2.display(); // Expected: 10:00:00. Actual: 10:GARBAGE:GARBAGE (Undefined Behavior)

    Time t3(23, 59, 59);
    std::cout << "Full Time: ";
    t3.display(); // Expected: 23:59:59

    Time t4(25, 65, -10); // Test invalid values, handled by correct constructor
    std::cout << "Invalid Time: ";
    t4.display(); // Expected: 00:00:00

    return 0;
}