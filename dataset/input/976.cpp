#include <iostream>
#include <iomanip> // For std::setw and std::setfill

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Time() : hours(0), minutes(0), seconds(0) {}

    // Parameterized constructor
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Copy constructor
    Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {}

    // Display method
    void displayTime() {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
}; // Missing semicolon here, causing a syntax error

int main() {
    std::cout << "Testing Time class:" << std::endl;

    // Test default constructor
    Time t1;
    std::cout << "Default time: ";
    t1.displayTime(); // Expected: 00:00:00

    // Test parameterized constructor
    Time t2(10, 20, 30);
    std::cout << "Parameterized time (10:20:30): ";
    t2.displayTime(); // Expected: 10:20:30

    // Test copy constructor
    Time t3 = t2;
    std::cout << "Copied time (from 10:20:30): ";
    t3.displayTime(); // Expected: 10:20:30

    Time t4(23, 59, 59);
    std::cout << "Parameterized time (23:59:59): ";
    t4.displayTime(); // Expected: 23:59:59

    return 0;
}