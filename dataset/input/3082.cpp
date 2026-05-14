#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    // Syntax error: Missing parenthesis after operator==
    bool operator== Point& other) const {
        return (x == other.x && y == other.y);
    }
};

int main() {
    Point p1(10, 20);
    Point p2(10, 20);
    Point p3(5, 10);

    // This code will not compile due to the syntax error in the Point class.
    // If it were to compile, the expected outputs are:
    // p1 and p2 are equal.
    // p1 and p3 are not equal.

    // The lines below are commented out to allow for a clearer test case description
    // in the JSON, as the program won't actually execute these comparisons.
    /*
    if (p1 == p2) {
        std::cout << "p1 and p2 are equal." << std::endl;
    } else {
        std::cout << "p1 and p2 are not equal." << std::endl;
    }

    if (p1 == p3) {
        std::cout << "p1 and p3 are equal." << std::endl;
    } else {
        std::cout << "p1 and p3 are not equal." << std::endl;
    }
    */

    return 0;
}