#include <iostream>
#include <string>
#include <sstream>
#include <limits> // For INT_MAX, relevant for robustness discussion

class Point {
public:
    int x, y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    Point& operator++() {
        // Robustness Issue:
        // This implementation does not check for potential integer overflow.
        // If 'x' or 'y' is at std::numeric_limits<int>::max() (INT_MAX)
        // and is incremented, it results in undefined behavior according to C++ standard.
        // While common systems might wrap around, this is not guaranteed and
        // can lead to unexpected results or crashes in a truly robust application.
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