#include <iostream>
#include <string>
#include <sstream>
#include <cmath> // For std::abs

class Fraction {
private:
    int numerator;
    int denominator;

    // Helper function for GCD (Euclidean algorithm)
    // This implementation is robust for inputs including zero, but the class's usage isn't.
    int calculateGCD(int a, int b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        // Robustness issue 1: No explicit check or handling for denominator == 0 here.
        // If denominator is 0, it remains 0, leading to an invalid fraction state.
        if (numerator == 0) {
            denominator = 1; // Simplify 0/X to 0/1
            return;
        }

        int common_divisor = calculateGCD(numerator, denominator);
        // Robustness issue 2: If common_divisor is 0 (only if numerator and denominator are both 0),
        // this would cause division by zero. Assuming valid inputs don't include 0/0.
        // If Fraction(X,0) is created, common_divisor will be abs(X).
        // numerator /= abs(X), denominator /= abs(X) still leaves denominator as 0.
        numerator /= common_divisor;
        denominator /= common_divisor;

        // Robustness issue 3: Does not normalize sign.
        // If denominator is negative (e.g., 1/-2), it remains negative (1/-2 instead of -1/2).
    }

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        // Robustness issue 4: No check for denominator == 0 in the constructor.
        // This allows creation of invalid fractions like 1/0.
        // The problem will manifest when simplify() is called or when printing.
        simplify(); // Simplify on construction.
    }

    // Friend declaration for the non-member operator*
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);

    void print() const {
        // Robustness issue 5: If denominator is 0, this will print an invalid mathematical expression like "1/0".
        // A robust implementation would handle this by throwing an exception or printing an error message.
        std::cout << numerator << "/" << denominator;
    }
};

// Overload the binary * operator as a non-member (friend) function
Fraction operator*(const Fraction& f1, const Fraction& f2) {
    int newNum = f1.numerator * f2.numerator;
    int newDen = f1.denominator * f2.denominator;
    // The constructor of Fraction (which calls simplify) will handle the new fraction,
    // potentially propagating the robustness issues.
    return Fraction(newNum, newDen);
}

// Driver code to run test cases
void run_test_cases(const std::string& input_str, const std::string& expected_str) {
    std::stringstream ss(input_str);
    std::string token;
    
    std::getline(ss, token, ' ');
    int num1 = std::stoi(token.substr(0, token.find('/')));
    int den1 = std::stoi(token.substr(token.find('/') + 1));
    Fraction f1(num1, den1);

    std::getline(ss, token, ' ');
    int num2 = std::stoi(token.substr(0, token.find('/')));
    int den2 = std::stoi(token.substr(token.find('/') + 1));
    Fraction f2(num2, den2);

    Fraction result = f1 * f2;

    std::cout << "Input: " << input_str << ", Result: ";
    result.print(); 
    std::cout << " (Expected: " << expected_str << ")" << std::endl;
}

int main() {
    std::cout << "Test Case: 1/2 * 1/3" << std::endl;
    run_test_cases("1/2 1/3", "1/6");
    std::cout << "Test Case: 1/2 * 2/3" << std::endl;
    run_test_cases("1/2 2/3", "1/3");
    std::cout << "Test Case: -1/2 * 1/3" << std::endl;
    run_test_cases("-1/2 1/3", "-1/6");
    std::cout << "Test Case: 2/1 * 3/4" << std::endl;
    run_test_cases("2/1 3/4", "3/2");
    std::cout << "Test Case: 0/5 * 7/8" << std::endl;
    run_test_cases("0/5 7/8", "0/1");
    std::cout << "Test Case: 4/6 * 9/12" << std::endl;
    run_test_cases("4/6 9/12", "3/4");
    std::cout << "Test Case: 1/-2 * 1/3 (Sign normalization issue)" << std::endl;
    run_test_cases("1/-2 1/3", "1/-6"); // Expected -1/6, but code outputs 1/-6 due to lack of sign normalization
    std::cout << "Test Case: 1/0 * 1/2 (Division by zero issue)" << std::endl;
    run_test_cases("1/0 1/2", "1/0"); // Expected an error or special handling, but code outputs 1/0 due to lack of denominator validation

    return 0;
}