#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple> // For std::get in driver

class Point {
public:
    int x;
    int y;

    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    // Friend declaration for the non-member operator+
    friend Point operator+(const Point& p1, const Point& p2);
};

// Correct Version: Non-member operator, takes const references, returns new Point.
Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

int main() {
    std::vector<std::tuple<int, int, int, int, std::string>> test_cases = {
        {1, 2, 3, 4, "(4, 6)"},
        {-1, 0, 1, 0, "(0, 0)"},
        {10, -5, -3, 8, "(7, 3)"},
        {0, 0, 0, 0, "(0, 0)"},
        {100, 200, -50, -100, "(50, 100)"}
    };

    std::stringstream ss_output;
    for (const auto& test : test_cases) {
        Point p1(std::get<0>(test), std::get<1>(test));
        Point p2(std::get<2>(test), std::get<3>(test));
        Point sum = p1 + p2; // This calls the overloaded operator
        ss_output << sum.toString() << std::endl;
    }
    std::cout << ss_output.str();

    return 0;
}