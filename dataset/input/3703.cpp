#include <iostream>

// Function template with a robustness issue:
// It forces comparison by casting to double, which might lose precision for long double
// or fail for custom types that don't implicitly convert to double.
template <typename T>
T findMax(T a, T b) {
    // This cast might lead to precision loss for types like long double,
    // and makes the template less generic for types not convertible to double.
    if (static_cast<double>(a) > static_cast<double>(b)) {
        return a;
    } else {
        return b;
    }
}

int main() {
    // Demonstrate with int
    std::cout << "Max of 5 and 10 (int): " << findMax(5, 10) << std::endl;
    std::cout << "Max of 7 and 7 (int): " << findMax(7, 7) << std::endl;
    std::cout << "Max of -5 and -10 (int): " << findMax(-5, -10) << std::endl;

    // Demonstrate with double
    std::cout << "Max of 3.14 and 2.71 (double): " << findMax(3.14, 2.71) << std::endl;
    std::cout << "Max of 1.0 and 1.0 (double): " << findMax(1.0, 1.0) << std::endl;
    std::cout << "Max of -0.5 and 0.5 (double): " << findMax(-0.5, 0.5) << std::endl;

    // Demonstrate with char
    std::cout << "Max of 'a' and 'z' (char): " << findMax('a', 'z') << std::endl;
    std::cout << "Max of 'X' and 'X' (char): " << findMax('X', 'X') << std::endl;
    std::cout << "Max of '9' and '0' (char): " << findMax('9', '0') << std::endl; // ASCII '9' > '0'

    return 0;
}