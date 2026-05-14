#include <iostream>
#include <cmath> // For std::sqrt
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

struct Point {
    int x;
    int y;
};

// Correct and efficient implementation of Euclidean distance
double distance(Point p1, Point p2) {
    // Calculate differences, casting to long long to prevent overflow if (p1.x - p2.x) itself is large
    long long dx = static_cast<long long>(p1.x) - p2.x;
    long long dy = static_cast<long long>(p1.y) - p2.y;

    // Use long long for squared differences to prevent overflow for large int coordinates.
    // Convert the sum to double before taking the square root to maintain precision.
    double dist_sq = static_cast<double>(dx * dx + dy * dy);
    
    return std::sqrt(dist_sq);
}

int main() {
    std::vector<std::pair<Point, Point>> test_inputs = {
        {{0, 0}, {3, 4}},
        {{1, 1}, {-2, -3}},
        {{10, 20}, {10, 20}},
        {{-5, 5}, {5, -5}},
        {{100000, 0}, {0, 0}},
        {{100000, 200000}, {0, 0}}
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