#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Constructor
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Default constructor for completeness
    Point() : x(0), y(0) {}

    // Getter methods for coordinates
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    // Friend declaration for the overloaded + operator
    // Readability / Efficiency Issue: Parameters passed by value instead of const reference.
    // This causes unnecessary copies of Point objects, reducing efficiency.
    friend Point operator+(Point p1, Point p2);
};

// Overload the binary + operator as a global friend function
// Readability / Efficiency Issue: Parameters passed by value, causing two unnecessary copies.
// Also, inconsistent indentation and use of unnecessary temporary variables reduce readability and efficiency.
Point operator+(Point p1, Point p2) {
                                        // Inconsistent indentation
    Point result; // Unnecessary temporary variable
    result.x = p1.x + p2.x;
        result.y = p1.y + p2.y; // Poor indentation
    return result;
}

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2; // Should be (4, 6)

    std::cout << "Point p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "Point p2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
    std::cout << "p1 + p2: (" << p3.getX() << ", " << p3.getY() << ")" << std::endl; // Expected: (4, 6)

    Point p4(0, 0);
    Point p5(-1, -1);
    Point p6 = p4 + p5; // Should be (-1, -1)
    std::cout << "p4 + p5: (" << p6.getX() << ", " << p6.getY() << ")" << std::endl; // Expected: (-1, -1)

    Point p7(10, -5);
    Point p8(2, 7);
    Point p9 = p7 + p8; // Should be (12, 2)
    std::cout << "p7 + p8: (" << p9.getX() << ", " << p9.getY() << ")" << std::endl; // Expected: (12, 2)

    return 0;
}