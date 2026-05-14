#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

int main() {
    const Point p(10, 20); // Declaring a const Point object

    std::cout << "Point coordinates (const object):" << std::endl;
    std::cout << "x: " << p.getX() << std::endl;
    std::cout << "y: " << p.getY() // ERROR: Missing semicolon here
    std::cout << "This line will cause a syntax error." << std::endl; // This line highlights the error context

    return 0;
}