#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision
#include <vector>

// Function definition with a syntax error (missing semicolon)
void calculate_circle_properties(double radius, double& area, double& circumference)
{
    const double PI = 3.141592653589793;
    area = PI * radius * radius;
    circumference = 2 * PI * radius // Missing semicolon here
}

int main() {
    std::cout << std::fixed << std::setprecision(15);

    std::vector<double> radii = {1.0, 2.0, 0.0};

    for (double r : radii) {
        double area_val = 0.0;
        double circumference_val = 0.0;
        // This call will fail to compile due to the syntax error in the function definition
        calculate_circle_properties(r, area_val, circumference_val);
        std::cout << "Radius: " << r << ", Area: " << area_val << ", Circumference: " << circumference_val << std::endl;
    }

    return 0;
}