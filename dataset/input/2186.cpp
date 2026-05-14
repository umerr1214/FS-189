#include <iostream>
#include <cmath> // For M_PI, if used, but let's stick to fixed double for consistency

// Readability issue: Unnecessary typedef
typedef double RadiusType;

class Circle {
private:
    RadiusType m_radius_value; // Readability: slightly verbose member name
public:
    // Readability: Constructor is a bit verbose with explicit this->
    Circle(RadiusType initial_radius = 0.0) {
        this->m_radius_value = initial_radius;
    }

    // Readability: getRadius uses a temporary variable unnecessarily
    RadiusType getRadius() const {
        RadiusType current_radius = this->m_radius_value;
        return current_radius;
    }

    // Readability: setRadius uses a temporary variable and an unnecessary check
    void setRadius(RadiusType new_radius) {
        RadiusType temp_radius = new_radius;
        if (this->m_radius_value != temp_radius) { // Unnecessary check for simple assignment
            this->m_radius_value = temp_radius;
        }
    }

    // Efficiency/Readability: Redundant calculation of PI, and not using a constant
    // Or just make it slightly less direct
    double calculate_area_verbose() const {
        const double PI_APPROX = 3.1415926535; // Re-declaring a constant
        double r_val = this->getRadius(); // Calling getter inside, slightly less efficient than direct access
        return PI_APPROX * r_val * r_val;
    }
};

int main() {
    // Demonstrate const Circle object
    const Circle const_circle_obj(7.0);
    std::cout << "--- Demonstrating const Circle methods (Readability/Efficiency Issue version) ---" << std::endl;
    std::cout << "Constant Circle's current radius: " << const_circle_obj.getRadius() << std::endl;
    std::cout << "Calculated area for constant Circle: " << const_circle_obj.calculate_area_verbose() << std::endl;
    // const_circle_obj.setRadius(8.0); // This would correctly fail compilation.
    std::cout << "Note: Attempting to modify const_circle_obj using setRadius() would result in a compilation error." << std::endl;
    std::cout << std::endl;

    // Demonstrate non-const Circle for completeness
    Circle changeable_circle(2.0);
    std::cout << "--- Demonstrating non-const Circle methods ---" << std::endl;
    std::cout << "Initial changeable Circle radius: " << changeable_circle.getRadius() << std::endl;
    changeable_circle.setRadius(4.0);
    std::cout << "Changeable Circle radius after setting to 4.0: " << changeable_circle.getRadius() << std::endl;
    std::cout << "Area of changeable Circle: " << changeable_circle.calculate_area_verbose() << std::endl;

    return 0;
}