#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    // Logical error: getX returns y, getY returns x
    int getX() const {
        return y; // Should return x
    }

    int getY() const {
        return x; // Should return y
    }
};

int main() {
    const Point p(10, 20); // Declaring a const Point object

    std::cout << "Point coordinates (const object):" << std::endl;
    std::cout << "x: " << p.getX() << std::endl; // This will output 20 instead of 10
    std::cout << "y: " << p.getY() << std::endl; // This will output 10 instead of 20

    return 0;
}