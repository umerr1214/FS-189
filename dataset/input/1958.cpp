#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Readability / Efficiency Issue:
// 1. operator+ is a member function, which is less symmetric than a non-member friend for binary arithmetic operators.
// 2. The implementation of operator+ is less efficient by creating a default-constructed temporary object
//    and then assigning its members, rather than directly constructing the result.

class Point {
public:
    int x;
    int y;

    // Default constructor
    Point() : x(0), y(0) {}

    // Parameterized constructor
    Point(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}

    // Overload the binary + operator as a member function
    // Readability Issue: Member functions for binary arithmetic operators like + are often considered less symmetric.
    // Efficiency Issue: Creates a default-constructed `temp` object, then assigns its members.
    // This involves default construction + two assignments + copy/move, which is less efficient
    // than directly constructing the `Point` in the return statement (e.g., `return Point(x + other.x, y + other.y);`).
    Point operator+(const Point& other) const {
        Point temp; // Default construct a temporary object
        temp.x = this->x + other.x; // Assign x coordinate
        temp.y = this->y + other.y; // Assign y coordinate
        return temp; // Return the temporary object (potentially involves copy/move)
    }

    // Display method for easy printing
    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

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