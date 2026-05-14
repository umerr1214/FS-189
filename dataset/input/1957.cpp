#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Robustness Issue: operator+ takes Point objects by value,
// causing unnecessary copies, which can be a performance robustness issue
// for larger objects or in high-performance contexts.

class Point {
public:
    int x;
    int y;

    // Constructor
    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Display method for easy printing
    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

// Overload the binary + operator as a non-member function
// Robustness Issue: Takes Point by value instead of const Point&
Point operator+(Point p1, Point p2) {
    // This creates copies of p1 and p2 before even starting the sum.
    // For simple int members, this is not critical, but for objects
    // with complex constructors/destructors or large data, it's inefficient.
    return Point(p1.x + p2.x, p1.y + p2.y);
}

int main() {
    std::vector<std::pair<Point, Point>> test_inputs = {
        {{1, 2}, {3, 4}},
        {{0, 0}, {-1, 5}},
        {{10, -5}, {-5, 10}},
        {{-2, -3}, {-1, -1}},
        {{100, 200}, {300, 400}}
    };

    std::vector<std::string> expected_outputs = {
        "(4, 6)",
        "(-1, 5)",
        "(5, 5)",
        "(-3, -4)",
        "(400, 600)"
    };

    for (size_t i = 0; i < test_inputs.size(); ++i) {
        Point p1 = test_inputs[i].first;
        Point p2 = test_inputs[i].second;
        Point sum = p1 + p2;
        
        std::stringstream ss;
        ss << "(" << sum.x << ", " << sum.y << ")";
        std::string actual_output = ss.str();

        std::cout << "Test " << i + 1 << ": ";
        if (actual_output == expected_outputs[i]) {
            std::cout << "Passed. Result: " << actual_output << std::endl;
        } else {
            std::cout << "Failed. Expected: " << expected_outputs[i] << ", Got: " << actual_output << std::endl;
        }
    }

    return 0;
}