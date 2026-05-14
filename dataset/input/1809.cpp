#include <iostream>

class Point2D {
private:
    int x;
    int y;

public:
    // Constructor
    Point2D(int val_x = 0, int val_y = 0) : x(val_x), y(val_y) {}

    // Getter methods for x and y (const-correct)
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

// Overload the binary + operator as a non-member function
// Takes arguments by const reference for efficiency and correctness.
// Returns a new Point2D object by value.
Point2D operator+(const Point2D& p1, const Point2D& p2) {
    return Point2D(p1.getX() + p2.getX(), p1.getY() + p2.getY());
}

int main() {
    Point2D p1_corr(1, 2);
    Point2D p2_corr(3, 4);
    Point2D p3_corr(-5, 10);
    Point2D p4_corr(2, -7);
    Point2D p5_corr(0, 0);
    Point2D p6_corr(100000, 200000);
    Point2D p7_corr(300000, 400000);

    Point2D sum1_corr = p1_corr + p2_corr;
    std::cout << "(" << p1_corr.getX() << ", " << p1_corr.getY() << ") + ("
              << p2_corr.getX() << ", " << p2_corr.getY() << ") = ("
              << sum1_corr.getX() << ", " << sum1_corr.getY() << ")" << std::endl;

    Point2D sum2_corr = p3_corr + p4_corr;
    std::cout << "(" << p3_corr.getX() << ", " << p3_corr.getY() << ") + ("
              << p4_corr.getX() << ", " << p4_corr.getY() << ") = ("
              << sum2_corr.getX() << ", " << sum2_corr.getY() << ")" << std::endl;

    Point2D sum3_corr = p5_corr + p1_corr;
    std::cout << "(" << p5_corr.getX() << ", " << p5_corr.getY() << ") + ("
              << p1_corr.getX() << ", " << p1_corr.getY() << ") = ("
              << sum3_corr.getX() << ", " << sum3_corr.getY() << ")" << std::endl;

    Point2D sum4_corr = p6_corr + p7_corr;
    std::cout << "(" << p6_corr.getX() << ", " << p6_corr.getY() << ") + ("
              << p7_corr.getX() << ", " << p7_corr.getY() << ") = ("
              << sum4_corr.getX() << ", " << sum4_corr.getY() << ")" << std::endl;

    return 0;
}