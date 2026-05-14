#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> // Not strictly necessary for this specific logic, but often useful.

// Function to check if three given side lengths can form a valid triangle.
// This version has a robustness issue: it does not explicitly validate that
// side lengths `a`, `b`, and `c` are positive. It implicitly assumes positive inputs
// and only checks the triangle inequality theorem.
bool isValidTriangle(int a, int b, int c) {
    // The core triangle inequality conditions
    bool cond1 = (a + b > c);
    bool cond2 = (a + c > b);
    bool cond3 = (b + c > a);

    return cond1 && cond2 && cond3;
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