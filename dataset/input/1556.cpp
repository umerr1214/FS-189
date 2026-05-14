#include <iostream>
#include <string>
#include <iomanip> // Included but not fully utilized for efficiency/readability issue

// Readability Issue: Using namespace std in global scope.
// While convenient for small files, it can lead to name collisions
// and reduced readability in larger projects.
using namespace std;

class Point {
private:
    double x;
    double y;
public:
    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Correct const getters (not a robustness issue here)
    double getX() const { return x; }
    double getY() const { return y; }
};

// Efficiency Issue: Point object passed by value.
// This creates a copy of the Point object every time the function is called,
// which is inefficient for larger objects or frequent calls.
void print(Point p) {
    // Readability Issue: Not explicitly setting precision for doubles.
    // While not incorrect, consistent formatting improves readability.
    cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;
}

// Efficiency Issue: Point object passed by value.
void print(Point p, string prefix) {
    cout << prefix << ": (" << p.getX() << ", " << p.getY() << ")" << endl;
}

int main() {
    Point p1(10.5, 20.25);
    Point p2(0.12345, 987.654);
    Point p3(1.0/7.0, 2.0/7.0); // Example with recurring decimals

    print(p1);
    print(p2, "DetailedPoint");
    print(p3, "RatioPoint");

    return 0;
}