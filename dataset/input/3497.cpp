#include <iostream>

// Function with a logical error: adds 2 instead of doubling
void doubleValue(int& num) {
    num = num + 2; // Should be num = num * 2;
}

int main() {
    int myValue = 5;
    std::cout << "Original value: " << myValue << std::endl;
    doubleValue(myValue);
    std::cout << "Doubled value: " << myValue << std::endl; // This will print 7, not 10
    return 0;
}