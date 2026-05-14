#include <iostream>
#include <iomanip> // For std::setw and std::setfill

class Timer {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor - Lacks input validation, leading to robustness issues
    Timer(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Displays the time in HH:MM:SS format
    void displayTime() const {
        // This method assumes the stored values are valid, which they might not be
        // due to the constructor's lack of validation.
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
};

int main() {
    // Test cases for Robustness Issue
    // The driver will demonstrate the issue by passing invalid time values
    // and showing that they are stored and displayed as is.
    Timer t1(10, 30, 45); // Valid time
    Timer t2(25, 15, 0);  // Invalid hour: 25
    Timer t3(12, 70, 5);  // Invalid minute: 70
    Timer t4(1, 2, 90);   // Invalid second: 90
    Timer t5(-5, 10, 20); // Negative hour: -5

    std::cout << "Timer 1 (10:30:45): ";
    t1.displayTime();

    std::cout << "Timer 2 (25:15:00): ";
    t2.displayTime();

    std::cout << "Timer 3 (12:70:05): ";
    t3.displayTime();

    std::cout << "Timer 4 (01:02:90): ";
    t4.displayTime();

    std::cout << "Timer 5 (-05:10:20): ";
    t5.displayTime();

    return 0;
}