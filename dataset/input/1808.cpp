#include <iostream>

class Point2D {
private:
    int x;
    int y;

public:
    // Constructor
    Point2D(int val_x = 0, int val_y = 0) : x(val_x), y(val_y) {}

    // Getter methods for x and y
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

// Overload the binary + operator as a non-member function
// This version has efficiency and readability issues:
// 1. Arguments are passed by value, leading to unnecessary copies.
// 2. The internal creation of a temporary object is slightly more verbose than necessary.
Point2D operator+(Point2D p_one, Point2D p_two) { // Passed by value - inefficient
    // Explicitly create a temporary object for the result
    Point2D temporary_result_point(p_one.getX() + p_two.getX(), p_one.getY() + p_two.getY());
    return temporary_result_point; // Returns by value, which is correct here, but input copying is the issue
}

int main() {
    Point2D p1_val(1, 2);
    Point2D p2_val(3, 4);
    Point2D p3_val(-5, 10);
    Point2D p4_val(2, -7);
    Point2D p5_val(0, 0);
    Point2D p6_val(100000, 200000);
    Point2D p7_val(300000, 400000);

    Point2D sum1_val = p1_val + p2_val;
    std::cout << "(" << p1_val.getX() << ", " << p1_val.getY() << ") + ("
              << p2_val.getX() << ", " << p2_val.getY() << ") = ("
              << sum1_val.getX() << ", " << sum1_val.getY() << ")" << std::endl;

    Point2D sum2_val = p3_val + p4_val;
    std::cout << "(" << p3_val.getX() << ", " << p3_val.getY() << ") + ("
              << p4_val.getX() << ", " << p4_val.getY() << ") = ("
              << sum2_val.getX() << ", " << sum2_val.getY() << ")" << std::endl;

    Point2D sum3_val = p5_val + p1_val;
    std::cout << "(" << p5_val.getX() << ", " << p5_val.getY() << ") + ("
              << p1_val.getX() << ", " << p1_val.getY() << ") = ("
              << sum3_val.getX() << ", " << sum3_val.getY() << ")" << std::endl;

    Point2D sum4_val = p6_val + p7_val;
    std::cout << "(" << p6_val.getX() << ", " << p6_val.getY() << ") + ("
              << p7_val.getX() << ", " << p7_val.getY() << ") = ("
              << sum4_val.getX() << ", " << sum4_val.getY() << ")" << std::endl;

    return 0;
}