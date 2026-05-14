#include <iostream>
#include <string>
#include <cstdio> // For printf

// Global function overloaded for int (using printf - readability/consistency issue)
void printValue(int value) {
    printf("Type: int, Value: %d\n", value); // Inconsistent with std::cout usage for other types
}

// Global function overloaded for double
void printValue(double value) {
    // Readability/Efficiency Issue: Using std::endl flushes the output buffer,
    // which is often unnecessary and less efficient than simply printing '\n'.
    std::cout << "Type: double, Value: " << value << std::endl;
}

// Global function overloaded for std::string (passed by value - efficiency issue)
void printValue(std::string value) { // Passing by value creates a copy of the string
    // Readability/Efficiency Issue: Using std::endl flushes the output buffer,
    // which is often unnecessary and less efficient than simply printing '\n'.
    std::cout << "Type: std::string, Value: " << value << std::endl;
}

int main() {
    printValue(42);
    printValue(123.4567);
    printValue("Hello from inefficient code");
    printValue("Another string to copy");
    printValue(0);
    printValue(0.0);
    return 0;
}