#include <iostream>
#include <vector>
#include <cmath> // Not strictly needed for squared distance, but good practice

// Define struct Point
struct Point {
    int x;
    int y;
} // Syntax Error: Missing semicolon here

int main() {
    // Array of Point objects
    std::vector<Point> points = {{1, 2}, {3, -4}, {-1, 5}, {0, 0}, {2, 2}};

    if (points.empty()) {
        std::cout << "No points to process." << std::endl;
        return 0;
    }

    Point closestPoint = points[0];
    long long min_dist_sq = (long long)points[0].x * points[0].x + (long long)points[0].y * points[0].y;

    for (size_t i = 1; i < points.size(); ++i) {
        long long current_dist_sq = (long long)points[i].x * points[i].x + (long long)points[i].y * points[i].y;
        if (current_dist_sq < min_dist_sq) {
            min_dist_sq = current_dist_sq;
            closestPoint = points[i];
        }
    }

    std::cout << "Closest point to origin: (" << closestPoint.x << "," << closestPoint.y << ")" << std::endl;

    return 0;
}