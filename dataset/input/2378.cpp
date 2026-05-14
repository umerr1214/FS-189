#include <iostream>
#include <cmath>   // For pow, sqrt
#include <vector>  // For setCoordinates (efficiency/readability issue)
#include <iomanip> // For std::fixed, std::setprecision

// Readability Issue: Using 'using namespace std;' in global scope is generally bad practice in headers or large projects.
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    // Constructor
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Readability/Efficiency Issue: setCoordinates takes a std::vector<int>
    // This is overly complex and less efficient than directly taking two int parameters
    // for a simple task of setting two integer coordinates. It also adds error handling for vector size.
    void setCoordinates(vector<int> coords) {
        if (coords.size() == 2) {
            this->x = coords[0];
            this->y = coords[1];
        } else {
            // In a real scenario, this might throw an exception or return an error code.
            // For this example, we'll print a warning and not modify coordinates.
            cout << "Warning: Invalid coordinates vector size. Expected 2 elements." << endl;
        }
    }

    // Readability/Efficiency Issue: getDistanceToOrigin uses std::pow(base, exponent)
    // Using pow(x, 2.0) is less efficient than simple multiplication (x*x) for integer squares
    // as it involves floating-point operations and function call overhead.
    double getDistanceToOrigin() {
        double x_val_double = static_cast<double>(x);
        double y_val_double = static_cast<double>(y);
        
        // Less efficient: using pow for squares
        double sum_of_squares = pow(x_val_double, 2.0) + pow(y_val_double, 2.0);
        return sqrt(sum_of_squares);
    }
};

int main() {
    // Set output precision for double values
    cout << fixed << setprecision(2);

    Point p1;
    p1.setCoordinates({3, 4}); // Using initializer list for vector
    cout << "Distance for (3, 4): " << p1.getDistanceToOrigin() << endl;

    Point p2;
    p2.setCoordinates({0, 0});
    cout << "Distance for (0, 0): " << p2.getDistanceToOrigin() << endl;

    Point p3;
    p3.setCoordinates({-5, 12});
    cout << "Distance for (-5, 12): " << p3.getDistanceToOrigin() << endl;

    // Test case for invalid vector size in setCoordinates
    Point p4;
    p4.setCoordinates({1}); // Only one element, will trigger warning and not change y (remains 0)
    cout << "Distance for (1, 0): " << p4.getDistanceToOrigin() << endl; // x=1, y=0 (initial value)
    
    return 0;
}