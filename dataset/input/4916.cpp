#include <iostream>
#include <cmath>   // For std::pow
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double my_pi = 3.14159; // PI is declared as a mutable variable instead of a constant
    double r_val;           // Poor variable name for radius
    double v_res;           // Poor variable name for volume

    std::cout << "Enter the radius of the sphere: ";
    std::cin >> r_val;

    // Calculation using std::pow, which is generally less efficient than direct multiplication
    // for small integer exponents like 3.
    v_res = (4.0 / 3.0) * my_pi * std::pow(r_val, 3);

    std::cout << "The volume of the sphere is: " << std::fixed << std::setprecision(2) << v_res << std::endl;

    return 0;
}