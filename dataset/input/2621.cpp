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

    // Constructor 2: Hours only
    Time(int h) : hours(h), minutes(0), seconds(0) {
        if (hours < 0 || hours > 23) hours = 0;
    }

    // Constructor 3: Hours, minutes, seconds - Logical Error: minutes and seconds swapped in initialization
    Time(int h, int m, int s) : hours(h), minutes(s), seconds(m) { // ERROR HERE: minutes(s), seconds(m)
        if (hours < 0 || hours > 23) hours = 0;
        // Validation applies to the values assigned, not the original parameters,
        // so `minutes` (which got `s`) and `seconds` (which got `m`) are validated.
        if (minutes < 0 || minutes > 59) minutes = 0;
        if (seconds < 0 || seconds > 59) seconds = 0;
    }

    void display() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
};

int main() {
    Time t1;
    std::cout << "Default Time: ";
    t1.display();

    Time t2(10);
    std::cout << "Time with hours: ";
    t2.display();

    Time t3(1, 2, 3); // Test case for swap
    std::cout << "Full Time (1,2,3): ";
    t3.display(); // Expected: 01:02:03, Actual: 01:03:02

    Time t4(23, 59, 59); // Test case for swap with max values (no visible error if m=s=59)
    std::cout << "Full Time (23,59,59): ";
    t4.display(); // Expected: 23:59:59, Actual: 23:59:59

    Time t5(25, 65, -10); // Test invalid values
    std::cout << "Invalid Time: ";
    t5.display(); // Expected: 00:00:00 (assuming correct clamping), Actual: 00:00:00 (due to internal clamping after swap)

    return 0;
}