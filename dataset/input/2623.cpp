#include <iostream>
#include <iomanip> // For std::setfill and std::setw

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Helper to clamp values to 0-max for positive inputs.
    // Negative inputs are clamped to 0, which is the robustness issue.
    void internal_set(int h, int m, int s) {
        // Seconds: clamp to 0-59. Negative inputs become 0.
        this->seconds = s % 60;
        if (this->seconds < 0) this->seconds = 0;

        // Minutes: clamp to 0-59. Negative inputs become 0.
        this->minutes = m % 60;
        if (this->minutes < 0) this->minutes = 0;

        // Hours: clamp to 0-23. Negative inputs become 0.
        this->hours = h % 24;
        if (this->hours < 0) this->hours = 0;
    }

public:
    // 1) No arguments (default to 00:00:00)
    Time() : hours(0), minutes(0), seconds(0) {}

    // 2) With only hours (minutes and seconds default to 0)
    Time(int h) {
        // Robustness issue: negative hours will be clamped to 0, not handled as a borrow.
        this->hours = h % 24;
        if (this->hours < 0) this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }

    // 3) With hours, minutes, and seconds
    Time(int h, int m, int s) {
        // Robustness issue: negative minutes/seconds are clamped to 0, not handled as borrows.
        // Positive out-of-range values are wrapped using modulo, but negative are not handled gracefully.
        internal_set(h, m, s);
    }

    void display() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds << std::endl;
    }
};

int main() {
    std::cout << "--- Robustness Issue Test Cases ---" << std::endl;

    Time t1;                // Default: 00:00:00
    Time t2(5);             // Hours only: 05:00:00
    Time t3(15, 30, 45);    // Full: 15:30:45

    Time t4(23, 59, 59);    // Max valid: 23:59:59
    Time t5(0, 0, 0);       // Min valid: 00:00:00

    // Positive out-of-range values (modulo works, but no carry propagation in `internal_set`)
    Time t6(25, 65, 70);    // Expected: 01:05:10 (modulo 24 for hours, modulo 60 for minutes/seconds, no carry)

    // Robustness issues: Negative inputs are clamped to 0 instead of correctly borrowing
    Time t7(10, -5, 0);     // Should be 09:55:00, but will be 10:00:00
    Time t8(0, 0, -1);      // Should be 23:59:59 (prev day), but will be 00:00:00
    Time t9(-2, 10, 20);    // Should be 22:10:20, but will be 00:10:20

    Time t10(24, 0, 0);     // Hours exact multiple: 00:00:00
    Time t11(0, 60, 0);     // Minutes exact multiple: 00:00:00
    Time t12(0, 0, 60);     // Seconds exact multiple: 00:00:00

    std::cout << "t1 (default): "; t1.display();
    std::cout << "t2 (5 hours): "; t2.display();
    std::cout << "t3 (15:30:45): "; t3.display();
    std::cout << "t4 (23:59:59): "; t4.display();
    std::cout << "t5 (00:00:00): "; t5.display();
    std::cout << "t6 (25:65:70 - positive overflow without carry): "; t6.display();
    std::cout << "t7 (10:-5:0 - negative minutes): "; t7.display();
    std::cout << "t8 (0:0:-1 - negative seconds): "; t8.display();
    std::cout << "t9 (-2:10:20 - negative hours): "; t9.display();
    std::cout << "t10 (24:0:0): "; t10.display();
    std::cout << "t11 (0:60:0): "; t11.display();
    std::cout << "t12 (0:0:60): "; t12.display();

    return 0;
}