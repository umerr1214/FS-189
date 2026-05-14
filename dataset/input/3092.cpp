#include <iostream>
#include <string>
#include <sstream>
#include <cmath> // For std::abs
#include <stdexcept> // For std::runtime_error

class Fraction {
private:
    int n; // Unclear variable name for numerator
    int d; // Unclear variable name for denominator

    // Inefficient GCD implementation (Readability/Efficiency Issue)
    // This method is correct but performs poorly for large numbers compared to Euclidean algorithm.
    int find_gcd_slow(int a_val, int b_val) {
        a_val = std::abs(a_val);
        b_val = std::abs(b_val);
        if (a_val == 0) return b_val;
        if (b_val == 0) return a_val;
        int min_val = (a_val < b_val) ? a_val : b_val;
        for (int i = min_val; i >= 1; --i) { // Iterating downwards, correct but slow
            if (a_val % i == 0 && b_val % i == 0) {
                return i;
            }
        }
        return 1; // Should not be reached for positive integers
    }

    void s_frac() { // Unclear method name for simplify (Readability Issue)
        if (d == 0) {
            throw std::runtime_error("Denominator cannot be zero."); // Correct handling, but efficiency/readability is the issue.
        }
        if (n == 0) {
            d = 1;
            return;
        }

        // Ensure denominator is positive
        if (d < 0) {
            n = -n;
            d = -d;
        }

        int common_divisor = find_gcd_slow(n, d); // Calls inefficient GCD
        n /= common_divisor;
        d /= common_divisor;
    }

public:
    Fraction(int num_val, int den_val) : n(num_val), d(den_val) { // Unclear variable names
        if (d == 0) {
            throw std::runtime_error("Denominator cannot be zero.");
        }
        s_frac(); // Simplify on construction
    }

    // Friend declaration
    friend Fraction operator*(const Fraction& f_one, const Fraction& f_two); // Unclear parameter names

    void display() const { // Unclear method name for print (Readability Issue)
        std::cout << n << "/" << d;
    }
};

// Overload the binary * operator as a non-member (friend) function
Fraction operator*(const Fraction& f_one, const Fraction& f_two) { // Unclear parameter names
    // Redundant intermediate variables (Readability Issue)
    int temp_num = f_one.n * f_two.n;
    int temp_den = f_one.d * f_two.d;
    Fraction res(temp_num, temp_den); // Creates a new Fraction object, constructor calls s_frac().
    return res;
}

// Driver code to run test cases (Readability Issue: lack of comments, unclear names)
void test_fraction_ops(const std::string& input_str, const std::string& expected_str) {
    std::stringstream ss(input_str);
    std::string t1, t2; // Unclear variable names
    ss >> t1 >> t2;

    int n1, d1, n2, d2;
    size_t pos_slash;

    pos_slash = t1.find('/');
    n1 = std::stoi(t1.substr(0, pos_slash));
    d1 = std::stoi(t1.substr(pos_slash + 1));

    pos_slash = t2.find('/');
    n2 = std::stoi(t2.substr(0, pos_slash));
    d2 = std::stoi(t2.substr(pos_slash + 1));

    try {
        Fraction fr1(n1, d1);
        Fraction fr2(n2, d2);
        Fraction mult_res = fr1 * fr2;

        std::cout << "Input: " << input_str << ", Result: ";
        mult_res.display();
        std::cout << " (Expected: " << expected_str << ")" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Input: " << input_str << ", Error: " << e.what() << " (Expected: " << expected_str << ")" << std::endl;
    }
}

int main() {
    test_fraction_ops("1/2 1/3", "1/6");
    test_fraction_ops("1/2 2/3", "1/3");
    test_fraction_ops("-1/2 1/3", "-1/6");
    test_fraction_ops("2/1 3/4", "3/2");
    test_fraction_ops("0/5 7/8", "0/1");
    test_fraction_ops("4/6 9/12", "3/4");
    test_fraction_ops("1/-2 1/3", "-1/6");
    test_fraction_ops("1/0 1/2", "Error: Denominator cannot be zero."); // This will now throw an exception
    
    return 0;
}