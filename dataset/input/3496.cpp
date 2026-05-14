#include <iostream>

// Function definition with a syntax error (missing semicolon)
void doubleValue(int& num) {
    num = num * 2
} // Missing semicolon here

int main() {
    int myValue = 5;
    std::cout << "Original value: " << myValue << std::endl;
    doubleValue(myValue);
    std::cout << "Doubled value: " << myValue << std::endl;
    return 0;
}