#include <iostream>
#include <vector>
#include <map>

// Function to count frequency of elements (LOGICAL ERROR: always sets count to 1)
void countFrequency(const std::vector<int>& arr) {
    std::map<int, int> frequencyMap;
    for (int x : arr) {
        // Logical error: Instead of incrementing, always sets the count to 1.
        // This means every distinct element will incorrectly show a count of 1.
        frequencyMap[x] = 1;
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