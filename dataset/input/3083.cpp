#include <iostream>
#include <string> // For boolean to string conversion in output

class Point {
private:
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    // Logical error: Returns true if EITHER x OR y coordinates are identical,
    // instead of BOTH.
    bool operator==(const Point& other) const {
        return (x == other.x || y == other.y); // Should be &&
    }
};

int main() {
    Point p1(10, 20);
    Point p2(10, 20); // Both x and y match
    Point p3(10, 30); // Only x matches
    Point p4(5, 20);  // Only y matches
    Point p5(5, 30);  // Neither matches

    std::cout << "p1(10,20) == p2(10,20) -> " << (p1 == p2 ? "true" : "false") << std::endl;
    std::cout << "p1(10,20) == p3(10,30) -> " << (p1 == p3 ? "true" : "false") << std::endl;
    std::cout << "p1(10,20) == p4(5,20) -> " << (p1 == p4 ? "true" : "false") << std::endl;
    std::cout << "p1(10,20) == p5(5,30) -> " << (p1 == p5 ? "true" : "false") << std::endl;

    return 0;
}