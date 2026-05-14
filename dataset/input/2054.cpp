#include <iostream>
// No iomanip for this one, as we're demonstrating a less efficient/readable way

class Timer {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor - Normalizes input to keep time valid (correctness is high)
    Timer(int h, int m, int s) {
        // Normalize seconds
        seconds = s % 60;
        int carryMinutes = s / 60;
        if (seconds < 0) { // Handle negative seconds
            seconds += 60;
            carryMinutes--;
        }

        // Normalize minutes
        minutes = (m + carryMinutes) % 60;
        int carryHours = (m + carryMinutes) / 60;
        if (minutes < 0) { // Handle negative minutes
            minutes += 60;
            carryHours--;
        }

        // Normalize hours
        hours = (h + carryHours) % 24;
        if (hours < 0) { // Handle negative hours
            hours += 24;
        }
    }

    // Displays the time in HH:MM:SS format - Less readable/efficient implementation
    void displayTime() const {
        // Manual leading zero handling, which is less readable and potentially less efficient
        // than using std::setw and std::setfill.
        if (hours < 10) {
            std::cout << "0";
        }
        std::cout << hours << ":";

        if (minutes < 10) {
            std::cout << "0";
        }
        std::cout << minutes << ":";

        if (seconds < 10) {
            std::cout << "0";
        }
        std::cout << seconds << std::endl;
    }
};

int main() {
    // Test cases for Readability / Efficiency Issue
    // The outputs will be correct, but the internal implementation of displayTime is suboptimal.
    Timer t1(10, 30, 45);
    Timer t2(2, 5, 8);
    Timer t3(23, 59, 59);
    Timer t4(0, 0, 0);
    Timer t5(25, 65, 70); // Should normalize to 02:06:10
    Timer t6(-1, -1, -1); // Should normalize to 22:58:59

    std::cout << "Timer 1 (10:30:45): ";
    t1.displayTime();

    std::cout << "Timer 2 (02:05:08): ";
    t2.displayTime();

    std::cout << "Timer 3 (23:59:59): ";
    t3.displayTime();

    std::cout << "Timer 4 (00:00:00): ";
    t4.displayTime();

    std::cout << "Timer 5 (25h 65m 70s -> 02:06:10): ";
    t5.displayTime();

    std::cout << "Timer 6 (-1h -1m -1s -> 22:58:59): ";
    t6.displayTime();

    return 0;
}