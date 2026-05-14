#include <iostream>
#include <string> // For char comparison example

// Robustness Issue: The function template's return type is fixed to the type of the first argument (T1),
// which can lead to implicit type conversions and potential data loss or unexpected results
// when comparing arguments of different types (e.g., `findMax(int, double)` might truncate the double).
template <typename T1, typename T2>
T1 findMax(T1 a, T2 b) {
    // For demonstration, print types involved.
    // In a real scenario, this implicit cast to T1 could be problematic.
    return (a > b) ? a : static_cast<T1>(b);
}

int main() {
    // Demonstrate with int
    int maxInt = findMax(10, 20);
    std::cout << "Max of 10 and 20 (int): " << maxInt << std::endl; // Expected: 20

    // Demonstrate with double
    double maxDouble = findMax(3.14, 2.71);
    std::cout << "Max of 3.14 and 2.71 (double): " << maxDouble << std::endl; // Expected: 3.14

    // Demonstrate with mixed types - Robustness Issue here
    // T1 is int, T2 is double. double 5.5 will be cast to int 5, losing precision.
    int maxMixedInt = findMax(5, 5.5);
    std::cout << "Max of 5 and 5.5 (int, double -> int): " << maxMixedInt << std::endl; // Expected: 5 (Incorrect, should be 5.5)

    // T1 is double, T2 is int. int 5 will be cast to double 5.0. This is generally fine.
    double maxMixedDouble = findMax(5.5, 5);
    std::cout << "Max of 5.5 and 5 (double, int -> double): " << maxMixedDouble << std::endl; // Expected: 5.5 (Correct)

    // Demonstrate with char
    char maxChar = findMax('a', 'z');
    std::cout << "Max of 'a' and 'z' (char): " << maxChar << std::endl; // Expected: z

    // Demonstrate with mixed char and int
    // T1 is char, T2 is int. int 100 ('d') will be cast to char.
    char maxMixedChar = findMax('c', 100); // 100 is ASCII for 'd'
    std::cout << "Max of 'c' and 100 (char, int -> char): " << maxMixedChar << std::endl; // Expected: d (Correct, but implicit conversion)

    return 0;
}