#include <iostream>
#include <string>
#include <sstream>

class Counter {
public:
    int count; // Robustness Issue: 'count' member is public

    Counter(int initial = 0) : count(initial) {}

    // Prefix increment: ++counter
    // Returns a reference to the modified object
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Postfix decrement: counter--
    // Returns a temporary object before decrementing
    Counter operator--(int) {
        Counter temp = *this; // Save current state
        --count;              // Decrement original object
        return temp;          // Return saved state
    }

    int getCount() const {
        return count;
    }
};

int main() {
    std::stringstream ss;

    // Test Case 1: Initial value and basic operations
    Counter c1(5);
    ss << "Initial c1: " << c1.getCount() << std::endl; // Expected: 5

    ++c1;
    ss << "After ++c1: " << c1.getCount() << std::endl; // Expected: 6

    c1--;
    ss << "After c1-- (original): " << c1.getCount() << std::endl; // Expected: 5

    // Robustness Issue demonstration: direct modification of public member
    c1.count = 10; // Directly modifying the public 'count' member
    ss << "After direct c1.count = 10: " << c1.getCount() << std::endl; // Expected: 10

    ++c1;
    ss << "After ++c1 (after direct modification): " << c1.getCount() << std::endl; // Expected: 11

    // Test Case 2: Chaining operations and postfix return value
    Counter c2(0);
    ss << "Initial c2: " << c2.getCount() << std::endl; // Expected: 0

    Counter temp_c2 = c2--; // temp_c2 gets 0, c2 becomes -1
    ss << "c2-- returned: " << temp_c2.getCount() << std::endl; // Expected: 0
    ss << "After c2-- (original c2): " << c2.getCount() << std::endl; // Expected: -1

    std::cout << ss.str();

    return 0;
}