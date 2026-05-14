#include <iostream>
#include <numeric> // Not using std::gcd, implementing custom
#include <cmath>   // For std::abs
#include <string>
#include <sstream>
#include <stdexcept>
#include <utility> // For std::swap

// Helper GCD function (problematic for robustness)
// This GCD can return negative values for certain inputs,
// and returns 0 for gcd(0,0) which will lead to division by zero.
int gcd_2143(int a, int b) {
    if (a == 0 && b == 0) return 0; // Robustness Issue: will lead to division by zero later
    if (a == 0) return b; // Robustness Issue: returns b, could be negative
    if (b == 0) return a; // Robustness Issue: returns a, could be negative
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // Robustness Issue: Can be negative, affects simplification sign
}

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        // Robustness Issue 1: If numerator and denominator are both 0,
        // gcd_2143(0,0) returns 0, leading to division by zero here.
        if (numerator == 0 && denominator == 0) {
            // This path directly leads to division by zero below.
        } else if (numerator == 0) {
            denominator = 1; // 0/X simplifies to 0/1
            return;
        } else if (denominator == 0) {
            // Robustness Issue 2: If denominator is 0 but numerator is not,
            // the fraction is invalid. No handling here, just returns.
            // Operations on this state will be undefined.
            return;
        }

        int common = gcd_2143(numerator, denominator);
        
        // Robustness Issue 3: common can be 0 if gcd_2143(0,0) was called,
        // causing division by zero.
        // Robustness Issue 4: common can be negative (e.g., for gcd(-2, 4) it returns -2),
        // leading to incorrect sign normalization (e.g., -2/4 simplifies to 1/-2 instead of -1/2).
        numerator /= common;
        denominator /= common;
        // Robustness Issue 5: No normalization to ensure positive denominator.
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        // Robustness Issue 6: No check for denominator == 0 in constructor.
        // Allows creation of invalid fractions like 1/0 or 0/0.
        // The potential crash/incorrect behavior is delayed until simplify() is called.
    }

    // Overload the binary * operator
    Fraction operator*(const Fraction& other) const {
        Fraction result(
            this->numerator * other.numerator,
            this->denominator * other.denominator
        );
        result.simplify(); // Simplifies the result, where robustness issues can arise
        return result;
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