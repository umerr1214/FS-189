#include <iostream>
#include <sstream>

class Point {
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    // Logical Error: Returns a copy (Point) instead of a reference (Point&)
    Point operator++() {
        x++;
        y++;
        return *this; // Returns a copy of the modified object
    }
};

int main() {
    std::stringstream ss;

    // Test Case 1: Basic increment - appears correct
    Point p1(1, 2);
    ss << "Initial p1: " << p1 << std::endl;
    ++p1;
    ss << "After ++p1: " << p1 << std::endl;

    // Test Case 2: Return value of prefix increment - demonstrates the copy behavior
    Point p2(5, 5);
    Point returned_p2 = ++p2; // Captures the copy returned by operator++
    ss << "After ++p2, p2: " << p2 << std::endl; // Original p2 is modified
    ss << "Returned object: " << returned_p2 << std::endl; // The copy has the incremented values
    returned_p2.x = 10; // Modifies the copy, not the original p2
    ss << "After returned_p2.x = 10, p2: " << p2 << std::endl; // p2 remains unchanged
    ss << "After returned_p2.x = 10, returned_p2: " << returned_p2 << std::endl;

    // Test Case 3: Chained increment - demonstrates that only the first increment affects the original object
    Point p3(10, 20);
    ss << "Initial p3: " << p3 << std::endl;
    // The expression ++(++p3) would be parsed as `operator++(operator++(p3))`.
    // The inner `operator++(p3)` increments p3 and returns a copy.
    // The outer `operator++` then operates on this *copy*, incrementing it, and returning another copy.
    // The original p3 is only incremented once.
    Point temp_p3_1 = ++p3; // p3 becomes (11,21), temp_p3_1 is a copy (11,21)
    Point temp_p3_2 = ++temp_p3_1; // temp_p3_1 becomes (12,22), temp_p3_2 is a copy (12,22)
                                 // p3 remains (11,21) as the second increment operated on a copy
    ss << "After ++(++p3) operation, p3: " << p3 << std::endl;
    ss << "Value of ++(++p3) (last returned temp): " << temp_p3_2 << std::endl;

    std::cout << ss.str();
    return 0;
}