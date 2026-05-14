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
    // Correct Version:
    // - Returns true if both x and y coordinates are identical.
    // - Is declared as 'const' because it does not modify the object.
    // - Is concise and efficient.
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
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

    // Test with const objects
    const Point const_p1(10, 20);
    const Point const_p2(10, 20);
    const Point const_p3(10, 25);
    std::cout << "const_p1(10,20) == const_p2(10,20): " << (const_p1 == const_p2 ? "true" : "false") << std::endl;
    std::cout << "const_p1(10,20) == const_p3(10,25): " << (const_p1 == const_p3 ? "true" : "false") << std::endl;

    return 0;
}