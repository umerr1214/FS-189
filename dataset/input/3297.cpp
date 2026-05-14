#include <iostream>
#include <string>
#include <sstream>

// Function to check if three given side lengths can form a valid triangle.
// This is the correct, robust, readable, and efficient version.
// It first checks if all side lengths are positive, then applies the triangle inequality theorem.
bool isValidTriangle(int a, int b, int c) {
    // A triangle is valid if:
    // 1. All side lengths are strictly positive.
    // 2. The sum of the lengths of any two sides is greater than the length of the third side.
    return (a > 0 && b > 0 && c > 0) && // Check for positive side lengths (robustness)
           (a + b > c) &&               // Triangle inequality condition 1
           (a + c > b) &&               // Triangle inequality condition 2
           (b + c > a);                 // Triangle inequality condition 3
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int a, b, c;
        if (ss >> a >> b >> c) {
            std::cout << (isValidTriangle(a, b, c) ? "true" : "false") << std::endl;
        } else {
            // In case of malformed input, output false.
            std::cout << "false" << std::endl;
        }
    }
    return 0;
}