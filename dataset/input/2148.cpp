#include <iostream>
#include <sstream>

class Point {
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    // Semantic Error: Increments *this, but returns a reference to a static local object.
    // This violates the semantic contract of prefix `++` to return a reference to the modified object itself.
    Point& operator++() {
        x++; // 'this' object is incremented
        y++; // 'this' object is incremented

        // Create a static Point to return a reference to.
        // This static object will hold the *current* state of the incremented point,
        // but it is NOT the object 'this'.
        static Point temp_static_point;
        temp_static_point.x = x;
        temp_static_point.y = y;
        return temp_static_point; // Returns a reference to a different static object
    }
};

int main() {
    std::stringstream ss;

    // Test Case 1: Basic increment - appears correct
    Point p1(1, 2);
    ss << "Initial p1: " << p1 << std::endl;
    ++p1;
    ss << "After ++p1: " << p1 << std::endl;

    // Test Case 2: Return value of prefix increment - demonstrates the semantic error
    Point p2(5, 5);
    Point& ref_p2 = ++p2; // p2 becomes (6,6). ref_p2 points to static temp_static_point, which is (6,6)
    ss << "After ++p2, p2: " << p2 << std::endl; // p2 is (6,6)
    ss << "Reference ref_p2: " << ref_p2 << std::endl; // ref_p2 is (6,6)
    ref_p2.x = 10; // Modifies static temp_static_point, NOT p2
    ss << "After ref_p2.x = 10, p2: " << p2 << std::endl; // p2 is still (6,6) - INCORRECT
    ss << "After ref_p2.x = 10, ref_p2: " << ref_p2 << std::endl; // ref_p2 is (10,6)

    // Test Case 3: Chained increment - further highlights the static object issue
    Point p3(10, 20);
    ss << "Initial p3: " << p3 << std::endl;
    // ++(++p3)
    // 1. Inner ++p3: p3 becomes (11,21). static temp_static_point becomes (11,21). Returns ref to temp_static_point.
    // 2. Outer ++(ref to temp_static_point): static temp_static_point becomes (12,22). Returns ref to temp_static_point.
    Point& ref_chain = ++(++p3);
    ss << "After ++(++p3), p3: " << p3 << std::endl; // p3 is (11,21) - INCORRECT (should be (12,22))
    ss << "Reference ref_chain from ++(++p3): " << ref_chain << std::endl; // ref_chain is (12,22)

    // Additional test to highlight static behavior (all references point to the same static object)
    Point p4(100, 100);
    Point& ref_p4 = ++p4; // p4=(101,101). static temp_static_point becomes (101,101).
    ss << "After ++p4, p4: " << p4 << std::endl;
    ss << "Reference ref_p4: " << ref_p4 << std::endl; // ref_p4 is (101,101)
    
    // Now, previous references (ref_p2 and ref_chain) will also reflect the state of temp_static_point
    ss << "Re-checking ref_p2 (should be (10,6) but is now (101,101)): " << ref_p2 << std::endl;
    ss << "Re-checking ref_chain (should be (12,22) but is now (101,101)): " << ref_chain << std::endl;

    std::cout << ss.str();
    return 0;
}