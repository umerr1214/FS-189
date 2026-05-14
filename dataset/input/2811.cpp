#include <iostream>
#include <string>
#include <numeric> // For std::gcd in C++17, but implementing for broader compatibility.
#include <cmath>   // For std::abs
#include <stdexcept> // For std::invalid_argument

class Fraction {
private:
    int numerator;
    int denominator;

    // Helper function to calculate GCD using Euclidean algorithm
    static int calculate_gcd(int a, int b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Simplifies the fraction to its canonical form
    void simplify() {
        // This method assumes denominator is not zero, as handled by constructor.
        // If denominator were 0, it would be an invalid state.

        // Ensure denominator is positive for a canonical form (e.g., 1/-2 becomes -1/2)
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        // Simplify using GCD, only if numerator is not zero to avoid gcd(0,X) issues
        // and ensure 0/X simplifies to 0/1.
        if (numerator == 0) {
            denominator = 1; // Canonical form for zero fraction is 0/1
        } else {
            int common_divisor = calculate_gcd(numerator, denominator);
            // common_divisor should never be 0 here because numerator is not 0.
            numerator /= common_divisor;
            denominator /= common_divisor;
        }
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify(); // Simplify and normalize on construction to ensure canonical form
    }

    // Overload the == operator
    // Since fractions are simplified and normalized in the constructor,
    // comparison is straightforward and efficient.
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator &&
               denominator == other.denominator;
    }

    // For printing in test cases (optional, but good for debugging/display)
    std::string toString() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
    
    // Getters for testing/display purposes (optional)
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
};

// Driver code to run test cases from stdin
int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        size_t comma_pos = line.find(',');
        std::string s_f1 = line.substr(0, comma_pos);
        std::string s_f2 = line.substr(comma_pos + 1);

        int n1 = std::stoi(s_f1.substr(0, s_f1.find('/')));
        int d1 = std::stoi(s_f1.substr(s_f1.find('/') + 1));
        int n2 = std::stoi(s_f2.substr(0, s_f2.find('/')));
        int d2 = std::stoi(s_f2.substr(s_f2.find('/') + 1));

        try {
            Fraction f1(n1, d1);
            Fraction f2(n2, d2);
            std::cout << (f1 == f2 ? "true" : "false") << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "EXCEPTION: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "GENERAL_EXCEPTION: " << e.what() << std::endl;
        } catch (...) {
            std::cout << "UNKNOWN_ERROR" << std::endl;
        }
    }
    return 0;
}