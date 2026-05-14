#include <iostream>
#include <vector>
#include <limits> // For std::numeric_limits, though not directly used in the error example

struct Point {
    int x;
    int y;
};

int main() {
    // Using larger coordinates to demonstrate potential integer overflow
    std::vector<Point> points = {{1, 2}, {50000, 50000}, {-100, 200}, {0, 0}, {30000, -40000}};

    if (points.empty()) {
        std::cout << "No points to process." << std::endl;
        return 0;
    }

    Point closestPoint = points[0];
    // Semantic Error: Potential integer overflow during multiplication.
    // x*x and y*y are calculated using int types first, which can overflow if x or y are large (e.g., 50000).
    // The result of this overflowed int calculation is then implicitly converted to long long,
    // leading to an incorrect distance value.
    // Correct: (long long)points[0].x * points[0].x + (long long)points[0].y * points[0].y;
    long long min_dist_sq = points[0].x * points[0].x + points[0].y * points[0].y;

    for (size_t i = 1; i < points.size(); ++i) {
        // Same semantic error here
        long long current_dist_sq = points[i].x * points[i].x + points[i].y * points[i].y;
        if (current_dist_sq < min_dist_sq) {
            min_dist_sq = current_dist_sq;
            closestPoint = points[i];
        }
    }

    std::cout << "Closest point to origin: (" << closestPoint.x << "," << closestPoint.y << ")" << std::endl;

    return 0;
}