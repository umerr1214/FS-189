#include <iostream>
#include <iomanip> // For std::setfill and std::setw

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Helper to normalize time values, handling carries and borrows correctly.
    // This logic is robust and correct.
    void normalize() {
        // Handle seconds overflow/underflow
        minutes += seconds / 60;
        seconds %= 60;
        if (seconds < 0) {
            seconds += 60;
            minutes--;
        }

        // Handle minutes overflow/underflow
        hours += minutes / 60;
        minutes %= 60;
        if (minutes < 0) {
            minutes += 60;
            hours--;
        }

        // Handle hours overflow/underflow (wrap around 24 hours)
        hours %= 24;
        if (hours < 0) {
            hours += 24;
        }
    }

public:
    // 1) No arguments (default to 00:00:00)
    Time() { // Readability/Efficiency: Not using initializer list
        hours = 0;
        minutes = 0;
        seconds = 0;
        // No call to normalize needed here, but the lack of delegation means
        // other constructors will duplicate initial assignment and normalization.
    }

    // 2) With only hours (minutes and seconds default to 0)
    Time(int h) { // Readability/Efficiency: Not using initializer list, no constructor delegation
        this->hours = h;
        this->minutes = 0;
        this->seconds = 0;
        normalize(); // Correctness is preserved, but code is verbose
    }

    // 3) With hours, minutes, and seconds
    Time(int h, int m, int s) { // Readability/Efficiency: Not using initializer list, no constructor delegation
        this->hours = h;
        this->minutes = m;
        this->seconds = s;
        normalize(); // Correctness is preserved, but code is verbose
    }

    void display() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds << std::endl;
    }
};

int main() {
    std::cout << "--- Readability / Efficiency Issue Test Cases ---" << std::endl;

    Time t1;                // Default: 00:00:00
    Time t2(5);             // Hours only: 05:00:00
    Time t3(15, 30, 45);    // Full: 15:30:45

    Time t4(23, 59, 59);    // Max valid: 23:59:59
    Time t5(0, 0, 0);       // Min valid: 00:00:00

    // Out-of-range values (should normalize correctly)
    Time t6(25, 65, 70);    // Expected: 01:06:10
    Time t7(10, -5, 0);     // Expected: 09:55:00
    Time t8(0, 0, -1);      // Expected: 23:59:59
    Time t9(-2, 10, 20);    // Expected: 22:10:20

    Time t10(24, 0, 0);     // Hours exact multiple: 00:00:00
    Time t11(0, 60, 0);     // Minutes exact multiple: 01:00:00
    Time t12(0, 0, 60);     // Seconds exact multiple: 00:01:00
    Time t13(48, 120, 120); // Large overflow: 02:02:00

    std::cout << "t1 (default): "; t1.display();
    std::cout << "t2 (5 hours): "; t2.display();
    std::cout << "t3 (15:30:45): "; t3.display();
    std::cout << "t4 (23:59:59): "; t4.display();
    std::cout << "t5 (00:00:00): "; t5.display();
    std::cout << "t6 (25:65:70 - overflow): "; t6.display();
    std::cout << "t7 (10:-5:0 - negative minutes): "; t7.display();
    std::cout << "t8 (0:0:-1 - negative seconds): "; t8.display();
    std::cout << "t9 (-2:10:20 - negative hours): "; t9.display();
    std::cout << "t10 (24:0:0): "; t10.display();
    std::cout << "t11 (0:60:0): "; t11.display();
    std::cout << "t12 (0:0:60): "; t12.display();
    std::cout << "t13 (48:120:120): "; t13.display();

    return 0;
}