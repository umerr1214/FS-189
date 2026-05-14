#include <iostream>
#include <cmath> // For std::pow

using namespace std; // Readability: Using namespace std; can pollute the global namespace

int main() {
    const double PI = 3.14159; // PI constant
    double r; // Readability: Poor variable name 'r' instead of 'radius'

    cout << "Give radius: "; // Readability: Less descriptive prompt
    cin >> r;

    // Efficiency: Using std::pow(r, 2) for squaring is generally less efficient
    // than direct multiplication (r * r) for simple powers, as pow involves
    // more complex calculations.
    double a = PI * pow(r, 2); // Readability: Poor variable name 'a' instead of 'area'
    double p = 2 * PI * r;     // Readability: Poor variable name 'p' instead of 'perimeter'

    // Readability: Less descriptive output messages
    cout << "A: " << a << "\n"; // Using '\n' is generally more efficient than std::endl
    cout << "P: " << p << "\n";

    return 0;
}