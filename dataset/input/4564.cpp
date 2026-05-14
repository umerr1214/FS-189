#include <iostream>
#include <vector>
#include <map>

// Function to count frequency of elements
void countFrequency(const std::vector<int>& arr) {
    std::map<int, int> frequencyMap;
    for (int x : arr) {
        frequencyMap[x]++;
    }

    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << ": " << pair.second << std::endl // SYNTAX ERROR: Missing semicolon
    }
}

int main() {
    int n;
    std::cin >> n; // Read array size

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i]; // Read elements
    }

    countFrequency(arr);

    return 0;
}