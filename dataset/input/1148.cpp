#include <iostream>
// No cmath for M_PI, using a magic number directly

class Circle {
    double _r; // Poor variable name for radius

public:
    // Constructor with inconsistent spacing
    Circle( double  _in_r ) : _r(_in_r)
    {
        // No validation, but that's not the primary error here
    }

    // Getter method, also poor naming
    double get_r_val() const {
        return _r;
    }

    // Function to calculate area, poor naming
    double calculate_circ_area() const {
        return 3.14159 * _r * _r; // Magic number for PI
    }
};

int main() {
    std::cout << "Starting calculations for circles...\n"; // Verbose output
    // First circle
    Circle c_one(10.0);
    std::cout << "Circle 1 details:\n";
    std::cout << "  Radius value: " << c_one.get_r_val() << "\n";
    std::cout << "  Calculated Area: " << c_one.calculate_circ_area() << "\n\n";

    // Second circle
    Circle c_two(2.5);
    std::cout << "Circle 2 details:\n";
    std::cout << "  Radius value: " << c_two.get_r_val() << "\n";
    std::cout << "  Calculated Area: " << c_two.calculate_circ_area() << "\n\n";

    // Third circle, demonstrating another radius
    Circle c_three(7.0);
    std::cout << "Circle 3 details:\n";
    std::cout << "  Radius value: " << c_three.get_r_val() << "\n";
    std::cout << "  Calculated Area: " << c_three.calculate_circ_area() << "\n\n";

    double another_radius = 1.0;
    Circle last_circle(another_radius);
    std::cout << "And finally, a small circle:\n";
    std::cout << "  Radius: " << last_circle.get_r_val() << "\n";
    std::cout << "  Area: " << last_circle.calculate_circ_area() << "\n\n";

    std::cout << "All circle calculations completed. Exiting program.\n";
    return 0;
}