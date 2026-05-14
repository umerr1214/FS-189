#include <iostream>
#include <string>
#include <sstream>

class Counter {
private:
    int count;

public:
    // Constructor
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
        Counter temp = *this; // Save current state using copy constructor
        --count;              // Decrement original object
        return temp;          // Return saved state
    }

    // Getter for count
    int getCount() const {
        return count;
    }
};

int main() {
    std::stringstream ss;

    // Test Case 1: Initial value and basic operations
    Counter c1(10);
    ss << "Initial c1: " << c1.getCount() << std::endl; // Expected: 10

    // Prefix increment
    Counter& c1_ref = ++c1; // c1 becomes 11, c1_ref refers to c1
    ss << "After ++c1: " << c1.getCount() << std::endl; // Expected: 11
    ss << "c1_ref count: " << c1_ref.getCount() << std::endl; // Expected: 11

    // Postfix decrement
    Counter c1_old_value = c1--; // c1_old_value gets 11, c1 becomes 10
    ss << "After c1-- (returned value): " << c1_old_value.getCount() << std::endl; // Expected: 11
    ss << "After c1-- (original c1): " << c1.getCount() << std::endl; // Expected: 10

    // Test Case 2: Chaining operations
    Counter c2(0);
    ss << "Initial c2: " << c2.getCount() << std::endl; // Expected: 0

    // Chaining prefix increments
    ++(++c2); // c2 becomes 2
    ss << "After ++(++c2): " << c2.getCount() << std::endl; // Expected: 2

    // Postfix decrement in an expression
    Counter c3(5);
    ss << "Initial c3: " << c3.getCount() << std::endl; // Expected: 5
    int result = (c3--).getCount() + (++c3).getCount(); // c3-- returns 5, c3 becomes 4. Then ++c3 makes c3 5. Result = 5 + 5 = 10
    ss << "Result of (c3--).getCount() + (++c3).getCount(): " << result << std::endl; // Expected: 10
    ss << "Final c3: " << c3.getCount() << std::endl; // Expected: 5

    std::cout << ss.str();

    return 0;
}