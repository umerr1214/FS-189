#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    int getX() const { return x; }
    int getY() const { return y; }

    // Overload the binary == operator as a member function
    // Robustness Issue:
    // 1. Missing 'const' qualifier, preventing its use with const Point objects.
    // 2. Logical error: Only compares 'x' coordinates, making it non-robust for 'y' differences.
    bool operator==(const Point& other) { // Should be 'const'
        // This implementation only checks the x-coordinate, which is incorrect.
        // It's a subtle bug that makes the comparison non-robust.
        return x == other.x;
    }
};

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);
    Point p4(3, 5); // Different y
    Point p5(1, 5); // Different y, same x as p1

    std::cout << "Test Case 1: p1(1,2) == p2(1,2)" << std::endl;
    std::cout << "Expected: true (if operator was correct), Actual: " << (p1 == p2 ? "true" : "false") << std::endl; // Should be true, will be true
    std::cout << "Test Case 2: p1(1,2) == p3(3,4)" << std::endl;
    std::cout << "Expected: false, Actual: " << (p1 == p3 ? "true" : "false") << std::endl; // Should be false, will be false
    std::cout << "Test Case 3: p3(3,4) == p4(3,5)" << std::endl;
    std::cout << "Expected: false, Actual: " << (p3 == p4 ? "true" : "false") << std::endl; // Should be false, will be true (robustness issue here)
    std::cout << "Test Case 4: p1(1,2) == p5(1,5)" << std::endl;
    std::cout << "Expected: false, Actual: " << (p1 == p5 ? "true" : "false") << std::endl; // Should be false, will be true (robustness issue here)

    // Demonstrate issue with const object (will not compile if this were uncommented)
    // const Point const_p(10, 20);
    // Point non_const_p(10, 20);
    // std::cout << (const_p == non_const_p ? "true" : "false") << std::endl; // ERROR: no matching member function for call to 'operator=='

    return 0;
}