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
};

void print(Point p) {
    // LOGICAL ERROR: Swapping x and y coordinates in the output for this specific print function
    std::cout << "Point: (" << std::fixed << std::setprecision(1) << p.getY() << ", " << p.getX() << ")" << std::endl;
}

void print(Point p, std::string prefix) {
    // This overloaded function prints correctly
    std::cout << prefix << ": (" << std::fixed << std::setprecision(1) << p.getX() << ", " << p.getY() << ")" << std::endl;
}

int main() {
    Point p1(10.5, 20.1);
    Point p2(-3.0, 7.8);

    print(p1); // This call will produce incorrect output due to the logical error
    print(p2, "Location");

    Point p3(0.0, 0.0);
    print(p3, "Origin");

    return 0;
}