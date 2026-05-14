#include <iostream>
#include <cmath> // For std::pow
#include <iomanip> // For std::fixed, std::setprecision

// Readability/Efficiency Issue: Using a macro for PI instead of M_PI or constexpr.
#define PI_APPROX 3.1415926535

// Base class with unclear name and missing const qualifier on virtual method.
class BaseShape_Abstract {
public:
    // Readability Issue: Missing 'const' qualifier, though it doesn't modify state.
    virtual double calculateArea_Method() = 0;
    virtual ~BaseShape_Abstract() {} // Correct destructor, but name is inconsistent.
};

// Derived class with unclear name and inefficient calculation.
class DerivedCircle_Obj : public BaseShape_Abstract {
private:
    double r_val; // Readability Issue: Obfuscated variable name.
public:
    DerivedCircle_Obj(double input_r) : r_val(input_r) {}

    // Readability Issue: Missing 'const' qualifier.
    // Efficiency Issue: Uses std::pow for squaring and an unnecessary temporary variable.
    double calculateArea_Method() override {
        double temp_radius_holder = this->r_val; // Unnecessary temporary variable.
        double computed_area = PI_APPROX * std::pow(temp_radius_holder, 2.0); // Inefficient squaring.
        return computed_area;
    }

    double retrieveRadius() const { return r_val; } // Good practice here, but inconsistent elsewhere.
};

int main() {
    std::cout << "Demonstrating Readability / Efficiency Issues:" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    // Readability Issue: Poor variable naming.
    BaseShape_Abstract* my_poly_shape_ptr = new DerivedCircle_Obj(8.0);

    std::cout << "Attempting to calculate area using the polymorphic pointer..." << std::endl;
    std::cout << "The result of area calculation is: "
              << std::fixed << std::setprecision(3)
              << my_poly_shape_ptr->calculateArea_Method()
              << " square units. Have a nice day!" << std::endl; // Overly verbose output.

    delete my_poly_shape_ptr;
    my_poly_shape_ptr = nullptr;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Code functions correctly but is hard to read and has minor inefficiencies." << std::endl;

    return 0;
}