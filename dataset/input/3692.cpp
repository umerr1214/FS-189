#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; // Readability/Efficiency Issue: Use of 'using namespace std;'

// Define a struct Point with x and y (double) coordinates
struct Point {
    double a; // Readability Issue: Non-descriptive variable names
    double b;
};

int main() {
    Point p1, p2;

    cout << "Enter coordinates for Point 1 (x y): ";
    cin >> p1.a >> p1.b; // Readability Issue: Using 'a' and 'b' for x and y

    cout << "Enter coordinates for Point 2 (x y): ";
    cin >> p2.a >> p2.b;

    // Calculate Euclidean distance
    double dx = p2.a - p1.a;
    double dy = p2.b - p1.b;
    // Efficiency Issue: Using std::pow(base, 2) is generally less efficient
    // than base * base for squaring, due to function call overhead and
    // more complex internal calculations.
    double distance = sqrt(pow(dx, 2) + pow(dy, 2));

    cout << fixed << setprecision(5);
    cout << "The Euclidean distance between the two points is: " << distance << endl;

    return 0;
}