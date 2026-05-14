#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            // Handle division by zero, though question doesn't specify.
            // For simplicity in this example, we'll just set it to 1.
            this->denominator = 1; 
        }
    }

    // Overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
} // Missing semicolon here

int main() {
    Fraction f1(3, 4);
    std::cout << f1 << std::endl;

    Fraction f2(1, 2);
    std::cout << f2 << std::endl;
    
    Fraction f3(5, 1);
    std::cout << f3 << std::endl;

    return 0;
}