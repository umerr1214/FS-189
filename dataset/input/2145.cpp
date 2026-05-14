#include <iostream>
#include <numeric> // Not using std::gcd, implementing custom for full control
#include <cmath>   // For std::abs
#include <string>
#include <sstream>
#include <stdexcept> // For std::invalid_argument
#include <utility> // For std::swap

// Helper GCD function (efficient Euclidean algorithm)
int gcd_2145(int a, int b) {
    a = std::abs(a); // Ensure positive inputs for GCD
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        if (numerator == 0) {
            denominator = 1; // 0/X simplifies to 0/1
            return;
        }

        // denominator is guaranteed to be non-zero by constructor
        int common = gcd_2145(numerator, denominator);
        numerator /= common;
        denominator /= common;

        // Ensure denominator is always positive for consistent representation
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor with default values, validates denominator
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify(); // Simplify on construction to maintain canonical form
    }

    // Overload the binary * operator
    Fraction operator*(const Fraction& other) const {
        // Create a new fraction from multiplication, the constructor
        // of the result will automatically call simplify().
        return Fraction(
            this->numerator * other.numerator,
            this->denominator * other.denominator
        );
    }

    // Friend function to overload the stream insertion operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};

// Driver for test cases
void run_test(const std::string& input_str, const std::string& expected_output) {
    std::istringstream iss(input_str);
    char slash;
    int n1, d1, n2, d2;

    try {
        iss >> n1 >> slash >> d1;
        Fraction f1(n1, d1);

        iss >> n2 >> slash >> d2;
        Fraction f2(n2, d2);
        
        Fraction result = f1 * f2;
        
        std::ostringstream oss;
        oss << result;
        std::string actual_output = oss.str();

        if (actual_output == expected_output) {
            std::cout << "Test passed: " << input_str << " -> " << actual_output << "\n";
        } else {
            std::cout << "Test failed: " << input_str << ". Expected: " << expected_output << ", Got: " << actual_output << "\n";
        }
    } catch (const std::invalid_argument& e) {
        if (expected_output == "ERROR: " + std::string(e.what())) {
            std::cout << "Test passed (exception): " << input_str << " -> " << e.what() << "\n";
        } else {
            std::cout << "Test failed (unexpected exception): " << input_str << ". Exception: " << e.what() << ". Expected: " << expected_output << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Test failed (unexpected runtime error): " << input_str << ". Error: " << e.what() << "\n";
    } catch (...) {
        std::cout << "Test failed (unknown error - possibly crash or division by zero): " << input_str << "\n";
    }
}

int main() {
    // Test cases will be inserted here by the JSON driver.
    // Example:
    // run_test("1/2 3/4", "3/8");
    return 0;
}