#include <iostream>
#include <cmath> // For std::pow

// Define PI as a constant. While functional, M_PI from <cmath> or std::numbers::pi (C++20)
// are generally preferred for precision and standard library usage.
const double MY_CUSTOM_PI_VALUE_FOR_AREA_CALCULATION = 3.141592653589793;

class Circle {
private:
    double m_the_internal_circle_radius_value; // Excessively long and verbose variable name

public:
    // Constructor
    Circle(double initial_radius_value) {
        // This constructor directly assigns, bypassing the setter's print statement
        // but still performs validation.
        if (initial_radius_value >= 0.0) {
            m_the_internal_circle_radius_value = initial_radius_value;
        } else {
            // Setting to a default valid value if initial is negative
            m_the_internal_circle_radius_value = 0.0;
            std::cout << "Circle constructor: Negative radius provided, defaulting to 0.0." << std::endl;
        }
    }

    // Default constructor
    Circle() : m_the_internal_circle_radius_value(0.0) {}

    // Getter method
    double getRadius() const {
        return m_the_internal_circle_radius_value;
    }

    // Setter method with verbose validation and side effect (printing)
    void setRadius(double new_radius_candidate_value) {
        // Verbose and slightly convoluted conditional check
        if (!(new_radius_candidate_value < 0.0)) {
            m_the_internal_circle_radius_value = new_radius_candidate_value;
            std::cout << "Circle setter: Radius successfully updated to " << new_radius_candidate_value << "." << std::endl;
        } else {
            // A setter generally shouldn't print directly to stdout for every failure
            // unless it's part of a specific logging or error reporting mechanism.
            // This is a side effect that reduces reusability and testability.
            std::cout << "Circle setter: Attempted to set a negative radius (" << new_radius_candidate_value << "). Radius remains " << m_the_internal_circle_radius_value << "." << std::endl;
        }
    }

    // Method to calculate area using std::pow, which is less efficient for squaring than direct multiplication.
    double calculateArea() const {
        // Using std::pow(base, 2) is less efficient than base * base for squaring.
        // Also using a custom PI constant instead of M_PI or std::numbers::pi.
        double radius_squared_value = std::pow(m_the_internal_circle_radius_value, 2);
        double calculated_area = MY_CUSTOM_PI_VALUE_FOR_AREA_CALCULATION * radius_squared_value;
        return calculated_area;
    }
};

int main() {
    std::cout << "--- Test Case 1: Initializing and calculating area ---" << std::endl;
    Circle myCircle(5.0);
    std::cout << "Current Radius: " << myCircle.getRadius() << std::endl;
    std::cout << "Calculated Area: " << myCircle.calculateArea() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test Case 2: Setting a new valid radius ---" << std::endl;
    myCircle.setRadius(10.0);
    std::cout << "Current Radius: " << myCircle.getRadius() << std::endl;
    std::cout << "Calculated Area: " << myCircle.calculateArea() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test Case 3: Attempting to set a negative radius ---" << std::endl;
    myCircle.setRadius(-2.5); // Should print a warning and keep radius at 10.0
    std::cout << "Current Radius: " << myCircle.getRadius() << std::endl;
    std::cout << "Calculated Area: " << myCircle.calculateArea() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test Case 4: Setting radius to zero ---" << std::endl;
    myCircle.setRadius(0.0);
    std::cout << "Current Radius: " << myCircle.getRadius() << std::endl;
    std::cout << "Calculated Area: " << myCircle.calculateArea() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test Case 5: Default constructed circle ---" << std::endl;
    Circle defaultCircle;
    std::cout << "Default Circle Radius: " << defaultCircle.getRadius() << std::endl;
    std::cout << "Default Circle Area: " << defaultCircle.calculateArea() << std::endl;
    defaultCircle.setRadius(7.0);
    std::cout << "Default Circle Radius after setting: " << defaultCircle.getRadius() << std::endl;
    std::cout << "Default Circle Area after setting: " << defaultCircle.calculateArea() << std::endl;
    std::cout << std::endl;

    return 0;
}