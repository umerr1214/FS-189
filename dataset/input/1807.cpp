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
// This version introduces a memory leak by returning a dynamically allocated object.
// The caller is responsible for deleting the returned pointer, which makes the API fragile
// and prone to memory leaks if not handled carefully.
Point2D* operator+(const Point2D& p1, const Point2D& p2) {
    Point2D* result = new Point2D(p1.getX() + p2.getX(), p1.getY() + p2.getY());
    return result; // Memory leak: caller is responsible for deleting, but often forgotten.
}

int main() {
    Point2D p1(1, 2);
    Point2D p2(3, 4);
    Point2D p3(-5, 10);
    Point2D p4(2, -7);
    Point2D p5(0, 0);
    Point2D p6(100000, 200000);
    Point2D p7(300000, 400000);

    Point2D* sum1 = p1 + p2; // Leaked memory
    std::cout << "(" << p1.getX() << ", " << p1.getY() << ") + ("
              << p2.getX() << ", " << p2.getY() << ") = ("
              << sum1->getX() << ", " << sum1->getY() << ")" << std::endl;

    Point2D* sum2 = p3 + p4; // Leaked memory
    std::cout << "(" << p3.getX() << ", " << p3.getY() << ") + ("
              << p4.getX() << ", " << p4.getY() << ") = ("
              << sum2->getX() << ", " << sum2->getY() << ")" << std::endl;

    Point2D* sum3 = p5 + p1; // Leaked memory
    std::cout << "(" << p5.getX() << ", " << p5.getY() << ") + ("
              << p1.getX() << ", " << p1.getY() << ") = ("
              << sum3->getX() << ", " << sum3->getY() << ")" << std::endl;

    Point2D* sum4 = p6 + p7; // Leaked memory
    std::cout << "(" << p6.getX() << ", " << p6.getY() << ") + ("
              << p7.getX() << ", " << p7.getY() << ") = ("
              << sum4->getX() << ", " << sum4->getY() << ")" << std::endl;

    // To prevent memory leaks, the returned pointers should be deleted:
    // delete sum1;
    // delete sum2;
    // delete sum3;
    // delete sum4;
    // These lines are intentionally omitted to demonstrate the robustness issue.

    return 0;
}