#include <iostream>

int main() {
    int s; // Non-descriptive variable name
    std::cout << "Enter array size: ";
    std::cin >> s;

    // No input validation - assumes valid positive integer input.
    // This could also be considered a robustness issue, but the primary focus here
    // is on readability and efficiency for *valid* inputs.

    int* a = new int[s]; // Non-descriptive variable name

    std::cout << "Array elements:" << std::endl; // Using std::endl flushes the buffer, less efficient than '\n'
    for (int i = 0; i < s; ++i) {
        a[i] = i;
        std::cout << a[i] << std::endl; // Using std::endl inside a loop is inefficient due to repeated buffer flushes
    }

    delete[] a;

    return 0;
}