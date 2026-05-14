#include <iostream>
#include <iomanip> // For std::setw and std::setfill

class Timer {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor - Properly normalizes input values
    Timer(int h, int m, int s) {
        // Convert everything to seconds first for easier normalization
        long long totalSeconds = (long long)h * 3600 + (long long)m * 60 + s;

        // Ensure totalSeconds is non-negative before modulo for predictable behavior
        // If totalSeconds is negative, add multiples of 24*3600 until it's positive
        while (totalSeconds < 0) {
            totalSeconds += 24LL * 3600;
        }

        seconds = totalSeconds % 60;
        totalSeconds /= 60; // Remaining minutes

        minutes = totalSeconds % 60;
        totalSeconds /= 60; // Remaining hours

        hours = totalSeconds % 24; // Normalize hours to 0-23
    }

    // Displays the time in HH:MM:SS format using iomanip for readability and efficiency
    void displayTime() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
};

int main() {
    // Test cases for Correct Version
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