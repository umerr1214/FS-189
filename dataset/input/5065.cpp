#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    // Initialize variables to make output predictable if cin fails
    double length = 0.0;
    double width = 0.0;

    std::cout << "Enter length: ";
    std::cin >> length;

    std::cout << "Enter width: ";
    std::cin >> width;

    // This version lacks robustness:
    // 1. It does not handle non-numeric input. If `std::cin >> double_var` fails,
    //    the failbit is set, the variable might retain its initial value (0.0 here),
    //    and subsequent `std::cin` operations will also fail without clearing the error.
    // 2. It does not validate for negative or zero dimensions, which are not
    //    meaningful for real-world rectangle measurements. Calculations will proceed
    //    with these invalid values.

    double area = length * width;
    double perimeter = 2 * (length + width);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}