#include <iostream>
#include <string>
#include <cmath>   // For std::abs
#include <stdexcept> // For std::invalid_argument (though a crash is intended for specific cases)

class Fraction {
private:
    int numerator;
    int denominator;

    // A potentially flawed gcd implementation for robustness issue
    // This gcd will return 0 for gcd(0,0), leading to division by zero later.
    int calculate_gcd(int a, int b) const {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a; // If a=0, b=0, this returns 0.
    }

    void simplify() {
        if (denominator == 0) {
            // Robustness issue: If numerator is also 0, calculate_gcd(0,0) returns 0.
            // The subsequent division will cause a crash.
            // If numerator is non-zero, this branch doesn't simplify, leading to an invalid state.
            // The main robustness flaw is the crash for 0/0.
            if (numerator == 0) {
                // This specific case (0/0) will lead to common_divisor = 0
                // and then division by zero below.
            }
            // No explicit throw here, allowing the division by zero to occur.
            return;
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        
        int common_divisor = calculate_gcd(numerator, denominator);
        // Robustness issue: If common_divisor is 0 (e.g., from Fraction(0,0)), this will crash.
        // This is the intended division by zero crash point.
        numerator /= common_divisor; 
        denominator /= common_divisor;
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        // Robustness issue: No check for denominator == 0 in constructor.
        // Allows creation of invalid fractions like Fraction(1,0) or Fraction(0,0).
        // Simplification is deferred to the == operator, where the crash occurs.
    }

    // Overload the == operator
    bool operator==(const Fraction& other) const {
        // Create temporary simplified fractions for comparison
        Fraction this_copy = *this;
        Fraction other_copy = other;

        // Robustness issue: simplify() will crash if denominator is 0 and numerator is also 0.
        // e.g., Fraction(0,0) == Fraction(0,0) will cause a division by zero in simplify().
        this_copy.simplify(); 
        other_copy.simplify();

        return this_copy.numerator == other_copy.numerator &&
               this_copy.denominator == other_copy.denominator;
    }

    // For printing in test cases
    std::string toString() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
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