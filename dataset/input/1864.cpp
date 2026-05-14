#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        // Basic normalization, though not strictly required by question, good practice
        // For simplicity, assuming valid time inputs for this problem
    }

    // Overload == operator
    bool operator==(const Time& other) const {
        return (hours == other.hours &&
                minutes == other.minutes &&
                seconds == other.seconds);
    }

    void display() const {
        std::cout << hours << ":" << minutes << ":" << seconds;
    }
}; // Missing semicolon here, causing a syntax error

int main() {
    Time t1(10, 30, 0);
    Time t2(10, 30, 0);
    Time t3(10, 30, 1);

    std::cout << "t1: "; t1.display(); std::cout << std::endl;
    std::cout << "t2: "; t2.display(); std::cout << std::endl;
    std::cout << "t3: "; t3.display(); std::cout << std::endl;

    if (t1 == t2) {
        std::cout << "t1 == t2 is true" << std::endl;
    } else {
        std::cout << "t1 == t2 is false" << std::endl;
    }

    if (t1 == t3) {
        std::cout << "t1 == t3 is true" << std::endl;
    } else {
        std::cout << "t1 == t3 is false" << std::endl;
    }

    return 0;
}