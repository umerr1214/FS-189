#include <iostream>
#include <vector>
#include <cmath> // For std::sqrt, though not used for comparison in this version
#include <limits> // For std::numeric_limits

struct Point {
    int x;
    int y;
};

// Function to calculate squared distance from origin
long long getSquaredDistance(const Point& p) {
    return static_cast<long long>(p.x) * p.x + static_cast<long long>(p.y) * p.y;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    // ROBUSTNESS ISSUE: This code does not handle the case where N=0 (empty vector)
    // Accessing points[0] will result in undefined behavior (e.g., a crash)
    // if N is 0.
    Point closest_point = points[0]; // CRASH/UNDEFINED BEHAVIOR if N=0
    long long min_squared_distance = getSquaredDistance(points[0]); // CRASH/UNDEFINED BEHAVIOR if N=0

    for (int i = 1; i < N; ++i) {
        long long current_squared_distance = getSquaredDistance(points[i]);
        if (current_squared_distance < min_squared_distance) {
            min_squared_distance = current_squared_distance;
            closest_point = points[i];
        }
    }

    std::cout << closest_point.x << " " << closest_point.y << std::endl;

    return 0;
}