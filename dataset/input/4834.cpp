#include <iostream>

template <typename T>
T findMin(T val1, T val2) {
    return (val1 < val2) ? val1 : val2 // Missing semicolon here
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