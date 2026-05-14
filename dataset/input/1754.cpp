#include <iostream>

class Point {
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

// Definition of the == operator
// Readability/Efficiency Issue:
// 1. Passes Point objects by value, which involves copying the objects.
//    While for a small class like Point it's not a major performance hit,
//    it's less efficient than passing by const reference and bad practice for larger objects.
// 2. Uses verbose if/else logic instead of a direct boolean return, reducing readability.
bool operator==(Point p1, Point p2) { // Efficiency: pass by value (copy)
    if (p1.x == p2.x) {
        if (p1.y == p2.y) {
            return true; // Readability: verbose if/else
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);

    std::cout << "Test Case 1: p1 == p2 (Expected: true, Actual: " << (p1 == p2 ? "true" : "false") << ")" << std::endl;
    std::cout << "Test Case 2: p1 == p3 (Expected: false, Actual: " << (p1 == p3 ? "true" : "false") << ")" << std::endl;

    Point p4(5, 6);
    Point p5(5, 7);
    std::cout << "Test Case 3: p4 == p5 (Expected: false, Actual: " << (p4 == p5 ? "true" : "false") << ")" << std::endl;

    Point p6(8, 8);
    Point p7(8, 8);
    std::cout << "Test Case 4: p6 == p7 (Expected: true, Actual: " << (p6 == p7 ? "true" : "false") << ")" << std::endl;

    // This version correctly handles temporaries because parameters are passed by value.
    std::cout << "Test Case 5: Point(10, 20) == Point(10, 20) (Expected: true, Actual: " << (Point(10, 20) == Point(10, 20) ? "true" : "false") << ")" << std::endl;

    return 0;
}