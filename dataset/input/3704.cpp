#include <iostream>

// Function template with a readability/efficiency issue:
// The logic is overly verbose and uses redundant checks for a simple comparison.
template <typename T>
T findMax(T a, T b) {
    T result;
    bool a_is_definitely_greater = false;
    bool b_is_definitely_greater = false;

    if (a > b) {
        a_is_definitely_greater = true;
    } else { // a <= b
        if (b > a) {
            b_is_definitely_greater = true;
        } else { // a == b
            // If they are equal, we can pick either, let's say 'a'
            a_is_definitely_greater = true; 
        }
    }

    if (a_is_definitely_greater && !b_is_definitely_greater) {
        result = a;
    } else if (b_is_definitely_greater && !a_is_definitely_greater) {
        result = b;
    } else { // This branch handles a==b or unexpected states
        result = a; // Default to 'a' if logic is ambiguous (e.g., a==b)
    }
    return result;
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