#include <iostream>
#include <algorithm> // Required for std::min and std::max

// Function to find the middle value among three distinct integers
int findMiddleValue(int a, int b, int c) {
    // Logical Error: The formula to find the middle value using sum, min, and max is incorrect.
    // It should be: a + b + c - std::min({a, b, c}) - std::max({a, b, c})
    // This implementation incorrectly uses std::min(a, b) and std::max(b, c)
    // instead of the overall minimum and maximum of all three numbers.
    int middle = a + b + c - std::min(a, b) - std::max(b, c);
    return middle;
}

// Main function for local testing
int main() {
    int x, y, z;
    std::cin >> x >> y >> z;
    std::cout << findMiddleValue(x, y, z) << std::endl;
    return 0;
}