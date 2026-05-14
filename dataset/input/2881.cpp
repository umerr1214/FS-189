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
    // Robustness Issue: This method returns an integer, truncating the actual double distance.
    // For example, a distance of 1.41 will be returned as 1.
    int calculateDistance(const Point& p1, const Point& p2) {
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        double squared_distance = dx * dx + dy * dy;
        return static_cast<int>(std::sqrt(squared_distance)); // Truncation happens here
    }
};

int main() {
    double x1, y1, x2, y2;
    while (std::cin >> x1 >> y1 >> x2 >> y2) {
        Point p1(x1, y1);
        Point p2(x2, y2);
        DistanceCalculator calculator;
        int distance_int = calculator.calculateDistance(p1, p2); // Get the truncated integer distance
        // Cast back to double for printing to match expected output format,
        // but the value itself reflects the truncation.
        std::cout << std::fixed << std::setprecision(2) << static_cast<double>(distance_int) << std::endl;
    }
    return 0;
}