#include <iostream>
#include <string>
#include <iomanip>

class Point {
private:
    double x;
    double y;

public:
    Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) {}

    double getX() const { return x; }
    double getY() const { return y; }
} // SYNTAX ERROR: Missing semicolon after class definition

void print(Point p) {
    std::cout << "Point: (" << std::fixed << std::setprecision(1) << p.getX() << ", " << p.getY() << ")" << std::endl;
}

void print(Point p, std::string prefix) {
    std::cout << prefix << ": (" << std::fixed << std::setprecision(1) << p.getX() << ", " << p.getY() << ")" << std::endl;
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