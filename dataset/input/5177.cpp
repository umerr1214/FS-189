#include <iostream>

template <typename T>
T findMax(T val1, T val2) {
    // Logical error: This function returns the minimum value instead of the maximum.
    return (val1 < val2) ? val1 : val2;
}

int main() {
    // Demonstrate with integers
    int int1 = 10;
    int int2 = 20;
    int maxInt = findMax(int1, int2);
    std::cout << "Max of " << int1 << " and " << int2 << " is: " << maxInt << std::endl; // Expected: 20, Actual: 10

    // Demonstrate with floating-point numbers
    double float1 = 15.5;
    double float2 = 10.2;
    double maxFloat = findMax(float1, float2);
    std::cout << "Max of " << float1 << " and " << float2 << " is: " << maxFloat << std::endl; // Expected: 15.5, Actual: 10.2

    return 0;
}