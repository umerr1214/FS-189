#include <iostream>

template <typename T>
T findMin(T val1, T val2) {
    // Semantic error: The comparison is performed after casting both values to 'double'.
    // While this happens to produce correct results for 'int' and 'double' types,
    // it introduces a semantic flaw for a generic template. For other types,
    // like custom classes or very large integers, this conversion could be
    // inappropriate, lead to precision loss, or bypass type-specific comparison logic.
    // The template should ideally use the native comparison operator for type T.
    if (static_cast<double>(val1) < static_cast<double>(val2)) {
        return val1;
    } else {
        return val2;
    }
}

int main() {
    // Demonstrate with integers
    int int1 = 10;
    int int2 = 5;
    std::cout << "Min of " << int1 << " and " << int2 << " is: " << findMin(int1, int2) << std::endl;

    // Demonstrate with doubles
    double double1 = 3.14;
    double double2 = 2.71;
    std::cout << "Min of " << double1 << " and " << double2 << " is: " << findMin(double1, double2) << std::endl;

    return 0;
}