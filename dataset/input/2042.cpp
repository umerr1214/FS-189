#include <iostream> // Required for std::ostream, std::cout, std::endl
#include <string>   // Required for std::string (used by stringstream)
#include <vector>   // Required for std::vector in main driver
#include <sstream>  // Required for std::stringstream (used in operator<< and main driver)
#include <cmath>    // Required for std::abs

class ComplexNumber {
public:
    double real;
    double imaginary;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Friend declaration for the overloaded '<<' operator
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);
};

// Readability / Efficiency Issue:
// This operator uses a std::stringstream to build the complete output string
// before printing it to the output stream. While functionally correct, this
// approach is less efficient than directly streaming the components to the
// std::ostream. It incurs overhead from string construction and copying,
// and makes the code slightly more verbose and less direct than necessary.
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    std::stringstream ss; // Unnecessary use of stringstream
    ss << c.real;
    if (c.imaginary >= 0) {
        ss << " + " << c.imaginary << "i";
    } else {
        ss << " - " << std::abs(c.imaginary) << "i";
    }
    os << ss.str(); // Print the entire string from stringstream
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