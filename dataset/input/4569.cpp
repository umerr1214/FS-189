#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map> // For efficient frequency counting
#include <algorithm>   // For std::sort, if needed for output ordering (not strictly required by problem)
#include <map>         // To ensure sorted output for test cases, using std::map for printing

// Correct Version: This program efficiently counts the frequency of each distinct element
// using an unordered_map, providing O(N) average time complexity.
// It then prints the elements and their counts, sorted by element value.
void countElementFrequencies(const std::vector<int>& elements) {
    // Use std::unordered_map for efficient counting (O(N) average time complexity)
    std::unordered_map<int, int> frequencyMap;

    for (int num : elements) {
        frequencyMap[num]++;
    }

    // To print the output in a sorted order by element value,
    // we can transfer the data to a std::map or sort a vector of pairs.
    // Using std::map for sorted output is clean.
    std::map<int, int> sortedFrequencies(frequencyMap.begin(), frequencyMap.end());

    for (const auto& pair : sortedFrequencies) {
        std::cout << pair.first << " " << pair.second << std::endl;
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

    countElementFrequencies(arr);

    std::cout.rdbuf(old_cout); // Restore cout
    std::cout << buffer.str(); // Print captured output

    return 0;
}