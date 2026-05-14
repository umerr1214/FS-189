#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void display() const {
        std::cout << hours << ":" << minutes << ":" << seconds;
    }
};

// Semantic Error: Attempting to define operator== as a non-member function
// and directly access private members of Time objects without a friend declaration.
bool operator==(const Time& time1, const Time& time2) {
    return (time1.hours == time2.hours && // Error: 'hours' is private
            time1.minutes == time2.minutes && // Error: 'minutes' is private
            time1.seconds == time2.seconds); // Error: 'seconds' is private
}

std::string bool_to_string(bool b) {
    return b ? "true" : "false";
}

int main() {
    Time t1(10, 30, 0);
    Time t2(10, 30, 0);
    Time t3(10, 30, 1);

    std::cout << "t1: "; t1.display(); std::cout << std::endl;
    std::cout << "t2: "; t2.display(); std::cout << std::endl;
    std::cout << "t3: "; t3.display(); std::cout << std::endl;

    // These comparisons will cause a compile-time error due to the semantic error above
    // if (t1 == t2) {
    //     std::cout << "t1 == t2 is true" << std::endl;
    // } else {
    //     std::cout << "t1 == t2 is false" << std::endl;
    // }

    // if (t1 == t3) {
    //     std::cout << "t1 == t3 is true" << std::endl;
    // } else {
    //     std::cout << "t1 == t3 is false" << std::endl;
    // }

    return 0;
}