#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> // For std::sort, though not used in the inefficient version

// Readability/Efficiency Issue: This implementation uses nested loops, resulting in O(N^2) time complexity.
// It also uses a 'visited' array which adds memory overhead and slightly more complex logic than a map-based solution.
// Variable names are somewhat generic, and comments are minimal for this version.
void freqCounter(const std::vector<int>& dataArray) {
    if (dataArray.empty()) {
        return;
    }

    std::vector<bool> visited(dataArray.size(), false); // To keep track of visited elements

    for (size_t i = 0; i < dataArray.size(); ++i) {
        if (visited[i] == true) {
            continue; // Skip if already counted
        }

        int currentElement = dataArray[i];
        int count = 1; // Count for the current element

        // Inner loop to find occurrences of the current element
        for (size_t j = i + 1; j < dataArray.size(); ++j) {
            if (dataArray[j] == currentElement) {
                count++;
                visited[j] = true; // Mark as visited to avoid recounting
            }
        }
        std::cout << currentElement << " " << count << std::endl;
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

    freqCounter(arr);

    std::cout.rdbuf(old_cout); // Restore cout
    std::cout << buffer.str(); // Print captured output

    return 0;
}