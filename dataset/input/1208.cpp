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

    // Readability/Efficiency Issue: Operator takes Point by value (unnecessary copy)
    // and constructs result less efficiently/readably.
    Point operator+(Point other) const { // 'other' is passed by value, causing a copy
        Point result; // Default-constructs, then assigns members individually
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result;
    }
};

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