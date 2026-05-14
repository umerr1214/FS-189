#include <iostream>
#include <vector>
#include <cmath> // Not strictly needed if only comparing squared distances, but good practice for math operations
#include <limits> // For std::numeric_limits

struct Point {
    int x;
    int y;
};

// Helper function to calculate the squared Euclidean distance from the origin.
// Using long long to prevent potential overflow for squared coordinates if x or y are large.
long long getSquaredDistance(const Point& p) {
    return static_cast<long long>(p.x) * p.x + static_cast<long long>(p.y) * p.y;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_points;
    std::cin >> num_points;

    std::vector<Point> points(num_points);
    for (int i = 0; i < num_points; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    // Handle the edge case where no points are provided.
    if (num_points == 0) {
        std::cout << "No points provided." << std::endl;
        return 0;
    }

    // Initialize the closest point and its squared distance with the first point.
    Point closest_point = points[0];
    long long min_squared_distance = getSquaredDistance(points[0]);

    // Iterate through the remaining points to find the closest one.
    // Comparing squared distances avoids costly std::sqrt operations and floating-point precision issues.
    for (int i = 1; i < num_points; ++i) {
        long long current_squared_distance = getSquaredDistance(points[i]);
        if (current_squared_distance < min_squared_distance) {
            min_squared_distance = current_squared_distance;
            closest_point = points[i];
        }
    }

    // Print the coordinates of the closest point.
    std::cout << closest_point.x << " " << closest_point.y << std::endl;

    return 0;
}