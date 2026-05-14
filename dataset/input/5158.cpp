#include <iostream>

void printTrianglePattern(int height) {
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl // Missing semicolon here
    }
}

int main() {
    int height;
    std::cout << "Enter the height of the triangle: ";
    std::cin >> height;
    printTrianglePattern(height);
    return 0;
}