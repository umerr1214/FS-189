#include <iostream>
#include <string>

class Point {
public:
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

// Overload == operator with a logical error
// It incorrectly returns true if *either* x or y coordinates match,
// instead of requiring *both* to match.
bool operator==(const Point& p1, const Point& p2) {
    return p1.x == p2.x || p1.y == p2.y; // Logical error: should be '&&' (AND)
}

void run_test(const std::string& name, const Point& p1, const Point& p2, bool expected_result) {
    bool actual_result = (p1 == p2);
    std::cout << name << ": Point(" << p1.x << "," << p1.y << ") == Point(" << p2.x << "," << p2.y << ") -> "
              << (actual_result ? "true" : "false")
              << " (Expected: " << (expected_result ? "true" : "false") << ")" << std::endl;
}

int main() {
    Point p1(1, 2);
    Point p2(1, 2); // Both match
    Point p3(1, 4); // x matches, y differs
    Point p4(3, 2); // y matches, x differs
    Point p5(3, 4); // Neither matches

    run_test("Test 1", p1, p2, true);  // Correct: true == true
    run_test("Test 2", p1, p3, false); // Incorrect: true == false (due to ||)
    run_test("Test 3", p1, p4, false); // Incorrect: true == false (due to ||)
    run_test("Test 4", p1, p5, false); // Correct: false == false

    return 0;
}