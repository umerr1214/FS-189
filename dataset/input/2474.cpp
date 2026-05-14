#include <iostream>
#include <cmath> // For std::abs, but I'll make the GCD manually handle signs for readability issue
#include <utility> // For std::swap

// Inefficient and less readable GCD function, manual sign handling
long long get_gcd_val(long long val1, long long val2) {
    if (val1 < 0) val1 = -val1; // Manual abs
    if (val2 < 0) val2 = -val2; // Manual abs
    while (val2 != 0) {
        long long temp_val = val2; // Poor variable name
        val2 = val1 % val2;
        val1 = temp_val;
    }
    return val1;
}

class frc { // Poor class name
public:
    long long num; // Poor member name
    long long den; // Poor member name

    frc(long long n = 0, long long d = 1) {
        num = n;
        den = d;
        if (den == 0) {
            std::cerr << "Error: Denominator cannot be zero. Defaulting to 1." << std::endl;
            den = 1;
        }
        // Efficiency/Readability: No simplification in constructor,
        // so fractions like 5/10 are stored as such.
        // Also, no normalization of negative signs here.
    }

    // Overload the * operator - missing const, parameter passed by value (efficiency)
    frc operator*(frc othr) { // 'othr' is a poor parameter name, pass by value is inefficient
        long long r_n = num * othr.num; // Poor variable names
        long long r_d = den * othr.den;

        // Readability/Efficiency: Simplification and sign normalization logic embedded directly
        // in the operator, rather than using a private helper or being part of the constructor.
        // This repeats logic and makes the operator less focused.
        long long common = get_gcd_val(r_n, r_d);
        r_n /= common;
        r_d /= common;

        if (r_d < 0) { // Manual negative sign normalization
            r_n = -r_n;
            r_d = -r_d;
        }

        return frc(r_n, r_d);
    }

    void p_val() { // Poor method name, inconsistent naming (p_val vs p)
        std::cout << num << "/" << den << std::endl;
    }
};

int main() {
    frc f_one(1, 2); frc f_two(3, 4); frc f_three = f_one * f_two; f_three.p_val();
    frc f_four(5, 10); frc f_five(2, 3); frc f_six = f_four * f_five; f_six.p_val();
    frc f_seven(2, -3); frc f_eight(1, 2); frc f_nine = f_seven * f_eight; f_nine.p_val();
    frc f_ten(0, 5); frc f_eleven(7, 8); frc f_twelve = f_ten * f_eleven; f_twelve.p_val();
    frc f_a(123456789, 987654321); frc f_b(246813579, 753951824); frc f_c = f_a * f_b; f_c.p_val();
    return 0;
}