#include <iostream>
#include <string>
#include <sstream>
#include <cmath>   // For std::abs
#include <stdexcept> // For std::runtime_error

// The Fraction class represents a rational number with integer numerator and denominator.
class Fraction {
private:
    int numerator;
    int denominator;

    // Private helper function to calculate the Greatest Common Divisor (GCD)
    // using the Euclidean algorithm. Ensures positive result.
    int calculateGCD(int a, int b) const {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Simplifies the fraction by dividing the numerator and denominator by their GCD.
    // Also ensures the denominator is always positive, moving the sign to the numerator if necessary.
    void simplify() {
        // This state should ideally be prevented by the constructor.
        // If it occurs, it's an invalid fraction and we throw an error.
        if (denominator == 0) {
            throw std::runtime_error("Cannot simplify a fraction with zero denominator.");
        }
        
        // If numerator is 0, simplify to 0/1.
        if (numerator == 0) {
            denominator = 1; 
            return;
        }

        // Normalize sign: Ensure denominator is always positive.
        // If denominator is negative, move the sign to the numerator.
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int common_divisor = calculateGCD(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }

public:
    // Constructor: Initializes a Fraction object with given numerator and denominator.
    // Throws std::runtime_error if the denominator is zero, preventing invalid fractions.
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw std::runtime_error("Denominator cannot be zero.");
        }
        simplify(); // Simplify the fraction upon construction
    }

    // Friend declaration for the non-member binary `*` operator.
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);

    // Overload the stream insertion operator (`<<`) for easy and clean printing of Fraction objects.
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};

// Overload the binary `*` operator as a non-member (friend) function.
// Multiplies two Fraction objects and returns a new simplified Fraction object.
Fraction operator*(const Fraction& f1, const Fraction& f2) {
    // Use long long for intermediate products to prevent potential integer overflow
    // before casting back to int for the Fraction constructor.
    long long newNum_ll = static_cast<long long>(f1.numerator) * f2.numerator;
    long long newDen_ll = static_cast<long long>(f1.denominator) * f2.denominator;

    // Create a new Fraction object. Its constructor will handle simplification and validation.
    return Fraction(static_cast<int>(newNum_ll), static_cast<int>(newDen_ll));
}

// Driver function to parse input strings, perform fraction operations, and print results.
void run_fraction_tests(const std::string& input_str, const std::string& expected_str) {
    std::stringstream ss(input_str);
    std::string token1_str, token2_str;
    ss >> token1_str >> token2_str;

    int num1, den1, num2, den2;
    
    // Lambda helper to parse a fraction string into numerator and denominator.
    auto parse_fraction_str = [](const std::string& s, int& num, int& den) {
        size_t slash_pos = s.find('/');
        if (slash_pos == std::string::npos) {
            throw std::runtime_error("Invalid fraction format: " + s);
        }
        num = std::stoi(s.substr(0, slash_pos));
        den = std::stoi(s.substr(slash_pos + 1));
    };

    try {
        // Parse and create the first fraction.
        parse_fraction_str(token1_str, num1, den1);
        Fraction f1(num1, den1);

        // Parse and create the second fraction.
        parse_fraction_str(token2_str, num2, den2);
        Fraction f2(num2, den2);

        // Perform multiplication.
        Fraction result = f1 * f2;

        // Print the result.
        std::cout << "Input: " << input_str << ", Result: " << result << " (Expected: " << expected_str << ")" << std::endl;
    } catch (const std::runtime_error& e) {
        // Catch and report runtime errors (e.g., division by zero).
        std::cout << "Input: " << input_str << ", Caught Exception: " << e.what() << " (Expected: " << expected_str << ")" << std::endl;
    } catch (const std::out_of_range& e) {
        // Catch and report errors from std::stoi if numbers are too large.
        std::cout << "Input: " << input_str << ", Caught Exception (Out of Range): " << e.what() << " (Expected: " << expected_str << ")" << std::endl;
    } catch (const std::invalid_argument& e) {
        // Catch and report errors from std::stoi if string cannot be converted.
        std::cout << "Input: " << input_str << ", Caught Exception (Invalid Argument): " << e.what() << " (Expected: " << expected_str << ")" << std::endl;
    }
}

int main() {
    // Run various test cases to demonstrate functionality and robustness.
    run_fraction_tests("1/2 1/3", "1/6");
    run_fraction_tests("1/2 2/3", "1/3");
    run_fraction_tests("-1/2 1/3", "-1/6");
    run_fraction_tests("2/1 3/4", "3/2");
    run_fraction_tests("0/5 7/8", "0/1");
    run_fraction_tests("4/6 9/12", "3/4");
    run_fraction_tests("1/-2 1/3", "-1/6"); // Correctly normalizes to -1/6
    run_fraction_tests("1/0 1/2", "Error: Denominator cannot be zero."); // Correctly throws exception
    run_fraction_tests("-4/-6 1/2", "1/3"); // Test double negative and simplification

    return 0;
}