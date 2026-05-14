#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Define a struct Time with members hours (int), minutes (int), and seconds (int).
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Robustness Issue:
// The addTimes function has a bug where the carry from seconds to minutes is not
// correctly incorporated into the calculation for minutes and subsequent carry to hours.
// It calculates the carry_to_minutes, but then proceeds to calculate minutes and
// carry_to_hours based solely on the sum of original minutes, effectively losing
// the carry from seconds.
Time addTimes(Time t1, Time t2) {
    Time result;

    // Calculate initial sums without considering rollovers yet
    int total_seconds = t1.seconds + t2.seconds;
    int total_minutes = t1.minutes + t2.minutes;
    int total_hours = t1.hours + t2.hours;

    // Handle seconds rollover
    result.seconds = total_seconds % 60;
    int carry_to_minutes = total_seconds / 60; // This carry is calculated

    // Handle minutes rollover
    // BUG: This line only normalizes total_minutes, not (total_minutes + carry_to_minutes)
    result.minutes = total_minutes % 60;
    // BUG: This carry_to_hours does not include carry_to_minutes
    int carry_to_hours = total_minutes / 60;

    // Handle hours
    // BUG: This line only adds the carry from the original total_minutes, not the one
    // that should have come from (total_minutes + carry_to_minutes)
    result.hours = total_hours + carry_to_hours;

    return result;
}

// Function to print Time for expected/actual output
std::string timeToString(const Time& t) {
    return std::to_string(t.hours) + "h " +
           std::to_string(t.minutes) + "m " +
           std::to_string(t.seconds) + "s";
}

// Function to parse input string "h1 m1 s1, h2 m2 s2"
std::pair<Time, Time> parseInput(const std::string& input_str) {
    std::stringstream ss(input_str);
    Time t1, t2;
    char comma;

    ss >> t1.hours >> t1.minutes >> t1.seconds;
    ss >> comma; // Consume the comma
    ss >> t2.hours >> t2.minutes >> t2.seconds;
    return {t1, t2};
}

int main() {
    std::vector<std::pair<std::string, std::string>> test_cases = {
        {"1 10 20, 0 5 10", "1h 15m 30s"}, // No rollover, should pass
        {"0 0 50, 0 0 20", "0h 0m 10s"},   // Expected: 0h 1m 10s. Actual (bugged): 0h 0m 10s (carry_to_minutes lost)
        {"0 50 0, 0 20 0", "1h 10m 0s"},   // Rollover in minutes only, should pass (no carry_to_minutes to lose)
        {"0 59 50, 0 0 20", "0h 59m 10s"}, // Expected: 1h 0m 10s. Actual (bugged): 0h 59m 10s (carry_to_minutes lost)
        {"23 30 0, 1 45 0", "25h 15m 0s"}  // Rollover in minutes to hours, no carry_to_minutes to lose, should pass
    };

    int test_num = 1;
    for (const auto& tc : test_cases) {
        std::pair<Time, Time> inputs = parseInput(tc.first);
        Time result = addTimes(inputs.first, inputs.second);
        std::string actual_output = timeToString(result);

        std::cout << "Test Case " << test_num++ << ":\n";
        std::cout << "Input: " << tc.first << "\n";
        std::cout << "Expected: " << tc.second << "\n";
        std::cout << "Actual: " << actual_output << "\n";
        if (actual_output == tc.second) {
            std::cout << "Result: PASSED\n\n";
        } else {
            std::cout << "Result: FAILED\n\n";
        }
    }

    return 0;
}