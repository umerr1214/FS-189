#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Correct Version:
// - Point class with appropriate constructor.
// - Binary + operator overloaded as a non-member friend function for symmetry.
// - Operands are taken by const reference to avoid unnecessary copies.
// - Returns a new Point object by value.

class Point {
public:
    int x;
    int y;

    // Constructor
    Point(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    // Declare the operator+ as a friend function for direct access to private members (if they were private)
    // and to allow it to be a non-member function while still accessing Point internals.
    // For public members, 'friend' is not strictly needed but is common practice for operator overloads
    // to signal its close relationship with the class.
    friend Point operator+(const Point& p1, const Point& p2);

    // Display method for easy printing
    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

// Overload the binary + operator as a non-member function
// Takes operands by const reference to avoid unnecessary copies and ensure they are not modified.
// Returns a new Point object by value.
Point operator+(const Point& p1, const Point& p2) {
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