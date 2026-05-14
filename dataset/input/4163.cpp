#include <iostream>
#include <string>

// Function template to return the larger of two comparable values
template <typename T>
T getLarger(T val1, T val2) {
    // Logical error: This function incorrectly returns the smaller value
    // It should be 'if (val1 > val2)' or 'return (val1 > val2) ? val1 : val2;'
    if (val1 < val2) { // Incorrect comparison for "larger"
        return val1;   // Returns the smaller value if val1 is smaller
    } else {
        return val2;   // Returns val2 if val1 is larger or equal (still incorrect if val1 was larger)
    }
}

int main() {
    // Demonstrate with int
    int int1 = 10;
    int int2 = 20;
    std::cout << "Comparing " << int1 << " and " << int2 << ": Larger is " << getLarger(int1, int2) << std::endl; // Expected: 20, Actual: 10

    // Demonstrate with double
    double double1 = 15.5;
    double double2 = 7.3;
    std::cout << "Comparing " << double1 << " and " << double2 << ": Larger is " << getLarger(double1, double2) << std::endl; // Expected: 15.5, Actual: 7.3

    // Demonstrate with char
    char char1 = 'a';
    char char2 = 'z';
    std::cout << "Comparing " << char1 << " and " << char2 << ": Larger is " << getLarger(char1, char2) << std::endl; // Expected: z, Actual: a

    // Demonstrate with equal values
    int int3 = 5;
    int int4 = 5;
    std::cout << "Comparing " << int3 << " and " << int4 << ": Larger is " << getLarger(int3, int4) << std::endl; // Expected: 5, Actual: 5 (correct for equality)

    return 0;
}