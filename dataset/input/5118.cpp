#include <iostream>

// Semantic error: Parameters are passed by value, not by reference.
// This function will not modify the original variables passed to it.
void swap(int a, int b) { // Changed from int& to int, violating the question's requirement for pass-by-reference
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5;
    int y = 10;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

    swap(x, y); // This call passes copies of x and y, so original x and y remain unchanged

    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}