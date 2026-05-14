#include <iostream>
#include <string> // Required for std::boolalpha

class Point {
private:
    int x_coord;
    int y_coord;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x_coord(x), y_coord(y) {}

    // Getters (provided for completeness, though not strictly needed by the operator itself)
    int getX() const { return x_coord; }
    int getY() const { return y_coord; }

    // Robustness Issue:
    // The operator== is not declared as 'const'. This means it cannot be called on
    // 'const Point' objects, limiting its usability and violating const-correctness.
    // It should be 'bool operator==(const Point& other) const'.
    bool operator==(const Point& other) { // Missing 'const' qualifier
        return (x_coord == other.x_coord && y_coord == other.y_coord);
    }
};

int main() {
    std::cout << std::boolalpha; // Print true/false instead of 1/0

    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);
    Point p4(0, 0);
    Point p5(-1, -2);
    Point p6(-1, -2);
    Point p7(-2, -1);
    Point p8(5, 5);
    Point p9(5, 0);

    // Test cases for the operator
    std::cout << "Point(1, 2) == Point(1, 2): " << (p1 == p2) << std::endl;
    std::cout << "Point(1, 2) == Point(3, 4): " << (p1 == p3) << std::endl;
    std::cout << "Point(5, 5) == Point(5, 0): " << (p8 == p9) << std::endl;
    std::cout << "Point(0, 0) == Point(0, 0): " << (p4 == p4) << std::endl; // Self-comparison
    std::cout << "Point(-1, -2) == Point(-1, -2): " << (p5 == p6) << std::endl;
    std::cout << "Point(-1, -2) == Point(-2, -1): " << (p5 == p7) << std::endl;

    // Note: If 'p_const' were a const Point, 'p_const == p1' would cause a compilation error
    // because operator== is not const-qualified. This demonstrates the robustness issue.
    // Example: const Point p_const(10, 20); // p_const == p1; // Would fail to compile
    
    return 0;
}