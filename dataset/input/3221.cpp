#include <iostream>
#include <string>

class Point {
private:
    int x;
    int y;
public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    // Non-const version of getX() - LOGICAL ERROR: returns y instead of x
    int getX() {
        std::cout << "(Non-const getX() invoked) ";
        return y; // Should return x
    }

    // Const version of getX()
    int getX() const {
        std::cout << "(Const getX() invoked) ";
        return x;
    }

    void printExplanation() const {
        std::cout << "Explanation:\n";
        std::cout << "The non-const getX() method (int getX()) is called on mutable Point objects.\n";
        std::cout << "It can potentially modify the object's state (though it doesn't in this example).\n";
        std::cout << "The const getX() method (int getX() const) is called on const Point objects,\n";
        std::cout << "or on objects accessed via const references/pointers.\n";
        std::cout << "It guarantees not to modify the object's state.\n";
    }
};

int main() {
    Point p(10, 20);
    const Point cp(30, 40);

    std::cout << "Non-const getX() called: " << p.getX() << std::endl;
    std::cout << "Const getX() called: " << cp.getX() << std::endl;

    p.printExplanation();
    return 0;
}