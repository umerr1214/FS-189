#include <iostream>
#include <cmath> // For M_PI

// A global 'PI' variable, not a const, which can potentially be modified (though not in this example)
// and is less idiomatic than using M_PI or a class-level const.
double GLOBAL_PI_VALUE = 3.1415926535;

class Circle {
private:
    double m_radius; // Using 'm_' prefix, but inconsistent with common practices or other code.

public:
    // Constructor - verbose initialization
    Circle(double initialRadius) {
        this->m_radius = initialRadius; // Redundant 'this->'
    }

    // getArea is const, but uses verbose intermediate variables and a global non-const PI
    double getArea() const {
        // Redundant intermediate variables and use of global non-const PI
        double radiusSquared = this->m_radius * this->m_radius;
        double calculatedArea = GLOBAL_PI_VALUE * radiusSquared;
        return calculatedArea;
    }

    // resize method - simple, but could be more concise if 'this->' was not used everywhere
    void resize(double newRadiusValue) {
        this->m_radius = newRadiusValue; // Redundant 'this->'
    }

    double getRadius() const {
        return this->m_radius; // Redundant 'this->'
    }
};

int main() {
    std::cout.precision(4);
    std::cout << std::fixed;

    // Non-const Circle object
    Circle myCircle(5.0);
    std::cout << "Initial Circle myCircle (non-const):\n";
    std::cout << "  Radius: " << myCircle.getRadius() << ", Area: " << myCircle.getArea() << "\n";

    // Call resize on non-const object
    myCircle.resize(10.0);
    std::cout << "myCircle after resize(10.0):\n";
    std::cout << "  Radius: " << myCircle.getRadius() << ", Area: " << myCircle.getArea() << "\n";

    // Const Circle object
    const Circle anotherCircle(7.0);
    std::cout << "\nInitial Circle anotherCircle (const):\n";
    std::cout << "  Radius: " << anotherCircle.getRadius() << ", Area: " << anotherCircle.getArea() << "\n";

    // Call const method on const object
    std::cout << "anotherCircle's area (called on const object): " << anotherCircle.getArea() << "\n";

    return 0;
}