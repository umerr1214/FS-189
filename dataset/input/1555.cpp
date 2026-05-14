#include <iostream>
#include <string>
#include <iomanip> // Included but not fully utilized for robustness issue

class Point {
private:
    double x;
    double y;
public:
    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Robustness Issue: Missing 'const' qualifier for getter methods.
    // This prevents these methods from being called on const Point objects
    // and is generally bad practice as getters should not modify state.
    double getX() { return x; }
    double getY() { return y; }
};

// Robustness Issue: Point object passed by value. While not a crash,
// for larger objects this can be an efficiency/resource issue.
// More importantly for robustness, no precision control for double output.
void print(Point p) {
    // Output without std::fixed or std::setprecision, leading to
    // potentially inconsistent or unreadable floating-point output (e.g., scientific notation).
    std::cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << std::endl;
}

// Robustness Issue: Point object passed by value.
// No precision control for double output.
void print(Point p, std::string prefix) {
    std::cout << prefix << ": (" << p.getX() << ", " << p.getY() << ")" << std::endl;
}

int main() {
    Point p1(10.5, 20.25);
    Point p2(0.123456789, 987654321.123456789);
    Point p3(1.0/3.0, 2.0/3.0);
    Point p4(0.0000000001, 50.0);

    print(p1);
    print(p2, "ComplexPoint");
    print(p3, "FractionPoint");
    print(p4);

    return 0;
}