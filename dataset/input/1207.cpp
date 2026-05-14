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
    // p1 is passed by non-const reference, allowing modification
    friend Point operator+(Point& p1, const Point& p2);
};

// Robustness Issue: The operator modifies its first operand (p1)
// instead of returning a new Point and leaving operands unchanged.
Point operator+(Point& p1, const Point& p2) {
    p1.x += p2.x; // Modifies p1
    p1.y += p2.y; // Modifies p1
    return p1;    // Returns the modified p1
}

int main() {
    std::vector<std::tuple<int, int, int, int, std::string, std::string>> test_cases_data = {
        {1, 2, 3, 4, "(4, 6)", "(4, 6)"}, // Expected sum, Expected p1 after sum
        {-1, 0, 1, 0, "(0, 0)", "(0, 0)"},
        {10, -5, -3, 8, "(7, 3)", "(7, 3)"},
        {0, 0, 0, 0, "(0, 0)", "(0, 0)"},
        {100, 200, -50, -100, "(50, 100)", "(50, 100)"}
    };

    std::stringstream ss_output;
    for (const auto& test : test_cases_data) {
        Point p1(std::get<0>(test), std::get<1>(test)); // p1 is a mutable object
        Point p2(std::get<2>(test), std::get<3>(test));
        
        Point sum = p1 + p2; // This calls the overloaded operator, modifying p1
        
        ss_output << "Sum: " << sum.toString() << ", p1 after: " << p1.toString() << std::endl;
    }
    std::cout << ss_output.str();

    return 0;
}