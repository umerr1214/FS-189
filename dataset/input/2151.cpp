#include <iostream>
#include <string>
#include <sstream>
#include <limits> // Included for consistency, not directly used in this operator++

class Point {
public:
    int x, y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    Point& operator++() {
        // Correct Version:
        // This is the standard, idiomatic, and efficient implementation
        // for the prefix increment operator. It directly increments
        // the 'x' and 'y' members and returns a reference to the
        // modified object itself (*this).
        ++x;
        ++y;
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