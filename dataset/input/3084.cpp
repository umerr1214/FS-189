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

    // Semantic error: operator== takes Point by value instead of const reference.
    // This works correctly in terms of result for simple types but involves unnecessary
    // copying, which is inefficient and semantically incorrect for an equality
    // comparison that shouldn't modify the argument and should be performant.
    bool operator==(Point other) const { // Should ideally be const Point& other
        return (x == other.x && y == other.y);
    }
};

int main() {
    Point p1(10, 20);
    Point p2(10, 20);
    Point p3(5, 10);
    const Point p_const1(1, 1);
    const Point p_const2(1, 1);

    // These comparisons will work correctly in terms of result,
    // but the underlying operator performs a copy of 'other' each time.
    std::cout << "p1(10,20) == p2(10,20) -> " << (p1 == p2 ? "true" : "false") << std::endl;
    std::cout << "p1(10,20) == p3(5,10) -> " << (p1 == p3 ? "true" : "false") << std::endl;
    std::cout << "p_const1(1,1) == p_const2(1,1) -> " << (p_const1 == p_const2 ? "true" : "false") << std::endl;

    return 0;
}