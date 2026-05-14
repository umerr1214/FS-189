#include <iostream>
#include <cstdlib> // Provides std::abs for integer types, but not primarily for floating-point types

template <typename T>
T get_absolute_value(T val)
{
    // Semantic error: Relying on <cstdlib> for std::abs overloads for floating-point types.
    // While it might compile due to transitive includes or compiler specifics,
    // the correct header for std::abs for float/double is <cmath>.
    return std::abs(val);
}

int main()
{
    // Demonstrate with int
    int int_val1 = -10;
    int int_val2 = 5;
    std::cout << "Absolute value of " << int_val1 << " (int): " << get_absolute_value(int_val1) << std::endl;

    // Demonstrate with double
    double double_val1 = -10.5;
    double double_val2 = 7.25;
    std::cout << "Absolute value of " << double_val1 << " (double): " << get_absolute_value(double_val1) << std::endl;
    std::cout << "Absolute value of " << double_val2 << " (double): " << get_absolute_value(double_val2) << std::endl;

    // Demonstrate with float
    float float_val1 = -3.14f;
    float float_val2 = 2.71f;
    std::cout << "Absolute value of " << float_val1 << " (float): " << get_absolute_value(float_val1) << std::endl;
    std::cout << "Absolute value of " << float_val2 << " (float): " << get_absolute_value(float_val2) << std::endl;

    return 0;
}