#include <iostream>
#include <iomanip> // For std::setw and std::setfill

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Default constructor
    Time() : hour(0), minute(0), second(0) {}

    // Setters with validation
    void setHour(int h) {
        if (h >= 0 && h <= 23) {
            hour = h;
        } else {
            // In a real application, this might throw an exception or print to stderr.
        }
    }

    void setMinute(int m) {
        // LOGICAL ERROR: This condition allows 60 as a valid minute,
        // which should be rejected. It should be 'm <= 59' or 'm < 60'.
        if (m >= 0 && m <= 60) { // Incorrect upper bound
            minute = m;
        } else {
            // In a real application, this might throw an exception or print to stderr.
        }
    }

    void setSecond(int s) {
        if (s >= 0 && s <= 59) {
            second = s;
        } else {
            // In a real application, this might throw an exception or print to stderr.
        }
    }

    // Getter for display
    void displayTime() const {
        std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << minute << ":"
                  << std::setw(2) << std::setfill('0') << second << std::endl;
    }
};

int main() {
    Time t;
    std::cout << "Initial time: ";
    t.displayTime(); // Expected: 00:00:00

    t.setHour(10);
    t.setMinute(30);
    t.setSecond(45);
    std::cout << "Set to 10:30:45: ";
    t.displayTime(); // Expected: 10:30:45

    t.setMinute(60); // This should be invalid but will be accepted due to logical error
    std::cout << "Attempting to set minute to 60: ";
    t.displayTime(); // Expected: 10:60:45 (incorrect behavior)

    t.setHour(23);
    t.setMinute(59);
    t.setSecond(59);
    std::cout << "Set to 23:59:59: ";
    t.displayTime(); // Expected: 23:59:59

    t.setHour(24); // Invalid, should not change hour
    t.setMinute(-1); // Invalid, should not change minute
    t.setSecond(60); // Invalid, should not change second (but minute is already 60)
    std::cout << "Attempting invalid settings (non-60): ";
    t.displayTime(); // Expected: 23:60:59 (incorrect behavior for minute)

    return 0;
}