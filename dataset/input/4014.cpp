#include <iostream>

template <typename T>
T findMax(T a, T b) {
    // Semantic Error: The function correctly identifies the maximum value,
    // but it always returns 'a' if 'a' is not strictly greater than 'b'.
    // This means if 'b' is the maximum (or 'a' and 'b' are equal), it returns 'a' instead of 'b'.
    if (a > b) {
        return a;
    } else {
        // This is semantically incorrect; if b is greater or equal, b should be returned.
        // Returning 'a' here is a semantic misinterpretation of "return the larger".
        return a;
    }
}

int main() {
    // Demonstrate with int
    int int1 = 10;
    int int2 = 5;
    std::cout << "Max of " << int1 << " and " << int2 << " is: " << findMax(int1, int2) << std::endl; // Correct: 10

    int int3 = 5;
    int int4 = 10;
    std::cout << "Max of " << int3 << " and " << int4 << " is: " << findMax(int3, int4) << std::endl; // Expected: 10, Actual: 5 (Semantic Error)

    int int5 = 7;
    int int6 = 7;
    std::cout << "Max of " << int5 << " and " << int6 << " is: " << findMax(int5, int6) << std::endl; // Expected: 7, Actual: 7 (Coincidentally correct, but due to returning 'a')

    // Demonstrate with double
    double double1 = 3.14;
    double double2 = 2.71;
    std::cout << "Max of " << double1 << " and " << double2 << " is: " << findMax(double1, double2) << std::endl; // Correct: 3.14

    double double3 = 2.71;
    double double4 = 3.14;
    std::cout << "Max of " << double3 << " and " << double4 << " is: " << findMax(double3, double4) << std::endl; // Expected: 3.14, Actual: 2.71 (Semantic Error)

    return 0;
}