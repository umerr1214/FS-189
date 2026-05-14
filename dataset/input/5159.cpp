#include <iostream>

void printTrianglePattern(int height) {
    for (int i = 1; i <= height; ++i) {
        // Logical error: The inner loop runs 'height' times, printing a rectangle, not a triangle.
        for (int j = 1; j <= height; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
    int height;
    std::cout << "Enter the height of the triangle: ";
    std::cin >> height;
    printTrianglePattern(height);
    return 0;
}