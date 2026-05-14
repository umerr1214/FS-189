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
            std::cout << "Invalid hour: " << h << ". Hour not set." << std::endl;
        }
    }

    void setMinute(int m) {
        if (m >= 0 && m <= 59) {
            minute = m;
        } else {
            std::cout << "Invalid minute: " << m << ". Minute not set." << std::endl;
        }
    }

    void setSecond(int s) {
        if (s >= 0 && s <= 59) {
            second = s;
        } else {
            std::cout << "Invalid second: " << s << ". Second not set." << std::endl;
        }
    }

    // Getter for display (for testing)
    void displayTime() const {
        std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << minute << ":"
                  << std::setw(2) << std::setfill('0') << second << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Time t;
    std::cout << "Initial time: ";
    t.displayTime();

    t.setHour(10);
    t.setMinute(30);
    t.setSecond(45);
    std::cout << "Set to 10:30:45: ";
    t.displayTime();

    t.setHour(25); // Invalid
    t.setMinute(-5); // Invalid
    t.setSecond(60); // Invalid
    std::cout << "Attempted invalid settings: ";
    t.displayTime();

    return 0;
}