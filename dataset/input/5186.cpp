#include <iostream>
#include <iomanip>
// This program lacks comments and uses uninformative variable names, impacting readability.
// It also uses std::endl which flushes the buffer, potentially being less efficient than '\n'.
int main() {
    float x, y; // Uninformative variable names
    std::cout << "Enter first number: "; // No newline after prompt
    std::cin >> x;
    std::cout << "Enter second number: "; // No newline after prompt
    std::cin >> y;
    float z = x + y; // 'z' for sum is not descriptive
    int w = static_cast<int>(x * y); // 'w' for product is not descriptive
    std::cout << "Sum: " << std::fixed << std::setprecision(6) << z << std::endl; // Uses std::endl
    std::cout << "Product (int): " << w << std::endl; // Uses std::endl
    return 0;
}