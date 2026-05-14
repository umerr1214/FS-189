#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision
#include <vector>

void calculate_circle_properties(double radius, double& area, double& circumference)
{
    const double PI = 3.141592653589793;
    area = PI * radius; // Logical error: Area should be PI * radius * radius
    circumference = 2 * PI * radius; // Correct
}

int main() {
    std::cout << std::fixed << std::setprecision(15);

    std::vector<double> radii = {1.0, 2.0, 0.0};

    for (double r : radii) {
        double area_val = 0.0;
        double circumference_val = 0.0;
        calculate_circle_properties(r, area_val, circumference_val);
        std::cout << "Radius: " << r << ", Area: " << area_val << ", Circumference: " << circumference_val << std::endl;
    }

    return 0;
}