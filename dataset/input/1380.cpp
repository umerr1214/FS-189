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

    // Setters with validation, but semantic error: parameter shadowing member variables
    void setHour(int hour) { // 'hour' here shadows 'this->hour'
        if (hour >= 0 && hour <= 23) {
            // SEMANTIC ERROR: This assigns the parameter 'hour' to itself.
            // The member variable 'this->hour' is never updated.
            hour = hour;
        } else {
            std::cout << "Invalid hour: " << hour << ". Hour not set." << std::endl;
        }
    }

    void setMinute(int minute) { // 'minute' here shadows 'this->minute'
        if (minute >= 0 && minute <= 59) {
            // SEMANTIC ERROR: Same issue as setHour.
            minute = minute;
        } else {
            std::cout << "Invalid minute: " << minute << ". Minute not set." << std::endl;
        }
    }

    void setSecond(int second) { // 'second' here shadows 'this->second'
        if (second >= 0 && second <= 59) {
            // SEMANTIC ERROR: Same issue as setHour.
            second = second;
        } else {
            std::cout << "Invalid second: " << second << ". Second not set." << std::endl;
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
    std::cout << "Attempted to set to 10:30:45: ";
    t.displayTime(); // Expected: 00:00:00 (due to semantic error, members not updated)

    t.setHour(25); // Invalid, but even if valid, wouldn't set
    t.setMinute(-5); // Invalid
    t.setSecond(60); // Invalid
    std::cout << "Attempted invalid settings: ";
    t.displayTime(); // Expected: 00:00:00 (members remain unchanged)

    return 0;
}