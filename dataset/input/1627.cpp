#include <iostream>
#include <cmath> // For std::sqrt
#include <iomanip> // For std::fixed, std::setprecision

class Point {
private:
    int x;
    int y;

public:
    // Constructor
    Point(int x_coord, int y_coord) {
        x = x_coord;
        y = y_coord;
    }

    // Method to calculate distance to origin (0,0)
    // Robustness issue: x*x + y*y might overflow int if x and y are large,
    // leading to incorrect results.
    double getDistanceToOrigin() {
        // These intermediate calculations are performed using 'int' type.
        // If x or y are large (e.g., 50000), x*x will exceed the maximum
        // value for a 32-bit signed int (~2.147 billion), leading to
        // integer overflow and incorrect values for x_squared, y_squared,
        // and subsequently sum_of_squares.
        int x_squared = x * x;
        int y_squared = y * y;
        int sum_of_squares = x_squared + y_squared;

        // The result of the overflowed sum is then cast to double and sqrt is taken.
        // This does not fix the initial incorrect calculation.
        return std::sqrt(static_cast<double>(sum_of_squares));
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(10);

    Point p1(0, 0);
    std::cout << "Distance for (0,0): " << p1.getDistanceToOrigin() << std::endl;

    Point p2(3, 4);
    std::cout << "Distance for (3,4): " << p2.getDistanceToOrigin() << std::endl;

    Point p3(-3, -4);
    std::cout << "Distance for (-3,-4): " << p3.getDistanceToOrigin() << std::endl;

    Point p4(5, 12);
    std::cout << "Distance for (5,12): " << p4.getDistanceToOrigin() << std::endl;

    Point p5(-8, 6);
    std::cout << "Distance for (-8,6): " << p5.getDistanceToOrigin() << std::endl;

    Point p6(1, 1);
    std::cout << "Distance for (1,1): " << p6.getDistanceToOrigin() << std::endl;

    // This case will demonstrate the robustness issue (integer overflow)
    // For x=50000, x*x = 2,500,000,000, which overflows a 32-bit signed int.
    Point p7(50000, 50000);
    std::cout << "Distance for (50000,50000): " << p7.getDistanceToOrigin() << std::endl;

    return 0;
}