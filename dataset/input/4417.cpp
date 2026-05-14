#include <iostream>

// Function template to print a value, demonstrating a robustness issue by passing by value.
template <typename T>
void printValue(T arg) { // Takes argument by value, which is not robust for all types (e.g., non-copyable, expensive to copy).
    std::cout << "Value: " << arg << '\n';
}

int main() {
    int i = 123;
    char c = 'A';

    // Demonstrate with an int
    printValue(i);

    // Demonstrate with a char
    printValue(c);

    return 0;
}