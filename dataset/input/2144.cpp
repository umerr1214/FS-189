#include <iostream>
#include <numeric> // Not using std::gcd, implementing custom
#include <cmath>   // For std::abs
#include <string>
#include <sstream>
#include <stdexcept>
#include <utility> // For std::swap

// Helper GCD function (inefficient for readability/efficiency issue)
// This uses a naive O(min(a,b)) approach instead of the efficient Euclidean O(log(min(a,b)))
int gcd_2144(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    if (a == 0) return b;
    if (b == 0) return a;
    int result = 1;
    for (int i = 1; i <= a && i <= b; ++i) { // Readability/Efficiency Issue: Inefficient loop for GCD
        if (a % i == 0 && b % i == 0) {
            result = i;
        }
    }
    return result;
}

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        // Denominator is handled in constructor to avoid zero.
        
        int common = gcd_2144(numerator, denominator); // Calls inefficient GCD
        numerator /= common;
        denominator /= common;

        // Ensure denominator is always positive for consistent representation
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        // For readability/efficiency, handling zero denominator by defaulting,
        // rather than throwing an exception, which might be considered less robust
        // but avoids crashes for this category, aiming for correctness=9.
        if (denominator == 0) {
            denominator = 1; // Readability/Efficiency Issue: Simple default, not robust error handling
        }
        simplify(); // Simplify on construction
    }

    // Overload the binary * operator
    Fraction operator*(const Fraction& other) const {
        // The core issue for efficiency is the GCD, not necessarily this operator's structure.
        Fraction result(
            this->numerator * other.numerator,
            this->denominator * other.denominator
        );
        result.simplify(); // Simplifies the result, calling the inefficient GCD
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