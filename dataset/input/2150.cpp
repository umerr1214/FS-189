#include <iostream>
#include <string>
#include <sstream>
#include <limits> // Included for consistency, not directly used in this operator++

class Point {
public:
    int x, y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    Point& operator++() {
        // Readability / Efficiency Issue:
        // This implementation creates a temporary Point object to calculate
        // the new values, then assigns those values back to the current object.
        // This is less efficient (involves an extra constructor call and object creation)
        // and less idiomatic/readable than directly incrementing the 'x' and 'y' members.
        Point new_point_val(this->x + 1, this->y + 1);
        this->x = new_point_val.x;
        this->y = new_point_val.y;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        char paren, comma;
        int x, y;
        ss >> paren >> x >> comma >> y >> paren; // Read (x,y)
        Point p(x, y);
        ++p; // Apply prefix increment
        std::cout << p << std::endl; // Print the result
    }
    return 0;
}