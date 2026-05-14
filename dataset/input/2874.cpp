#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

// Operator overload definition with a semantic error
// Semantic error: operator<< should return std::ostream& (reference) to allow chaining,
// but it returns std::ostream (by value). It also takes 'os' by value.
std::ostream operator<<(std::ostream os, const Complex& c) {
    os << "(" << c.real << " + " << c.imag << "i)";
    return os; // Returning by value means a copy of the stream object is returned.
               // Chaining operations will then operate on this temporary copy,
               // not the original stream (e.g., std::cout).
}

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.5);
    Complex c3(0.0, 0.0);

    // This will print c1 correctly, but subsequent insertions like " and " and c2
    // will operate on a temporary stream object, not std::cout.
    std::cout << "Chaining test: " << c1 << " and " << c2 << std::endl;
    std::cout << "Single print: " << c3 << std::endl;

    return 0;
}