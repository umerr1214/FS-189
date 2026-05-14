#include <iostream>

class Point {
public: // Readability / Encapsulation Issue: Members should be private
    int x;
    int y;

    // Minor Efficiency/Readability Issue: Using assignment instead of initializer list
    Point(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
    // No print method, directly accessing public members in main
};

// Readability / Efficiency Issue:
// 1. Takes Point objects by value, leading to unnecessary copies.
// 2. Implementation uses default construction then assignment for result,
//    which is less concise and potentially less efficient than direct initialization.
Point operator+(Point p1, Point p2) { // Arguments passed by value -> copies p1 and p2
    Point result_point; // Unnecessary default construction
    result_point.x = p1.x + p2.x; // Then assignment
    result_point.y = p1.y + p2.y;
    return result_point; // Returns by value -> copies result_point
}

int main() {
    std::cout << "--- Readability / Efficiency Issue Test ---" << std::endl;

    // Test Case 1
    Point p1(1, 2);
    Point p2(3, 4);
    // Explicitly calling operator+ as it's a non-member function
    // The operator will internally make copies of p1 and p2.
    Point p3 = operator+(p1, p2);
    std::cout << "Test Case 1: ";
    // Directly accessing public members to print
    std::cout << "(" << p1.x << ", " << p1.y << ") + ";
    std::cout << "(" << p2.x << ", " << p2.y << ") = ";
    std::cout << "(" << p3.x << ", " << p3.y << ")" << std::endl;
    // Expected: (4, 6)

    // Test Case 2
    Point p4(0, 0);
    Point p5(-1, -5);
    Point p6 = operator+(p4, p5);
    std::cout << "Test Case 2: ";
    std::cout << "(" << p4.x << ", " << p4.y << ") + ";
    std::cout << "(" << p5.x << ", " << p5.y << ") = ";
    std::cout << "(" << p6.x << ", " << p6.y << ")" << std::endl;
    // Expected: (-1, -5)

    return 0;
}