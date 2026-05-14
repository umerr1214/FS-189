#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            // A logical handling, though not specified to be error-free
            this->denominator = 1; 
        }
    }

    // Overload the << operator
    // Logical error: Prints with a space instead of a slash
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << " " << f.denominator; // Should be f.numerator << "/" << f.denominator;
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

    return 0;
}