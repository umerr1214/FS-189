#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    // Overload == operator - LOGICAL ERROR: Ignores seconds
    bool operator==(const Time& other) const {
        return (hours == other.hours &&
                minutes == other.minutes); // Logical error: seconds are not compared
    }

    void display() const {
        std::cout << hours << ":" << minutes << ":" << seconds;
    }
};

std::string bool_to_string(bool b) {
    return b ? "true" : "false";
}

int main() {
    Time t1(10, 30, 0);
    Time t2(10, 30, 0);
    Time t3(10, 30, 1); // Should be false
    Time t4(11, 0, 0);
    Time t5(10, 30, 15); // Should be false

    std::cout << "t1: "; t1.display(); std::cout << std::endl;
    std::cout << "t2: "; t2.display(); std::cout << std::endl;
    std::cout << "t3: "; t3.display(); std::cout << std::endl;
    std::cout << "t5: "; t5.display(); std::cout << std::endl;

    std::cout << "t1 == t2: " << bool_to_string(t1 == t2) << std::endl; // Expected: true, Actual: true
    std::cout << "t1 == t3: " << bool_to_string(t1 == t3) << std::endl; // Expected: false, Actual: true (BUG)
    std::cout << "t1 == t5: " << bool_to_string(t1 == t5) << std::endl; // Expected: false, Actual: true (BUG)
    std::cout << "t1 == t4: " << bool_to_string(t1 == t4) << std::endl; // Expected: false, Actual: false

    return 0;
}