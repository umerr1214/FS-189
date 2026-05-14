#include <iostream>

template <typename T>
// Semantic error: The function is defined with a 'void' return type
// but the question specified `T findMax(T val1, T val2)`.
void findMax(T val1, T val2) {
    T result = (val1 > val2) ? val1 : val2;
    std::cout << "Calculated max is: " << result << std::endl; // Prints instead of returning
}

int main() {
    // Demonstrate with integers
    int int1 = 10;
    int int2 = 20;
    std::cout << "Finding max of " << int1 << " and " << int2 << ": ";
    findMax(int1, int2); // Function call is valid, but it doesn't return a value

    // Demonstrate with floating-point numbers
    double float1 = 15.5;
    double float2 = 10.2;
    std::cout << "Finding max of " << float1 << " and " << float2 << ": ";
    findMax(float1, float2); // Function call is valid, but it doesn't return a value

    return 0;
}