#include <iostream>
#include <iomanip> // Required for std::setw and std::setfill

class Timer {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor to initialize time
    Timer(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Public method to display time in HH:MM:SS format
    void displayTime() {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Timer t1(10, 5, 30);
    std::cout << "Timer 1: ";
    t1.displayTime();
    std::cout << std::endl;

    Timer t2(0, 0, 0);
    std::cout << "Timer 2: ";
    t2.displayTime();
    std::cout << std::endl;

    Timer t3(23, 59, 59);
    std::cout << "Timer 3: ";
    t3.displayTime();
    std::cout << std::endl;

    Timer t4(1, 2, 3);
    std::cout << "Timer 4: ";
    t4.displayTime();
    std::cout << std::endl;

    return 0;
}