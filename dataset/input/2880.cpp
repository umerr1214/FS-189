#include <iostream>
#include <cmath>

class Point {
private:
    double x;
    double y;

public:
    Point(double _x, double _y) : x(_x), y(_y) {}

    // Public getters, introduced for the semantic error scenario
    double getX() const { return x; }
    double getY() const { return y; }

    friend class DistanceCalculator;
};

class DistanceCalculator {
public:
    double calculateDistance(const Point& p1, const Point& p2) {
        // SEMANTIC ERROR: DistanceCalculator is a friend of Point, but it uses public getters
        // instead of directly accessing the private members (p1.x, p1.y).
        // This violates the problem's explicit requirement for direct access facilitated by the friend relationship.
        double dx = p1.getX() - p2.getX();
        double dy = p1.getY() - p2.getY();
        return std::sqrt(dx * dx + dy * dy);
    }
};

int main() {
    Point p1(1.0, 1.0);
    Point p2(4.0, 5.0);
    DistanceCalculator dc;
    double dist = dc.calculateDistance(p1, p2);
    std::cout << "Distance between (1,1) and (4,5): " << dist << std::endl;

    Point p3(0.0, 0.0);
    Point p4(3.0, 4.0);
    double dist2 = dc.calculateDistance(p3, p4);
    std::cout << "Distance between (0,0) and (3,4): " << dist2 << std::endl;
    return 0;
}