#include <iostream>
#include <string>

// Global function overloaded for int
void printValue(int value) {
    std::cout << "Value: " << value << ", Type: int\n";
}

// Global function overloaded for double
void printValue(double value) {
    // Logical error: Incorrectly prints "Type: int" for a double value
    std::cout << "Value: " << value << ", Type: int\n";
}

// Global function overloaded for std::string
void printValue(std::string value) {
    std::cout << "Value: " << value << ", Type: string\n";
}

int main() {
    printValue(10);
    printValue(3.14);
    printValue(std::string("Hello C++"));
    return 0;
}