#include <iostream>
#include <string>

// Global function overloaded for int
void printValue(int value) {
    std::cout << "Value: " << value << ", Type: int\n" // Syntax error: missing semicolon
}

// Global function overloaded for double
void printValue(double value) {
    std::cout << "Value: " << value << ", Type: double\n";
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