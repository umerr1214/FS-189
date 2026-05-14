#include <iostream>
#include <string>

// Global function overloaded for int
void printValue(int value) {
    std::cout << "Value: " << value << ", Type: int\n";
}

// Global function overloaded for double
void printValue(double value) {
    std::cout << "Value: " << value << ", Type: double\n";
}

// Global function overloaded for std::string
void printValue(std::string value) {
    // Semantic error: Instead of printing the full string value,
    // it only prints the first character if the string is not empty.
    if (!value.empty()) {
        std::cout << "Value: " << value[0] << ", Type: string (first char only)\n";
    } else {
        std::cout << "Value: (empty string), Type: string\n";
    }
}

int main() {
    printValue(10);
    printValue(3.14);
    printValue(std::string("Hello C++"));
    printValue(std::string("")); // Test with an empty string
    return 0;
}