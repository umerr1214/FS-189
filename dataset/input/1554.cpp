#include <iostream>
#include <string>
#include <iomanip>

class Point {
private:
    double x;
    double y;

public:
    Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) {}

    // SEMANTIC ERROR: No public getters for x and y.
    // Non-member functions will attempt to access private members directly, leading to a compilation error.
    // double getX() const { return x; }
    // double getY() const { return y; }
};

void print(Point p) {
    // Attempting to access private members p.x and p.y directly
    std::cout << "Point: (" << std::fixed << std::setprecision(1) << p.x << ", " << p.y << ")" << std::endl;
}

void print(Point p, std::string prefix) {
    // Attempting to access private members p.x and p.y directly
    std::cout << prefix << ": (" << std::fixed << std::setprecision(1) << p.x << ", " << p.y << ")" << std::endl;
}

int main() {
    Point p1(10.5, 20.1);
    Point p2(-3.0, 7.8);

    print(p1);
    print(p2, "Location");

    Point p3(0.0, 0.0);
    print(p3, "Origin");

    return 0;
}