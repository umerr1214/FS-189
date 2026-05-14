#include <iostream>
#include <cmath> // Required for std::abs
#include <iomanip> // For std::setfill and std::setw

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        // No input validation here, focusing on operator== robustness
    }

    // Overload the == operator with a robustness issue
    // It considers two times equal if hours and minutes match,
    // and seconds differ by 0 or 1. This violates "exact same time".
    bool operator==(const Time& other) const {
        return hours == other.hours &&
               minutes == other.minutes &&
               std::abs(seconds - other.seconds) <= 1; // Robustness Issue: Allows 1 second difference
    }

    // Helper function to print time in HH:MM:SS format
    void print() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds;
    }
};

int main() {
    // Test cases for Robustness Issue
    Time t1(10, 30, 45);
    Time t2(10, 30, 45); // Identical
    Time t3(10, 30, 46); // Differs by 1 second
    Time t4(10, 30, 47); // Differs by 2 seconds
    Time t5(5, 5, 0);
    Time t6(5, 5, 1);    // Differs by 1 second
    Time t7(0, 0, 0);
    Time t8(0, 0, 0);    // Identical
    Time t9(1, 2, 3);
    Time t10(1, 2, 4);   // Differs by 1 second
    Time t11(1, 2, 5);   // Differs by 2 seconds

    std::cout << "Testing Robustness Issue (seconds difference <= 1 considered equal):\n";

    std::cout << "t1 ("; t1.print(); std::cout << ") == t2 ("; t2.print(); std::cout << ") -> " << (t1 == t2 ? "Equal" : "Not Equal") << " (Expected: Equal)\n";
    std::cout << "t1 ("; t1.print(); std::cout << ") == t3 ("; t3.print(); std::cout << ") -> " << (t1 == t3 ? "Equal" : "Not Equal") << " (Expected: Not Equal, but will be Equal)\n";
    std::cout << "t1 ("; t1.print(); std::cout << ") == t4 ("; t4.print(); std::cout << ") -> " << (t1 == t4 ? "Equal" : "Not Equal") << " (Expected: Not Equal)\n";
    std::cout << "t5 ("; t5.print(); std::cout << ") == t6 ("; t6.print(); std::cout << ") -> " << (t5 == t6 ? "Equal" : "Not Equal") << " (Expected: Not Equal, but will be Equal)\n";
    std::cout << "t7 ("; t7.print(); std::cout << ") == t8 ("; t8.print(); std::cout << ") -> " << (t7 == t8 ? "Equal" : "Not Equal") << " (Expected: Equal)\n";
    std::cout << "t9 ("; t9.print(); std::cout << ") == t10 ("; t10.print(); std::cout << ") -> " << (t9 == t10 ? "Equal" : "Not Equal") << " (Expected: Not Equal, but will be Equal)\n";
    std::cout << "t9 ("; t9.print(); std::cout << ") == t11 ("; t11.print(); std::cout << ") -> " << (t9 == t11 ? "Equal" : "Not Equal") << " (Expected: Not Equal)\n";

    return 0;
}