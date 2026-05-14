#include <iostream>
#include <iomanip> // For std::setfill and std::setw

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Helper to normalize time values, handling carries and borrows correctly.
    // This ensures that hours, minutes, and seconds are always within their valid ranges.
    void normalize() {
        // Handle seconds overflow/underflow
        minutes += seconds / 60;
        seconds %= 60;
        if (seconds < 0) {
            seconds += 60; // Adjust to positive
            minutes--;     // Borrow from minutes
        }

        // Handle minutes overflow/underflow
        hours += minutes / 60;
        minutes %= 60;
        if (minutes < 0) {
            minutes += 60; // Adjust to positive
            hours--;       // Borrow from hours
        }

        // Handle hours overflow/underflow (wrap around 24 hours)
        hours %= 24;
        if (hours < 0) {
            hours += 24; // Adjust to positive (e.g., -1 hour becomes 23 hours)
        }
    }

public:
    // 3) Primary constructor: With hours, minutes, and seconds.
    // Uses initializer list for efficient member initialization, then normalizes.
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // 1) No arguments (default to 00:00:00) - delegates to the primary constructor.
    Time() : Time(0, 0, 0) {}

    // 2) With only hours (minutes and seconds default to 0) - delegates to the primary constructor.
    Time(int h) : Time(h, 0, 0) {}

    void display() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds << std::endl;
    }
};

int main() {
    std::cout << "--- Correct Version Test Cases ---" << std::endl;

    Time t1;                // Default: 00:00:00
    Time t2(5);             // Hours only: 05:00:00
    Time t3(15, 30, 45);    // Full: 15:30:45

    Time t4(23, 59, 59);    // Max valid: 23:59:59
    Time t5(0, 0, 0);       // Min valid: 00:00:00

    // Out-of-range values (should normalize correctly, handling carries and borrows)
    Time t6(25, 65, 70);    // 25h -> 1h (carry 1d), 65m -> 5m (carry 1h), 70s -> 10s (carry 1m)
                            // Result: (25%24 + 1h_from_min) : (65%60 + 1m_from_sec) : (70%60)
                            // (1 + 1) : (5 + 1) : 10 => 02:06:10
                            // Let's re-evaluate the normalize logic.
                            // 70s -> 10s, minutes += 1
                            // 65+1 = 66m -> 6m, hours += 1
                            // 25+1 = 26h -> 2h
                            // Final: 02:06:10. My code calculates this correctly.

    Time t7(10, -5, 0);     // 0h : -5m -> 55m, hours -= 1
                            // Result: 09:55:00
    Time t8(0, 0, -1);      // 0h : 0m : -1s -> 59s, minutes -= 1
                            // 0h : -1m -> 59m, hours -= 1
                            // -1h -> 23h
                            // Result: 23:59:59
    Time t9(-2, 10, 20);    // -2h -> 22h
                            // Result: 22:10:20

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