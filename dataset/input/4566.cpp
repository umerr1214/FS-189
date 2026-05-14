#include <iostream>
#include <vector>
#include <map>

// Function to count frequency of elements (SEMANTIC ERROR: potential out-of-bounds access)
void countFrequency(const std::vector<int>& arr) {
    std::map<int, int> frequencyMap;
    // Semantic error: Loop condition allows accessing arr[arr.size()], which is out of bounds.
    // This leads to undefined behavior, potentially a crash or corrupted data.
    for (size_t i = 0; i <= arr.size(); ++i) { // Should be i < arr.size()
        frequencyMap[arr[i]]++; // Accessing arr[arr.size()] here
    }

    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
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