#include <iostream>
#include <cmath>    // Required for std::sqrt
#include <iomanip>  // Required for std::fixed and std::setprecision

// Forward declaration of DistanceCalculator to allow its friend declaration in Point
class DistanceCalculator;

class Point {
private:
    double x;
    double y;

public:
    // Constructor to initialize private coordinates
    Point(double _x, double _y) : x(_x), y(_y) {}

    // Declare DistanceCalculator as a friend class
    // This grants DistanceCalculator direct access to Point's private members (x, y).
    friend class DistanceCalculator;
};

class DistanceCalculator {
public:
    // Calculates the Euclidean distance between two Point objects.
    // Takes Point objects by const reference to avoid unnecessary copying and ensure data integrity.
    double calculateDistance(const Point& p1, const Point& p2) {
        // Directly access private members x and y of Point objects due to friend declaration
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        
        // Calculate the squared distance
        double squared_distance = dx * dx + dy * dy;
        
        // Return the square root of the squared distance
        return std::sqrt(squared_distance);
    }
};

int main() {
    double x1, y1, x2, y2;
    // Read coordinates from standard input until EOF
    while (std::cin >> x1 >> y1 >> x2 >> y2) {
        // Create Point objects
        Point p1(x1, y1);
        Point p2(x2, y2);
        
        // Create a DistanceCalculator object
        DistanceCalculator calculator;
        
        // Calculate the distance
        double distance = calculator.calculateDistance(p1, p2);
        
        // Print the result formatted to two decimal places
        std::cout << std::fixed << std::setprecision(2) << distance << std::endl;
    }
    return 0;
}