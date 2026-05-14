#include <iostream>
#include <cmath> // For std::abs

template <typename T>
T get_absolute_value(T val)
{
    if (val < 0)
    {
        return -val // Missing semicolon here
    }
    return val;
}

int main()
{
    // Demonstrate with int
    int int_val1 = -10;
    int int_val2 = 5;
    std::cout << "Absolute value of " << int_val1 << " (int): " << get_absolute_value(int_val1) << std::endl;
    std::cout << "Absolute value of " << int_val2 << " (int): " << get_absolute_value(int_val2) << std::endl;

    // Demonstrate with double
    double double_val1 = -10.5;
    double double_val2 = 7.25;
    std::cout << "Absolute value of " << double_val1 << " (double): " << get_absolute_value(double_val1) << std::endl;
    std::cout << "Absolute value of " << double_val2 << " (double): " << get_absolute_value(double_val2) << std::endl;

    return 0;
}