#include <iostream>
#include <string>

// Robustness Issue:
// The function template returns a const reference to one of its arguments.
// While efficient for large objects, this design can lead to a dangling reference
// if the arguments passed to the function are temporaries or go out of scope
// before the returned reference is used. For fundamental types like int and double,
// this might be optimized by the compiler to return a value, but conceptually
// it's a design flaw for a generic template if argument lifetime is not guaranteed.
template <typename T>
const T& find_maximum(const T& a, const T& b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    // Test with int
    int int_val1 = 10;
    int int_val2 = 20;
    const int& max_int_ref = find_maximum(int_val1, int_val2);
    std::cout << "Maximum of " << int_val1 << " and " << int_val2 << " (int): " << max_int_ref << std::endl;

    // Test with double
    double double_val1 = 15.5;
    double double_val2 = 10.2;
    const double& max_double_ref = find_maximum(double_val1, double_val2);
    std::cout << "Maximum of " << double_val1 << " and " << double_val2 << " (double): " << max_double_ref << std::endl;

    // Example of potential dangling reference (though not directly exposed by current output)
    // For instance, if `find_maximum(T(), T())` was called, the returned reference would dangle.
    // However, for basic types and lvalue inputs, it typically works due to optimizations or direct use.

    return 0;
}