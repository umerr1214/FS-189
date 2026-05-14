#include <iostream>
#include <string>

class Point {
public:
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Overload == operator as a member function with a semantic error
    // It modifies the 'this' object by incrementing x, which is semantically incorrect
    // for a comparison operator. Comparison operators should not have side effects.
    bool operator==(const Point& other) {
        this->x++; // Semantic error: Modifying 'this' object
        return this->x == other.x && this->y == other.y;
    }
};

void run_test(const std::string& name, Point p1_initial, const Point& p2) {
    Point p1_copy = p1_initial; // Use a copy to ensure each test starts with original p1 value
    std::cout << name << ": Point(" << p1_copy.x << "," << p1_copy.y << ") == Point(" << p2.x << "," << p2.y << ") -> "
              << (p1_copy == p2 ? "true" : "false") << std::endl;
    std::cout << "  (p1 after comparison: Point(" << p1_copy.x << "," << p1_copy.y << "))" << std::endl;
}

int main() {
    // Test 1: Identical points - Expected true, but side effect makes it false
    run_test("Test 1", Point(1, 2), Point(1, 2));

    // Test 2: Different points - Expected false, still false, but p1 is modified
    run_test("Test 2", Point(1, 2), Point(3, 4));

    // Test 3: Demonstrating repeated comparison side effect
    Point p_test(10, 20);
    Point p_target(11, 20); // This target will match p_test.x after one increment

    std::cout << "\nTest 3 (repeated comparison with side effect):" << std::endl;
    std::cout << "  Initial p_test: (" << p_test.x << "," << p_test.y << ")" << std::endl;

    // First comparison: p_test (10,20) vs p_target (11,20)
    // p_test.x becomes 11. Compares (11,20) == (11,20) -> true
    std::cout << "  p_test == p_target (1st call): " << (p_test == p_target ? "true" : "false") << std::endl;
    std::cout << "  p_test after 1st call: (" << p_test.x << "," << p_test.y << ")" << std::endl;

    // Second comparison: p_test (11,20) vs p_target (11,20)
    // p_test.x becomes 12. Compares (12,20) == (11,20) -> false
    std::cout << "  p_test == p_target (2nd call): " << (p_test == p_target ? "true" : "false") << std::endl;
    std::cout << "  p_test after 2nd call: (" << p_test.x << "," << p_test.y << ")" << std::endl;

    return 0;
}