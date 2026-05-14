#include <iostream>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Logical Error: Carry from seconds to minutes, and minutes to hours, is calculated
// but not added to the total minutes/hours before calculating their modulo and carry.
Time addTimes(Time t1, Time t2) {
    Time result;

    int totalSeconds = t1.seconds + t2.seconds;
    result.seconds = totalSeconds % 60;
    int carryMinutes = totalSeconds / 60; // This carry is calculated...

    int totalMinutes = t1.minutes + t2.minutes; // ...but not added here!
    result.minutes = totalMinutes % 60;
    int carryHours = totalMinutes / 60; // This carry is calculated...

    int totalHours = t1.hours + t2.hours; // ...but not added here!
    result.hours = totalHours; // Hours are not typically modulo'd unless a 24-hour cycle is specified.

    // Corrected logic would be:
    // result.seconds = (t1.seconds + t2.seconds) % 60;
    // int carryMinutes = (t1.seconds + t2.seconds) / 60;
    // result.minutes = (t1.minutes + t2.minutes + carryMinutes) % 60;
    // int carryHours = (t1.minutes + t2.minutes + carryMinutes) / 60;
    // result.hours = t1.hours + t2.hours + carryHours;

    return result;
}

int main() {
    Time t1, t2, sum;

    // Test Case 1
    t1 = {1, 30, 0}; t2 = {0, 15, 0};
    sum = addTimes(t1, t2);
    std::cout << sum.hours << " " << sum.minutes << " " << sum.seconds << std::endl;

    // Test Case 2
    t1 = {0, 0, 50}; t2 = {0, 0, 20};
    sum = addTimes(t1, t2);
    std::cout << sum.hours << " " << sum.minutes << " " << sum.seconds << std::endl;

    // Test Case 3
    t1 = {0, 59, 30}; t2 = {0, 1, 40};
    sum = addTimes(t1, t2);
    std::cout << sum.hours << " " << sum.minutes << " " << sum.seconds << std::endl;

    // Test Case 4
    t1 = {2, 30, 45}; t2 = {3, 40, 20};
    sum = addTimes(t1, t2);
    std::cout << sum.hours << " " << sum.minutes << " " << sum.seconds << std::endl;

    // Test Case 5
    t1 = {23, 59, 59}; t2 = {0, 0, 1};
    sum = addTimes(t1, t2);
    std::cout << sum.hours << " " << sum.minutes << " " << sum.seconds << std::endl;

    return 0;
}