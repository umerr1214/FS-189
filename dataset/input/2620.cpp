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

    // Constructor 3: Hours, minutes, seconds
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        if (hours < 0 || hours > 23) hours = 0;
        if (minutes < 0 || minutes > 59) minutes = 0;
        if (seconds < 0 || seconds > 59) seconds = 0;
    }

    void display() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Time t1;
    std::cout << "Default Time: ";
    t1.display();

    Time t2(10);
    std::cout << "Time with hours: ";
    t2.display();

    Time t3(23, 59, 59);
    std::cout << "Full Time: ";
    t3.display();

    Time t4(25, 65, -10); // Test invalid values
    std::cout << "Invalid Time: ";
    t4.display();

    return 0;
}