#include <iostream>

// Function with a semantic error: takes int by value instead of reference
void doubleValue(int num) { // Should be void doubleValue(int& num)
    num = num * 2; // This modifies the local copy, not the original variable
}

int main() {
    int myValue = 5;
    std::cout << "Original value: " << myValue << std::endl;
    doubleValue(myValue);
    std::cout << "Doubled value: " << myValue << std::endl; // This will still print 5
    return 0;
}