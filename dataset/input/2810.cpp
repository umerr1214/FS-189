#include <iostream>
#include <string>
#include <cmath> // For std::abs

class Fraction {
private:
    int num; // Poor naming: 'num' instead of 'numerator'
    int den; // Poor naming: 'den' instead of 'denominator'

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        // Readability/Efficiency issue: No simplification in constructor,
        // relying on == operator to simplify fractions on the fly.
        // No check for den == 0 here, relying on == operator to handle it.
    }

    // Overload the == operator
    bool operator==(const Fraction& other) const {
        // Efficiency issue: gcd logic is duplicated and not encapsulated.
        // Readability issue: inline gcd, poor variable names, long function.

        // Create copies to simplify for comparison
        int n1 = num;
        int d1 = den;
        int n2 = other.num;
        int d2 = other.den;

        // Handle negative denominators for 'this' fraction to normalize sign
        if (d1 < 0) {
            n1 = -n1;
            d1 = -d1;
        }
        // Handle negative denominators for 'other' fraction to normalize sign
        if (d2 < 0) {
            n2 = -n2;
            d2 = -d2;
        }

        // Basic handling for division by zero to prevent crashes, but not canonical
        if (d1 == 0 && n1 != 0) return false; // Undefined fraction cannot equal anything (arbitrary choice)
        if (d2 == 0 && n2 != 0) return false;
        if (d1 == 0 && d2 == 0) return (n1 == 0 && n2 == 0); // 0/0 == 0/0 (arbitrary choice, potentially incorrect)
        if (d1 == 0) return false; // only one is 0/0
        if (d2 == 0) return false;

        // Calculate GCD for 'this' fraction (duplicated logic)
        // Inefficient: Repeated calculation for every comparison.
        int temp_n1 = std::abs(n1);
        int temp_d1 = std::abs(d1);
        while (temp_d1 != 0) {
            int t = temp_d1;
            temp_d1 = temp_n1 % temp_d1;
            temp_n1 = t;
        }
        int common_divisor1 = temp_n1;
        
        // Simplify 'this' fraction
        n1 /= common_divisor1;
        d1 /= common_divisor1;

        // Calculate GCD for 'other' fraction (duplicated logic)
        // Inefficient: Repeated calculation for every comparison.
        int temp_n2 = std::abs(n2);
        int temp_d2 = std::abs(d2);
        while (temp_d2 != 0) {
            int t = temp_d2;
            temp_d2 = temp_n2 % temp_d2;
            temp_n2 = t;
        }
        int common_divisor2 = temp_n2;

        // Simplify 'other' fraction
        n2 /= common_divisor2;
        d2 /= common_divisor2;

        return n1 == n2 && d1 == d2;
    }

    // For printing in test cases
    std::string toString() const {
        return std::to_string(num) + "/" + std::to_string(den);
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