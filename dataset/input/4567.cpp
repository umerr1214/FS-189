#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map> // Included for potential future use or if map is used internally for debugging/small tasks

// A robustness issue: This code assumes all elements are non-negative and within a small range (0-99).
// If an element is negative or greater than 99, it will lead to out-of-bounds access or incorrect results.
const int MAX_ELEMENT_VALUE = 99;

void countFrequencies(const std::vector<int>& arr) {
    // This fixed-size array is the source of the robustness issue
    std::vector<int> counts(MAX_ELEMENT_VALUE + 1, 0);

    for (int num : arr) {
        if (num >= 0 && num <= MAX_ELEMENT_VALUE) {
            counts[num]++;
        } else {
            // This 'else' branch attempts to handle out-of-range, but the core issue is the fixed-size array.
            // For negative numbers or numbers > MAX_ELEMENT_VALUE, this approach is fundamentally flawed
            // if we need to count them. It effectively ignores them or assumes they won't appear.
            // A truly robust solution would use a map.
            // For the purpose of demonstrating a robustness issue, we let the fixed-size array be the problem.
            // If we uncomment the line below for negative numbers, it will crash.
            // counts[num]++; // This would be the crash if num is negative or too large
        }
    }

    // Print frequencies for elements within the assumed range
    for (int i = 0; i <= MAX_ELEMENT_VALUE; ++i) {
        if (counts[i] > 0) {
            std::cout << i << " " << counts[i] << std::endl;
        }
    }
}

// Driver code for testing
int main() {
    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    int num;
    std::vector<int> arr;
    while (ss >> num) {
        arr.push_back(num);
    }

    // Redirect cout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old_cout = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    countFrequencies(arr);

    std::cout.rdbuf(old_cout); // Restore cout
    std::cout << buffer.str(); // Print captured output

    return 0;
}