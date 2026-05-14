#include <iostream>

int main() {
    float l, w; // Readability Issue: Short, uninformative variable names

    std::cout << "Enter length: "; // Readability Issue: Brief prompt
    std::cin >> l;

    std::cout << "Enter width: "; // Readability Issue: Brief prompt
    std::cin >> w;

    float a = l * w; // Readability Issue: Short, uninformative variable name 'a'
    float p = 2 * (l + w); // Readability Issue: Short, uninformative variable name 'p'

    // Efficiency Issue: Using float instead of double for dimensions and calculations,
    // which might lead to less precision in some scenarios, though less critical here.
    // Readability Issue: Output messages are terse.
    std::cout << "Area: " << a << std::endl;
    std::cout << "Perimeter: " << p << std::endl;

    return 0;
}