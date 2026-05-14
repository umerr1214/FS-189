#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    // SEMANTIC ERROR: Missing 'friend' declaration for operator<<.
    // This will lead to a compilation error when operator<< tries to access private members.
    // friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

// This external function attempts to access private members 'x' and 'y'
// without being declared as a friend inside the Point class.
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")"; // Semantic error: 'x' and 'y' are private
    return os;
}

int main() {
    Point p1(1, 2);
    std::cout << p1 << std::endl;
    Point p2(0, 0);
    std::cout << p2 << std::endl;
    Point p3(-5, 10);
    std::cout << p3 << std::endl;
    return 0;
}