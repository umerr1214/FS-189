#include <iostream>
#include <iomanip> // For std::setw, std::setfill

class Time {
private:
    int hour;
    int minute;
    int second;

    // Constants for validation ranges (improves readability and maintainability)
    static const int MIN_HOUR = 0;
    static const int MAX_HOUR = 23;
    static const int MIN_MINUTE = 0;
    static const int MAX_MINUTE = 59;
    static const int MIN_SECOND = 0;
    static const int MAX_SECOND = 59;

public:
    // Constructor
    Time() : hour(MIN_HOUR), minute(MIN_MINUTE), second(MIN_SECOND) {}

    // Public setter methods with robust validation, returning bool to indicate success/failure
    bool setHour(int h) {
        if (h >= MIN_HOUR && h <= MAX_HOUR) {
            this->hour = h;
            return true;
        }
        return false;
    }

    bool setMinute(int m) {
        if (m >= MIN_MINUTE && m <= MAX_MINUTE) {
            this->minute = m;
            return true;
        }
        return false;
    }

    bool setSecond(int s) {
        if (s >= MIN_SECOND && s <= MAX_SECOND) {
            this->second = s;
            return true;
        }
        return false;
    }

    // Getters (good practice, though not explicitly asked)
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

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

    std::cout << "Test Case 1: Setting valid time (10:20:30)\n";
    if (t.setHour(10)) {
        std::cout << "Hour set to 10 successfully.\n";
    } else {
        std::cout << "Failed to set hour to 10.\n";
    }
    if (t.setMinute(20)) {
        std::cout << "Minute set to 20 successfully.\n";
    } else {
        std::cout << "Failed to set minute to 20.\n";
    }
    if (t.setSecond(30)) {
        std::cout << "Second set to 30 successfully.\n";
    } else {
        std::cout << "Failed to set second to 30.\n";
    }
    std::cout << "Current time: ";
    t.displayTime();
    std::cout << "\n\n";

    std::cout << "Test Case 2: Attempting to set invalid time (24:-5:60)\n";
    std::cout << "Attempting to set hour to 24: ";
    if (!t.setHour(24)) {
        std::cout << "Failed (as expected). Hour remains " << t.getHour() << ".\n";
    }
    std::cout << "Attempting to set minute to -5: ";
    if (!t.setMinute(-5)) {
        std::cout << "Failed (as expected). Minute remains " << t.getMinute() << ".\n";
    }
    std::cout << "Attempting to set second to 60: ";
    if (!t.setSecond(60)) {
        std::cout << "Failed (as expected). Second remains " << t.getSecond() << ".\n";
    }
    std::cout << "Current time after invalid attempts: ";
    t.displayTime();
    std::cout << "\n\n";

    std::cout << "Test Case 3: Setting edge case values (23:59:59)\n";
    t.setHour(23);
    t.setMinute(59);
    t.setSecond(59);
    std::cout << "Current time: ";
    t.displayTime();
    std::cout << "\n";

    return 0;
}