#include <iostream>

// Function to find the middle value among three distinct integers
int findMiddleValue(int a, int b, int c) {
    // Semantic Error: The condition for 'b' being the middle value is semantically incorrect.
    // It uses an '||' (OR) operator where an '&&' (AND) operator is required for the first part
    // of the comparison, making the condition too broad and leading to incorrect results.
    // E.g., for (b > a || b < c) if a=1, b=5, c=2, (5 > 1 || 5 < 2) is true, but 5 is not the middle.
    if ((a > b && a < c) || (a < b && a > c)) {
        return a;
    } else if ((b > a || b < c) || (b < a && b > c)) {
        return b;
    } else {
        return c;
    }
}

// Main function for local testing
int main() {
    int x, y, z;
    std::cin >> x >> y >> z;
    std::cout << findMiddleValue(x, y, z) << std::endl;
    return 0;
}