#include <iostream>
#include <string>

// Function template to return the larger of two comparable values
template <typename T>
T getLarger(T val1, T val2) {
    if (val1 > val2) {
        return val1;
    } else {
        return val2;
    }
}

int main() {
    // Demonstrate with int
    int int1 = 10;
    int int2 = 20;
    std::cout << "Comparing " << int1 << " and " << int2 << ": Larger is " << getLarger(int1, int2) << std::endl;

    // Demonstrate with double
    double double1 = 15.5;
    double double2 = 7.3;
    std::cout << "Comparing " << double1 << " and " << double2 << ": Larger is " << getLarger(double1, double2) << std::endl;

    // Demonstrate with char
    char char1 = 'a';
    char char2 = 'z';
    std::cout << "Comparing " << char1 << " and " << char2 << ": Larger is " << getLarger(char1, char2) << std::endl;

    // Demonstrate with equal values
    int int3 = 5;
    int int4 = 5;
    std::cout << "Comparing " << int3 << " and " << int4 << ": Larger is " << getLarger(int3, int4) << std::endl;
} // Missing closing brace for main function - SYNTAX ERROR