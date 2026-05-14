#include <iostream>
#include <vector>
#include <cmath> // Required for std::sqrt
#include <limits> // For std::numeric_limits, not directly used but common

struct Point {
    int x;
    int y;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N_points; // Less descriptive variable name
    std::cin >> N_points;

    std::vector<Point> pts(N_points); // Less descriptive variable name
    for (int i = 0; i < N_points; ++i) {
        std::cin >> pts[i].x >> pts[i].y;
    }

    if (N_points == 0) {
        std::cout << "No points provided." << std::endl;
        return 0;
    }

    // READABILITY / EFFICIENCY ISSUE:
    // 1. Uses std::sqrt in a loop, which is computationally more expensive
    //    than comparing squared distances and can introduce floating-point precision issues.
    // 2. Variable names like `min_d` and `curr_d` are less descriptive.
    Point min_pt = pts[0];
    double min_d = std::sqrt(static_cast<double>(min_pt.x) * min_pt.x + static_cast<double>(min_pt.y) * min_pt.y);

    for (int i = 1; i < N_points; ++i) {
        double curr_d = std::sqrt(static_cast<double>(pts[i].x) * pts[i].x + static_cast<double>(pts[i].y) * pts[i].y);
        if (curr_d < min_d) {
            min_d = curr_d;
            min_pt = pts[i];
        }
    }

    std::cout << min_pt.x << " " << min_pt.y << std::endl;

    return 0;
}