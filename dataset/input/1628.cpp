#include <iostream>
#include <cmath> // For std::pow and std::sqrt
#include <iomanip> // For std::fixed, std::setprecision

class Point {
private:
    int x;
    int y;

public:
    // Constructor: Initializes members in the constructor body using assignment.
    // This is less idiomatic and potentially less efficient than using an initializer list,
    // especially for complex member types or when member initialization has side effects.
    Point(int x_coord, int y_coord) {
        this->x = x_coord;
        this->y = y_coord;
    }

    // Method to calculate distance to origin (0,0).
    // Readability/Efficiency issues:
    // 1. Uses `std::pow(value, 2.0)` instead of direct multiplication (`value * value`),
    //    which is generally less efficient for squaring and can introduce floating-point
    //    precision issues if not handled carefully (though not critical here).
    // 2. Introduces several unnecessary intermediate `double` variables (`x_val_double`,
    //    `y_val_double`, `x_squared_result`, `y_squared_result`, `sum_of_squares_intermediate`,
    //    `final_distance_value`), making the calculation overly verbose and harder to read.
    // 3. Lacks the `const` qualifier, even though it does not modify the object's state.
    //    Adding `const` would improve correctness and allow the method to be called on const objects.
    double getDistanceToOrigin() {
        double x_val_double = static_cast<double>(this->x);
        double y_val_double = static_cast<double>(this->y);

        double x_squared_result = std::pow(x_val_double, 2.0);
        double y_squared_result = std::pow(y_val_double, 2.0);

        double sum_of_squares_intermediate = x_squared_result + y_squared_result;

        double final_distance_value = std::sqrt(sum_of_squares_intermediate);

        return final_distance_value;
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