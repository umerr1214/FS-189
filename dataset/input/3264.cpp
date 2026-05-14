#include <iostream>

class Counter {
private:
    int count;

public:
    Counter(int initialCount = 0) : count(initialCount) {}

    // Prefix increment operator (SEMANTIC ERROR: returns Counter by value, should return Counter&)
    // This compiles, but breaks the standard behavior of prefix increment for chaining or using the result as an lvalue.
    Counter operator++() {
        ++count;
        return *this; // Returns a copy of the incremented object.
                      // Semantically, for prefix increment, it should return *this by reference (Counter&).
    }

    // Postfix increment operator (correct)
    Counter operator++(int) {
        Counter temp = *this;
        ++count;
        return temp;
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter c1(5);
    std::cout << "c1 initial: " << c1.getCount() << std::endl; // Expected: 5

    ++c1; // c1 becomes 6. This works as a statement.
    std::cout << "c1 after prefix ++: " << c1.getCount() << std::endl; // Expected: 6

    // Demonstrate the semantic issue: chaining.
    // Correct behavior: c1 = 6 -> ++c1 (c1 becomes 7) -> ++c1 (c1 becomes 8). c_chained = 8.
    // Buggy behavior: c1 = 6 -> ++c1 returns a COPY (value 7) -> ++(copy) (copy becomes 8). c1 remains 7. c_chained = 8.
    Counter c_chained = ++(++c1);
    std::cout << "c1 after chained prefix ++: " << c1.getCount() << std::endl; // Expected: 8 (if correct), but will be 7 (due to error)
    std::cout << "c_chained value: " << c_chained.getCount() << std::endl; // Expected: 8

    Counter c2 = c1++; // c1 becomes 8. c2 should be 7 (c1's value before this increment).
    std::cout << "c1 after postfix ++ (assigned to c2): " << c1.getCount() << std::endl; // Expected: 8
    std::cout << "c2 (value before increment): " << c2.getCount() << std::endl; // Expected: 7

    return 0;
}