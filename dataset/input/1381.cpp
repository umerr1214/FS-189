#include <iostream>
#include <iomanip> // For std::setw, std::setfill

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor
    Time() : hour(0), minute(0), second(0) {}

    // Setter methods with robustness issues (silent clamping, off-by-one error)
    void setHour(int h) {
        if (h < 0) {
            this->hour = 0; // Silently clamp to 0
            std::cout << "Hour " << h << " is too low. Clamped to 0.\n";
        } else if (h > 23) {
            this->hour = 23; // Silently clamp to 23
            std::cout << "Hour " << h << " is too high. Clamped to 23.\n";
        } else {
            this->hour = h;
            std::cout << "Hour set to " << h << ".\n";
        }
    }

    void setMinute(int m) {
        // Robustness issue: off-by-one error in upper bound (allows 60, should be 59)
        if (m < 0) {
            this->minute = 0; // Silently clamp to 0
            std::cout << "Minute " << m << " is too low. Clamped to 0.\n";
        } else if (m > 60) { // Should be m > 59
            this->minute = 60; // Silently clamp to 60 (invalid minute value)
            std::cout << "Minute " << m << " is too high. Clamped to 60.\n";
        } else {
            this->minute = m;
            std::cout << "Minute set to " << m << ".\n";
        }
    }

    void setSecond(int s) {
        if (s < 0) {
            this->second = 0; // Silently clamp to 0
            std::cout << "Second " << s << " is too low. Clamped to 0.\n";
        } else if (s > 59) {
            this->second = 59; // Silently clamp to 59
            std::cout << "Second " << s << " is too high. Clamped to 59.\n";
        } else {
            this->second = s;
            std::cout << "Second set to " << s << ".\n";
        }
    }

    // Display method
    void displayTime() const {
        std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << minute << ":"
                  << std::setw(2) << std::setfill('0') << second;
    }
};

int main() {
    Time t;
    std::cout << "Initial time: ";
    t.displayTime();
    std::cout << "\n\n";

    std::cout << "Test Case 1: Invalid values (too high, off-by-one high, negative)\n";
    t.setHour(25);
    t.setMinute(61);
    t.setSecond(-5);
    std::cout << "Time after invalid sets: ";
    t.displayTime();
    std::cout << "\nExpected: 23:60:00 (due to clamping and minute bug)\n\n";

    std::cout << "Test Case 2: Another invalid value (negative hour)\n";
    t.setHour(-1);
    t.setMinute(30);
    t.setSecond(30);
    std::cout << "Time after negative hour set: ";
    t.displayTime();
    std::cout << "\nExpected: 00:30:30\n\n";

    std::cout << "Test Case 3: Valid values\n";
    t.setHour(10);
    t.setMinute(59);
    t.setSecond(59);
    std::cout << "Time after valid sets: ";
    t.displayTime();
    std::cout << "\nExpected: 10:59:59\n";

    return 0;
}