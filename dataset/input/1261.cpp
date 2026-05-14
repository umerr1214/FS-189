#include <iostream>

class Point {
public:
    int x;
    int y;

    // Constructor with default values
    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Robustness Issue:
    // The prefix increment operator returns 'const Point&' instead of 'Point&'.
    // This prevents chaining of increment operations (e.g., `++(++p)`)
    // and prevents modifying the result of the increment directly (e.g., `(++p).x = 5;`),
    // which are common and expected uses for prefix '++'.
    const Point& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // Method to print the point coordinates
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(1, 2);
    std::cout << "Original point p1: ";
    p1.print();
    std::cout << std::endl;

    // Basic increment operation
    ++p1;
    std::cout << "After ++p1: ";
    p1.print();
    std::cout << std::endl;

    Point p2(5, 6);
    std::cout << "Original point p2: ";
    p2.print();
    std::cout << std::endl;

    // Due to 'const Point&' return type:
    // The following lines would cause compile-time errors:
    // (++p2).x = 10;   // Error: expression must be a modifiable lvalue
    // ++(++p2);        // Error: no match for 'operator++' (operand type is 'const Point')

    // We can only assign the result to a const reference or use const methods on it.
    const Point& temp_ref = ++p2;
    std::cout << "After ++p2 (temp_ref points to p2): ";
    temp_ref.print();
    std::cout << std::endl;

    std::cout << "Final p2: ";
    p2.print(); // p2 was indeed incremented
    std::cout << std::endl;

    return 0;
}