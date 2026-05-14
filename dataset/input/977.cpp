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

    // Parameterized constructor - LOGICAL ERROR HERE
    // Intended: hours(h), minutes(m), seconds(s)
    // Actual: Scrambles the values
    Time(int h, int m, int s) : hours(m), minutes(s), seconds(h) {} // Logical error: incorrect assignment

    // Copy constructor
    Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {}

    // Display method
    void displayTime() {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
};

int main() {
    std::cout << "Testing Time class:" << std::endl;

    // Test default constructor
    Time t1;
    std::cout << "Default time: ";
    t1.displayTime(); // Expected: 00:00:00

    // Test parameterized constructor
    Time t2(10, 20, 30); // Input: h=10, m=20, s=30
    std::cout << "Parameterized time (10:20:30): ";
    t2.displayTime(); // Expected: 10:20:30, Actual (with error): 20:30:10

    // Test copy constructor
    Time t3 = t2;
    std::cout << "Copied time (from 10:20:30): ";
    t3.displayTime(); // Expected: 10:20:30, Actual (with error): 20:30:10

    Time t4(23, 59, 59); // Input: h=23, m=59, s=59
    std::cout << "Parameterized time (23:59:59): ";
    t4.displayTime(); // Expected: 23:59:59, Actual (with error): 59:59:23

    return 0;
}