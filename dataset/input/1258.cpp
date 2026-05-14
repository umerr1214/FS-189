#include <iostream>
#include <sstream>

class Point {
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Syntax Error: Missing return type for operator++
    operator++() { // Expected 'Point&' before 'operator++'
        ++x;
        ++y;
        return *this;
    }
};

int main() {
    std::stringstream ss;
    // Test case 1
    Point p1(1, 2);
    ++p1; // This line will cause a compile error due to the operator definition
    ss << "(" << p1.x << ", " << p1.y << ")";
    // Test case 2
    Point p2(5, 10);
    ++p2;
    ++p2;
    ss << ";" << "(" << p2.x << ", " << p2.y << ")";
    std::cout << ss.str();
    return 0;
}