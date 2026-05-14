#include <iostream>
#include <cmath> // For std::sqrt
#include <iomanip> // For std::fixed, std::setprecision

class Point {
private:
    int x;
    int y;

public:
    // Constructor: Uses initializer list for efficient and idiomatic member initialization.
    Point(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}

    // Method to calculate Euclidean distance from the point to the origin (0,0).
    // - Returns `double` for precision.
    // - Uses `static_cast<double>` on `x` and `y` before squaring to prevent
    //   potential integer overflow for large coordinate values, ensuring accuracy.
    // - Uses direct multiplication (`x_double * x_double`) for efficiency over `std::pow`.
    // - Marked `const` as it does not modify the object's state, improving type safety
    //   and allowing it to be called on `const Point` objects.
    double getDistanceToOrigin() const {
        double x_double = static_cast<double>(x);
        double y_double = static_cast<double>(y);
        return std::sqrt(x_double * x_double + y_double * y_double);
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

    Point p7(50000, 50000);
    std::cout << "Distance for (50000,50000): " << p7.getDistanceToOrigin() << std::endl;

    return 0;
}