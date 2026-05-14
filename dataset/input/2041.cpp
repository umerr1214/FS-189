#include <iostream> // Required for std::ostream, std::cout, std::endl
#include <string>   // Required for std::string (though not directly used in operator<<, good practice)
#include <vector>   // Required for std::vector in main driver
#include <sstream>  // Required for std::stringstream in main driver
#include <cmath>    // Required for std::abs, but intentionally not used correctly in this version

class ComplexNumber {
public:
    double real;
    double imaginary;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Friend declaration for the overloaded '<<' operator
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);
};

// Robustness Issue:
// This operator simply prints "real + imaginaryi".
// It fails to handle negative imaginary parts by changing the '+' to a '-' sign.
// For example, for a complex number 1.0 - 2.0i, it will incorrectly print "1.0 + -2.0i"
// instead of the standard "1.0 - 2.0i". This is a robustness issue as it produces
// non-standard and potentially confusing output for valid inputs.
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << c.real << " + " << c.imaginary << "i";
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