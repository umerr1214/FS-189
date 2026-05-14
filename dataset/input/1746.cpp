#include <iostream>

class Fraction {
public: // Semantic error: Members are public instead of private
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            // Handle division by zero
            this->denominator = 1; 
        }
    }

    // Overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};

int main() {
    Fraction f1(3, 4);
    std::cout << f1 << std::endl;

    Fraction f2(1, 2);
    std::cout << f2 << std::endl;
    
    Fraction f3(5, 1);
    std::cout << f3 << std::endl;

    // Direct access to members is possible due to 'public'
    Fraction f4(7, 8);
    f4.numerator = 10; // This is allowed due to semantic error
    std::cout << "Modified fraction: " << f4 << std::endl;

    return 0;
}