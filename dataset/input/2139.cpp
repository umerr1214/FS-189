#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    // Correct: Constructor using initializer list
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Correct: Const-correct getter methods
    int getX() const { return x; }
    int getY() const { return y; }

    // Correct: Const-correct method to print the Point coordinates
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    // Correct: Declare the non-member operator+ as a friend to access private members
    // This allows the operator to be a non-member function while still having
    // direct access to the private x and y, promoting symmetry (e.g., int + Point)
    friend Point operator+(const Point& p1, const Point& p2);
};

// Correct: Overloaded binary '+' operator implemented as a non-member function
// 1. Takes arguments by const reference for efficiency and to prevent modification.
// 2. Returns a new Point object by value (leveraging RVO/NRVO for efficiency).
// 3. Does not modify its operands.
Point operator+(const Point& p1, const Point& p2) {
    // Creates and returns a new Point object with summed coordinates
    return Point(p1.x + p2.x, p1.y + p2.y);
}

int main() {
    std::cout << "--- Correct Version Test ---" << std::endl;

    // Test Case 1
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2; // Uses the overloaded operator+
    std::cout << "Test Case 1: ";
    p1.print();
    std::cout << " + ";
    p2.print();
    std::cout << " = ";
    p3.print();
    std::cout << std::endl;
    // Expected: (4, 6)

    // Test Case 2
    Point p4(0, 0);
    Point p5(-1, -5);
    Point p6 = p4 + p5;
    std::cout << "Test Case 2: ";
    p4.print();
    std::cout << " + ";
    p5.print();
    std::cout << " = ";
    p6.print();
    std::cout << std::endl;
    // Expected: (-1, -5)

    return 0;
}