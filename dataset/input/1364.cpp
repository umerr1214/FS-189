#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class ComplexNumber {
private:
    double m_realPart; // Verbose member variable name
    double m_imaginaryPart; // Verbose member variable name

public:
    // Constructor
    ComplexNumber(double initialReal = 0.0, double initialImaginary = 0.0)
        : m_realPart(initialReal), m_imaginaryPart(initialImaginary) {}

    // Getter methods (verbose names)
    double getRealComponent() const { return m_realPart; }
    double getImaginaryComponent() const { return m_imaginaryPart; }

    // Overload binary + operator (Efficiency Issue: passes by value)
    // Passing 'other' by value causes an unnecessary copy of the ComplexNumber object.
    ComplexNumber operator+(ComplexNumber other) {
        double newReal = this->m_realPart + other.m_realPart;
        double newImaginary = this->m_imaginaryPart + other.m_imaginaryPart;
        return ComplexNumber(newReal, newImaginary);
    }

    // Method to get string representation for display (Readability Issue: slightly awkward formatting)
    std::string generateComplexStringRepresentation() const {
        std::ostringstream outputStream;
        outputStream << std::fixed << std::setprecision(2);
        outputStream << m_realPart;
        if (m_imaginaryPart >= 0.0) {
            outputStream << "+" << m_imaginaryPart << "i"; // No space, might look cluttered
        } else {
            outputStream << m_imaginaryPart << "i";
        }
        return outputStream.str();
    }
};

// Driver code
int main() {
    ComplexNumber complex1(1.1, 2.2);
    ComplexNumber complex2(3.3, 4.4);
    ComplexNumber complex3(-0.7, 1.3);
    ComplexNumber complex4(2.7, -3.3);
    ComplexNumber complexA(10.0, 5.0);
    ComplexNumber complexB(2.0, -1.0);
    ComplexNumber complexC(0.5, 0.5);

    ComplexNumber sum1 = complex1 + complex2;
    std::cout << sum1.generateComplexStringRepresentation() << std::endl;

    ComplexNumber sum2 = complex3 + complex4;
    std::cout << sum2.generateComplexStringRepresentation() << std::endl;

    ComplexNumber sum3 = complexA + complexB + complexC;
    std::cout << sum3.generateComplexStringRepresentation() << std::endl;

    return 0;
}