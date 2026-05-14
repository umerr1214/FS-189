#include <iostream>

struct Time {
    int hours;
    int minutes;
    int seconds;
}; // SYNTAX ERROR: Missing semicolon here

Time addTimes(Time t1, Time t2) {
    Time result;

    result.seconds = t1.seconds + t2.seconds;
    result.minutes = t1.minutes + t2.minutes;
    result.hours = t1.hours + t2.hours;

    result.minutes += result.seconds / 60;
    result.seconds %= 60;

    result.hours += result.minutes / 60;
    result.minutes %= 60;

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