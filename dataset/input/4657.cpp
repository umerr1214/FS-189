#include <iostream>
#include <cmath> // For sqrt
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

struct Point {
    int x;
    int y;
};

// Function with a robustness issue: integer overflow for intermediate squared differences
double distance(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;

    // Robustness issue: dx*dx and dy*dy can overflow an 'int' if dx or dy are large.
    // This will lead to incorrect calculations for large coordinates.
    // For example, if dx = 100,000, dx*dx = 10,000,000,000, which exceeds INT_MAX (~2*10^9).
    int dx_sq = dx * dx; // Potential overflow here
    int dy_sq = dy * dy; // Potential overflow here

    double dist_sq = static_cast<double>(dx_sq + dy_sq);
    return std::sqrt(dist_sq);
}

int main() {
    std::vector<std::pair<Point, Point>> test_inputs = {
        {{0, 0}, {3, 4}},
        {{1, 1}, {-2, -3}},
        {{10, 20}, {10, 20}},
        {{-5, 5}, {5, -5}},
        {{100000, 0}, {0, 0}}, // dx = 100000, dx*dx overflows int
        {{100000, 200000}, {0, 0}} // dx = 100000, dy = 200000, both squared terms overflow int
    };

    for (const auto& pair : test_inputs) {
        Point p1 = pair.first;
        Point p2 = pair.second;
        double dist = distance(p1, p2);
        std::cout << "Distance between (" << p1.x << ", " << p1.y << ") and ("
                  << p2.x << ", " << p2.y << ") is: "
                  << std::fixed << std::setprecision(10) << dist << std::endl;
    }
    return 0;
}