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

// Readability / Efficiency Issue:
// This version correctly calculates the sum of two Time structs with rollovers
// by converting everything to total seconds, adding them, and then converting back.
// While functionally correct and efficient in terms of Big-O complexity (constant time),
// it suffers from readability issues due to overly verbose variable names and
// explicit `long long` casts which are not strictly necessary for typical time values,
// making the code more cumbersome to read and maintain than a direct carry-over approach.
Time addTimes(Time t1, Time t2) {
    Time final_time_result;

    // Convert the first time struct into its total equivalent in seconds.
    // Using long long to prevent potential overflow for very large hour values,
    // though int would likely suffice for typical ranges (e.g., up to 24855 hours).
    long long first_time_total_seconds_representation = (long long)t1.hours * 3600 + (long long)t1.minutes * 60 + t1.seconds;

    // Convert the second time struct into its total equivalent in seconds.
    long long second_time_total_seconds_representation = (long long)t2.hours * 3600 + (long long)t2.minutes * 60 + t2.seconds;

    // Calculate the grand total number of seconds by summing the two total second representations.
    long long grand_total_seconds_sum = first_time_total_seconds_representation + second_time_total_seconds_representation;

    // Now, convert the grand total seconds back into the hours, minutes, and seconds components.

    // First, determine the number of full hours from the grand total seconds.
    long long calculated_hours_component = grand_total_seconds_sum / 3600;
    final_time_result.hours = static_cast<int>(calculated_hours_component);

    // Calculate the number of remaining seconds after the hours have been extracted.
    long long remaining_seconds_after_hours_extraction = grand_total_seconds_sum % 3600;

    // Next, determine the number of full minutes from the remaining seconds.
    long long calculated_minutes_component = remaining_seconds_after_hours_extraction / 60;
    final_time_result.minutes = static_cast<int>(calculated_minutes_component);

    // Finally, the remaining seconds after minutes extraction form the seconds component.
    long long final_seconds_component = remaining_seconds_after_hours_extraction % 60;
    final_time_result.seconds = static_cast<int>(final_seconds_component);

    return final_time_result;
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