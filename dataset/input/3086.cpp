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
    // Readability / Efficiency Issue:
    // The implementation is overly verbose and uses redundant temporary variables and nested if-else statements,
    // making it less readable and slightly less efficient than a direct logical AND.
    bool operator==(const Point& other) const {
        bool x_matches;
        if (this->x == other.x) {
            x_matches = true;
        } else {
            x_matches = false;
        }

        bool y_matches;
        if (this->y == other.y) {
            y_matches = true;
        } else {
            y_matches = false;
        }

        if (x_matches) {
            if (y_matches) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);
    Point p4(3, 5);
    Point p5(1, 5);
    Point p6(0, 0);
    Point p7(0, 0);
    Point p8(5, 10);
    Point p9(10, 5);

    std::cout << "p1(1,2) == p2(1,2): " << (p1 == p2 ? "true" : "false") << std::endl;
    std::cout << "p3(3,4) == p4(3,5): " << (p3 == p4 ? "true" : "false") << std::endl;
    std::cout << "p1(1,2) == p5(1,5): " << (p1 == p5 ? "true" : "false") << std::endl;
    std::cout << "p6(0,0) == p7(0,0): " << (p6 == p7 ? "true" : "false") << std::endl;
    std::cout << "p8(5,10) == p9(10,5): " << (p8 == p9 ? "true" : "false") << std::endl;

    return 0;
}