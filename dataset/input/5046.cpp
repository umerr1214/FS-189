#include <iostream>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Semantic Error: The function returns a pointer to a local variable (`result`).
// When the function returns, `result` is destroyed, and the returned pointer
// becomes a dangling pointer, leading to undefined behavior when dereferenced.
Time* addTimes(Time t1, Time t2) { // Should return Time, not Time*
    Time result; // `result` is a local variable, allocated on the stack

    result.seconds = t1.seconds + t2.seconds;
    result.minutes = t1.minutes + t2.minutes;
    result.hours = t1.hours + t2.hours;

    result.minutes += result.seconds / 60;
    result.seconds %= 60;

    result.hours += result.minutes / 60;
    result.minutes %= 60;

    return &result; // Returning the address of a local variable
}

int main() {
    Time t1, t2;
    Time* sumPtr; // Pointer to receive the result

    // Test Case 1
    t1 = {1, 30, 0}; t2 = {0, 15, 0};
    sumPtr = addTimes(t1, t2);
    // Dereferencing a dangling pointer leads to undefined behavior
    std::cout << sumPtr->hours << " " << sumPtr->minutes << " " << sumPtr->seconds << std::endl;

    // Test Case 2
    t1 = {0, 0, 50}; t2 = {0, 0, 20};
    sumPtr = addTimes(t1, t2);
    std::cout << sumPtr->hours << " " << sumPtr->minutes << " " << sumPtr->seconds << std::endl;

    // Test Case 3
    t1 = {0, 59, 30}; t2 = {0, 1, 40};
    sumPtr = addTimes(t1, t2);
    std::cout << sumPtr->hours << " " << sumPtr->minutes << " " << sumPtr->seconds << std::endl;

    // Test Case 4
    t1 = {2, 30, 45}; t2 = {3, 40, 20};
    sumPtr = addTimes(t1, t2);
    std::cout << sumPtr->hours << " " << sumPtr->minutes << " " << sumPtr->seconds << std::endl;

    // Test Case 5
    t1 = {23, 59, 59}; t2 = {0, 0, 1};
    sumPtr = addTimes(t1, t2);
    std::cout << sumPtr->hours << " " << sumPtr->minutes << " " << sumPtr->seconds << std::endl;

    return 0;
}