#include <iostream>
#include <string>
#include <iomanip> // Needed for std::fixed, std::setprecision

// Global function overloaded for int
void printValue(int value) {
    std::cout << "Type: int, Value: " << value << '\n';
}

// Global function overloaded for double
void printValue(double value) {
    // Robustness Issue: Using std::fixed and a small std::setprecision(2)
    // might lead to loss of precision for double values that require more
    // decimal places, or display very large/small numbers in a truncated way
    // instead of scientific notation. This makes the output potentially
    // misleading or less informative for certain edge cases, compromising
    // the robustness of data representation.
    // The stream state is temporarily modified for this print.
    std::cout << "Type: double, Value: " << std::fixed << std::setprecision(2) << value << '\n';

    // Reset stream state to default after printing to avoid affecting subsequent prints
    std::cout.unsetf(std::ios_base::floatfield); // Reset floatfield (e.g., std::fixed)
    std::cout << std::setprecision(6); // Reset precision to default (usually 6)
}

// Global function overloaded for std::string
void printValue(const std::string& value) {
    std::cout << "Type: std::string, Value: " << value << '\n';
}

int main() {
    printValue(123);
    printValue(3.1415926535);
    printValue(123456789.123456789);
    printValue(0.00000012345);
    printValue("Robustness test string");
    printValue("");
    printValue(1.23456789); // Test to ensure subsequent double prints are not affected
    printValue(999999999.12345); // Test to ensure subsequent double prints are not affected

    return 0;
}