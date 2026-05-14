#include <iostream>
#include <cmath> // For std::sqrt and std::pow
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

struct Point {
    int x;
    int y;
};

// Function with readability and efficiency issues
float distance(Point p1, Point p2) { // Using float for return type and calculations
    float dX = static_cast<float>(p1.x - p2.x); // Less descriptive variable name (dX, dY instead of delta_x, delta_y)
    float dY = static_cast<float>(p1.y - p2.y);

    // Inefficient: Using std::pow(x, 2) instead of x*x for squaring.
    // std::pow is a general-purpose exponentiation function and is typically slower than simple multiplication.
    float sq1 = std::pow(dX, 2);
    float sq2 = std::pow(dY, 2);

    float total_sq = sq1 + sq2; // Could be combined for slightly better efficiency
    float res = std::sqrt(total_sq); // Using float for sqrt, which has lower precision than double

    return res;
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
        float dist = distance(p1, p2); // Note: dist is float here
        std::cout << "Distance between (" << p1.x << ", " << p1.y << ") and ("
                  << p2.x << ", " << p2.y << ") is: "
                  << std::fixed << std::setprecision(10) << dist << std::endl;
    }
    return 0;
}