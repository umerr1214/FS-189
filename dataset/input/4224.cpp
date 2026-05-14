#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision
#include <vector>

// Semantic error: area and circumference are passed by value, not by reference.
// The variables in the calling function (main) will not be updated.
void calculate_circle_properties(double radius, double area, double circumference)
{
    const double PI = 3.141592653589793;
    area = PI * radius * radius;       // Updates local 'area' parameter
    circumference = 2 * PI * radius; // Updates local 'circumference' parameter
}

int main() {
    std::cout << std::fixed << std::setprecision(15);

    std::vector<double> radii = {1.0, 2.0, 0.0};

    for (double r : radii) {
        double area_main = 0.0; // Initialized to 0.0
        double circumference_main = 0.0; // Initialized to 0.0
        calculate_circle_properties(r, area_main, circumference_main);
        // area_main and circumference_main will remain 0.0 because they were passed by value
        std::cout << "Radius: " << r << ", Area: " << area_main << ", Circumference: " << circumference_main << std::endl;
    }

    return 0;
}