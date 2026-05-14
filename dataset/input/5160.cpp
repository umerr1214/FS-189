#include <iostream>

void printTrianglePattern(int height) {
    for (int i = 1; i <= height; ++i) {
        // Semantic error: The inner loop condition 'j < i' causes one less asterisk to be printed per row.
        // For row 'i', it should print 'i' asterisks, but 'j < i' prints 'i-1' asterisks.
        for (int j = 1; j < i; ++j) {
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