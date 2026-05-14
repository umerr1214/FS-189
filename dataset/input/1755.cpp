#include <iostream>

class Point {
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Friend declaration for the == operator
    // Correct signature: takes const references to avoid copying and ensure objects are not modified.
    friend bool operator==(const Point& p1, const Point& p2);
};

// Definition of the == operator
// Correct, efficient, and readable implementation.
bool operator==(const Point& p1, const Point& p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);

    std::cout << "Test Case 1: p1 == p2 (Expected: true, Actual: " << (p1 == p2 ? "true" : "false") << ")" << std::endl;
    std::cout << "Test Case 2: p1 == p3 (Expected: false, Actual: " << (p1 == p3 ? "true" : "false") << ")" << std::endl;

    Point p4(5, 6);
    Point p5(5, 7);
    std::cout << "Test Case 3: p4 == p5 (Expected: false, Actual: " << (p4 == p5 ? "true" : "false") << ")" << std::endl;

    // Test with temporary objects (rvalues) - should work correctly
    std::cout << "Test Case 4: Point(10, 20) == Point(10, 20) (Expected: true, Actual: " << (Point(10, 20) == Point(10, 20) ? "true" : "false") << ")" << std::endl;
    std::cout << "Test Case 5: Point(10, 20) == Point(10, 21) (Expected: false, Actual: " << (Point(10, 20) == Point(10, 21) ? "true" : "false") << ")" << std::endl;

    return 0;
}