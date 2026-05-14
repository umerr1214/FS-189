#include <iostream>
#include <iomanip> // For std::setfill and std::setw

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor with basic validation (good practice, though not strictly required by problem for ==)
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        // Basic validation to keep time components within reasonable ranges.
        // For the purpose of 'exact same time' comparison, the key is consistency.
        if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
            // In a real application, this might throw an exception, normalize, or log an error.
            // For this problem, we'll assume valid inputs or that comparison handles them as-is,
            // but a robust class would enforce valid ranges.
        }
    }

    // Overload the == operator
    // This is the correct, readable, and efficient way to compare for exact equality.
    // It directly compares each attribute.
    bool operator==(const Time& other) const {
        return hours == other.hours &&
               minutes == other.minutes &&
               seconds == other.seconds;
    }

    // Helper function to print time in HH:MM:SS format
    void print() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds;
    }
};

int main() {
    // Test cases for Correct Version
    Time t1(10, 30, 45);
    Time t2(10, 30, 45); // Identical
    Time t3(10, 30, 46); // Different seconds
    Time t4(11, 30, 45); // Different hours
    Time t5(0, 0, 0);
    Time t6(0, 0, 1);    // Different seconds
    Time t7(23, 59, 59);
    Time t8(23, 59, 59); // Identical
    Time t9(1, 2, 3);
    Time t10(1, 2, 4);   // Different seconds

    std::cout << "Testing Correct Version:\n";

    std::cout << "t1 ("; t1.print(); std::cout << ") == t2 ("; t2.print(); std::cout << ") -> " << (t1 == t2 ? "Equal" : "Not Equal") << " (Expected: Equal)\n";
    std::cout << "t1 ("; t1.print(); std::cout << ") == t3 ("; t3.print(); std::cout << ") -> " << (t1 == t3 ? "Equal" : "Not Equal") << " (Expected: Not Equal)\n";
    std::cout << "t1 ("; t1.print(); std::cout << ") == t4 ("; t4.print(); std::cout << ") -> " << (t1 == t4 ? "Equal" : "Not Equal") << " (Expected: Not Equal)\n";
    std::cout << "t5 ("; t5.print(); std::cout << ") == t6 ("; t6.print(); std::cout << ") -> " << (t5 == t6 ? "Equal" : "Not Equal") << " (Expected: Not Equal)\n";
    std::cout << "t7 ("; t7.print(); std::cout << ") == t8 ("; t8.print(); std::cout << ") -> " << (t7 == t8 ? "Equal" : "Not Equal") << " (Expected: Equal)\n";
    std::cout << "t9 ("; t9.print(); std::cout << ") == t10 ("; t10.print(); std::cout << ") -> " << (t9 == t10 ? "Equal" : "Not Equal") << " (Expected: Not Equal)\n";

    return 0;
}