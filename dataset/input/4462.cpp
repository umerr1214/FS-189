#include <iostream>

// Function to find the middle value among three distinct integers
int findMiddleValue(int a, int b, int c) {
    if ((a > b && a < c) || (a < b && a > c)) {
        return a;
    } else if ((b > a && b < c) || (b < a && b > c)) {
        return b
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