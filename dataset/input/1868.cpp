#include <iostream>
#include <iomanip> // For std::setfill and std::setw

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        // No input validation here, focusing on operator== efficiency/readability
    }

    // A helper function to convert time to total seconds for comparison.
    // This function itself is not an error, but its use in operator==
    // introduces the readability/efficiency issue.
    long long convertToTotalSeconds() const {
        // Using long long to be safe, though for typical 24-hour cycle int would suffice.
        return static_cast<long long>(hours) * 3600 +
               static_cast<long long>(minutes) * 60 +
               seconds;
    }

    // Overload the == operator with a readability/efficiency issue
    // This implementation converts both Time objects to total seconds for comparison.
    // This involves unnecessary arithmetic operations (multiplications and additions)
    // compared to a direct attribute-by-attribute comparison, making it less efficient.
    // It also reduces readability by obscuring the simple intent of comparing three integer members.
    bool operator==(const Time& other) const {
        return this->convertToTotalSeconds() == other.convertToTotalSeconds();
    }

    // Helper function to print time in HH:MM:SS format
    void print() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds;
    }
};

int main() {
    // Test cases for Readability / Efficiency Issue
    Time t1(10, 30, 45);
    Time t2(10, 30, 45); // Identical
    Time t3(10, 30, 46); // Different seconds
    Time t4(11, 30, 45); // Different hours
    Time t5(0, 0, 0);
    Time t6(0, 0, 1);    // Different seconds
    Time t7(23, 59, 59);
    Time t8(23, 59, 59); // Identical

    std::cout << "Testing Readability / Efficiency Issue (using total seconds conversion):\n";

    std::cout << "t1 ("; t1.print(); std::cout << ") == t2 ("; t2.print(); std::cout << ") -> " << (t1 == t2 ? "Equal" : "Not Equal") << " (Expected: Equal)\n";
    std::cout << "t1 ("; t1.print(); std::cout << ") == t3 ("; t3.print(); std::cout << ") -> " << (t1 == t3 ? "Equal" : "Not Equal") << " (Expected: Not Equal)\n";
    std::cout << "t1 ("; t1.print(); std::cout << ") == t4 ("; t4.print(); std::cout << ") -> " << (t1 == t4 ? "Equal" : "Not Equal") << " (Expected: Not Equal)\n";
    std::cout << "t5 ("; t5.print(); std::cout << ") == t6 ("; t6.print(); std::cout << ") -> " << (t5 == t6 ? "Equal" : "Not Equal") << " (Expected: Not Equal)\n";
    std::cout << "t7 ("; t7.print(); std::cout << ") == t8 ("; t8.print(); std::cout << ") -> " << (t7 == t8 ? "Equal" : "Not Equal") << " (Expected: Equal)\n";

    return 0;
}