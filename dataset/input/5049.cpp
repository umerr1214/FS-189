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

// Correct Version:
// This function correctly adds two Time structs, handling rollovers for seconds,
// minutes, and hours in a clear, concise, and efficient manner.
Time addTimes(Time t1, Time t2) {
    Time result;

    // Add seconds and handle rollover
    result.seconds = t1.seconds + t2.seconds;
    int carry_minutes = result.seconds / 60;
    result.seconds %= 60;

    // Add minutes (including carry from seconds) and handle rollover
    result.minutes = t1.minutes + t2.minutes + carry_minutes;
    int carry_hours = result.minutes / 60;
    result.minutes %= 60;

    // Add hours (including carry from minutes)
    result.hours = t1.hours + t2.hours + carry_hours;

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
        {"1 10 20, 0 5 10", "1h 15m 30s"},
        {"0 0 50, 0 0 20", "0h 1m 10s"},
        {"0 50 0, 0 20 0", "1h 10m 0s"},
        {"0 59 50, 0 0 20", "1h 0m 10s"},
        {"23 30 0, 1 45 0", "25h 15m 0s"}
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