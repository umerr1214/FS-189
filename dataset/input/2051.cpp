#include <iostream>
// #include <iomanip> // This header is intentionally omitted/unused to demonstrate the logical error

class Timer {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor to initialize time
    Timer(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Public method to display time
    void displayTime() {
        // LOGICAL ERROR: Does not pad single-digit numbers with a leading '0'.
        // For example, 1 hour will be printed as '1' instead of '01'.
        std::cout << hours << ":"
                  << minutes << ":"
                  << seconds;
    }
};

int main() {
    Timer t1(10, 5, 30);
    std::cout << "Timer 1: ";
    t1.displayTime(); // Expected: 10:05:30, Actual: 10:5:30
    std::cout << std::endl;

    Timer t2(0, 0, 0);
    std::cout << "Timer 2: ";
    t2.displayTime(); // Expected: 00:00:00, Actual: 0:0:0
    std::cout << std::endl;

    Timer t3(23, 59, 59);
    std::cout << "Timer 3: ";
    t3.displayTime(); // Expected: 23:59:59, Actual: 23:59:59 (Correct by coincidence)
    std::cout << std::endl;

    Timer t4(1, 2, 3);
    std::cout << "Timer 4: ";
    t4.displayTime(); // Expected: 01:02:03, Actual: 1:2:3
    std::cout << std::endl;

    return 0;
}