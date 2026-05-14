#include <iostream>

class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}
    int getCount() const { return count; }

    // LOGICAL ERROR: Returns by value instead of by reference as required.
    // This compiles, but leads to incorrect behavior when chaining or expecting a reference.
    Counter operator++() { // Should be Counter& operator++()
        ++count;
        return *this; // Returns a copy of *this
    }
};

int main() {
    Counter c1(5);
    std::cout << "Initial c1 count: " << c1.getCount() << std::endl; // Expected: 5

    // First increment
    Counter c2 = ++c1;
    std::cout << "After first ++ (c1): " << c1.getCount() << std::endl; // Expected: 6
    std::cout << "After first ++ (c2): " << c2.getCount() << std::endl; // Expected: 6

    // Chained increment to highlight the 'by reference' requirement
    // If operator++ returned by reference, ++(++c1) would increment c1 twice.
    // With current implementation, it increments c1 once, then increments a temporary copy.
    std::cout << "Before chained ++ (c1): " << c1.getCount() << std::endl; // Expected: 6
    Counter c3 = ++(++c1); // Correct behavior would make c1 = 7, then 8, c3 = 8.
                           // Actual behavior: c1 becomes 7. A temporary copy of c1 (value 7) is made.
                           //                  This temporary copy is incremented to 8. c3 gets 8.
                           //                  So, c1 should be 8, but it's 7 due to returning by value.
    std::cout << "After chained ++ (c1): " << c1.getCount() << std::endl; // ACTUAL: 7, EXPECTED: 8
    std::cout << "After chained ++ (c3): " << c3.getCount() << std::endl; // Expected: 8

    return 0;
}