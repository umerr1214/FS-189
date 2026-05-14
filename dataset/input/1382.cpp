#include <iostream>
#include <iomanip> // For std::setw, std::setfill

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor
    Time() : hour(0), minute(0), second(0) {
        std::cout << "Time object created, initialized to 00:00:00.\n";
    }

    // Setter methods with readability/efficiency issues (verbose output, nested conditions, magic numbers)
    void setHour(int h) {
        std::cout << "--- Attempting to set hour to " << h << " ---\n";
        if (h >= 0) { // Check lower bound
            std::cout << "Hour " << h << " is not negative. Good so far.\n";
            if (h <= 23) { // Check upper bound
                std::cout << "Hour " << h << " is not too high. Valid range.\n";
                this->hour = h;
                std::cout << "Successfully updated hour to " << this->hour << ".\n";
            } else {
                std::cout << "Hour " << h << " is greater than the maximum allowed (23). Hour not set.\n";
            }
        } else {
            std::cout << "Hour " << h << " is less than the minimum allowed (0). Hour not set.\n";
        }
        std::cout << "Current hour in object: " << this->hour << "\n";
    }

    void setMinute(int m) {
        std::cout << "--- Attempting to set minute to " << m << " ---\n";
        if (m >= 0) { // Check lower bound
            std::cout << "Minute " << m << " is not negative. Good so far.\n";
            if (m <= 59) { // Check upper bound
                std::cout << "Minute " << m << " is not too high. Valid range.\n";
                this->minute = m;
                std::cout << "Successfully updated minute to " << this->minute << ".\n";
            } else {
                std::cout << "Minute " << m << " is greater than the maximum allowed (59). Minute not set.\n";
            }
        } else {
            std::cout << "Minute " << m << " is less than the minimum allowed (0). Minute not set.\n";
        }
        std::cout << "Current minute in object: " << this->minute << "\n";
    }

    void setSecond(int s) {
        std::cout << "--- Attempting to set second to " << s << " ---\n";
        if (s >= 0) { // Check lower bound
            std::cout << "Second " << s << " is not negative. Good so far.\n";
            if (s <= 59) { // Check upper bound
                std::cout << "Second " << s << " is not too high. Valid range.\n";
                this->second = s;
                std::cout << "Successfully updated second to " << this->second << ".\n";
            } else {
                std::cout << "Second " << s << " is greater than the maximum allowed (59). Second not set.\n";
            }
        } else {
            std::cout << "Second " << s << " is less than the minimum allowed (0). Second not set.\n";
        }
        std::cout << "Current second in object: " << this->second << "\n";
    }

    // Display method
    void displayTime() const {
        std::cout << "Displaying current time: ";
        std::cout << std::setw(2) << std::setfill('0') << hour << ":"
                  << std::setw(2) << std::setfill('0') << minute << ":"
                  << std::setw(2) << std::setfill('0') << second << "\n";
    }
};

int main() {
    Time myTime;
    myTime.displayTime();
    std::cout << "\n";

    std::cout << "--- Testing valid values ---\n";
    myTime.setHour(15);
    myTime.setMinute(30);
    myTime.setSecond(45);
    myTime.displayTime();
    std::cout << "\n";

    std::cout << "--- Testing invalid values ---\n";
    myTime.setHour(25); // Too high
    myTime.setMinute(-1); // Too low
    myTime.setSecond(60); // Too high
    myTime.displayTime();
    std::cout << "\n";

    std::cout << "--- Testing edge cases ---\n";
    myTime.setHour(0);
    myTime.setMinute(59);
    myTime.setSecond(0);
    myTime.displayTime();

    return 0;
}