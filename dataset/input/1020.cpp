#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    // Semantic error: Getters are NOT declared const
    // Calling these on a const Point object will result in a compilation error
    int getX() { // Missing const keyword
        return x;
    }

    int getY() { // Missing const keyword
        return y;
    }
};

int main() {
    const Point p(10, 20); // Declaring a const Point object

    std::cout << "Point coordinates (const object):" << std::endl;
    // These calls will cause a semantic error because p is const,
    // but getX() and getY() are not const member functions.
    std::cout << "x: " << p.getX() << std::endl;
    std::cout << "y: " << p.getY() << std::endl;

    return 0;
}