#include <iostream> // Required for std::ostream, std::cout, std::endl
#include <string>   // Required for std::string (though not directly used in operator<<)
#include <vector>   // Required for std::vector in main driver
#include <sstream>  // Required for std::stringstream in main driver
#include <cmath>    // Required for std::abs

class ComplexNumber {
public:
    double real;
    double imaginary;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Friend declaration for the overloaded '<<' operator
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);
};

// Correct Version:
// This overloaded '<<' operator correctly formats ComplexNumber objects
// according to the specified format "real + imaginaryi".
// It correctly handles positive and zero imaginary parts by using '+'
// and negative imaginary parts by using '-' followed by the absolute value
// of the imaginary component, ensuring standard mathematical representation.
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << c.real;
    if (c.imaginary >= 0) {
        os << " + " << c.imaginary << "i";
    } else {
        os << " - " << std::abs(c.imaginary) << "i";
    }
    return os;
}

int main() {
    // Driver code to test the ComplexNumber class and its overloaded '<<' operator.
    // It creates several ComplexNumber objects and prints them to standard output.
    // The output will be captured and compared against expected values in the JSON.
    std::vector<std::pair<double, double>> inputs = {{3.0, 4.5}, {1.0, -2.0}, {0.0, 5.0}, {7.0, 0.0}, {0.0, 0.0}, {-2.5, -3.0}};
    for (const auto& p : inputs) {
        ComplexNumber c(p.first, p.second);
        std::cout << c << std::endl;
    }
    return 0;
}