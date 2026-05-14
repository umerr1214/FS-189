#include <iostream>
#include <string>
#include <iomanip> // Included for good practice, though not strictly needed for basic printing

// Global function overloaded for int
void printValue(int value) {
    std::cout << "Type: int, Value: " << value << '\n';
}

// Global function overloaded for double
void printValue(double value) {
    std::cout << "Type: double, Value: " << value << '\n';
}

// Global function overloaded for std::string (passed by const reference for efficiency)
void printValue(const std::string& value) {
    std::cout << "Type: std::string, Value: " << value << '\n';
}

int main() {
    printValue(100);
    printValue(987.654321);
    printValue("This is a correctly implemented string.");
    printValue(-50);
    printValue(0.001);
    printValue(""); // Test with an empty string
    printValue("A very long string that should be handled efficiently without unnecessary copies.");

    return 0;
}