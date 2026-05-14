#include <iostream>

// Syntax error: Typo in 'template' keyword
tempalte <typename T>
T findMax(T val1, T val2) {
    return (val1 > val2) ? val1 : val2;
}

int main() {
    // Demonstrate with integers
    int int1 = 10;
    int int2 = 20;
    int maxInt = findMax(int1, int2);
    std::cout << "Max of " << int1 << " and " << int2 << " is: " << maxInt << std::endl;

    // Demonstrate with floating-point numbers
    double float1 = 15.5;
    double float2 = 10.2;
    double maxFloat = findMax(float1, float2);
    std::cout << "Max of " << float1 << " and " << float2 << " is: " << maxFloat << std::endl;

    return 0;
}