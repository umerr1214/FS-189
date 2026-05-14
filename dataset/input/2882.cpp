#include <iostream>
#include <cmath>
#include <iomanip>

// Forward declaration of DistanceCalculator
class DistanceCalculator;

class Point {
private:
    double x;
    double y;

public:
    Point(double _x, double _y) : x(_x), y(_y) {}

    // Declare DistanceCalculator as a friend class
    friend class DistanceCalculator;
};

class DistanceCalculator {
public:
    // Readability / Efficiency Issue:
    // The calculateDistance method takes Point objects by value (Point p1, Point p2)
    // instead of by const reference (const Point& p1, const Point& p2).
    // This causes unnecessary copying of Point objects, which is inefficient,
    // especially for larger objects, and can impact performance.
    double calculateDistance(Point p1, Point p2) { // Pass by value - efficiency issue
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        double squared_distance = dx * dx + dy * dy;
        return std::sqrt(squared_distance);
    }
};

int main() {
    double x1, y1, x2, y2;
    while (std::cin >> x1 >> y1 >> x2 >> y2) {
        Point p1(x1, y1);
        Point p2(x2, y2);
        DistanceCalculator calculator;
        double distance = calculator.calculateDistance(p1, p2);
        std::cout << std::fixed << std::setprecision(2) << distance << std::endl;
    }
    return 0;
}