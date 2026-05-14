#include <iostream>

class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}

    int getValue() const {
        return value;
    }

    // Pre-increment operator (prefix)
    // Increments the object and returns a reference to the incremented object.
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Post-increment operator (postfix) - ROBUSTNESS ISSUE
    // This implementation INCORRECTLY returns the incremented object itself,
    // instead of the object's state *before* incrementing.
    // This violates the expected semantics of post-increment (which should return the old value).
    Counter operator++(int) {
        // Create a temporary copy of the current state.
        // The intention is to return this temporary.
        Counter temp = *this;
        
        // Increment the original object.
        ++value;
        
        // ROBUSTNESS ISSUE: Instead of returning 'temp' (the old state),
        // it returns '*this' (the new, incremented state).
        // This makes `c++` behave like `++c` in terms of the returned value.
        return *this; // Should be 'return temp;'
    }
};

int main() {
    std::cout << "--- Testing Robustness Issue (Post-increment) ---" << std::endl;

    // Test pre-increment (should work correctly)
    Counter c1(5);
    std::cout << "c1 initial: " << c1.getValue() << std::endl; // Expected: 5
    std::cout << "Value of (++c1): " << (++c1).getValue() << std::endl; // c1 becomes 6, prints 6
    std::cout << "c1 after pre-inc: " << c1.getValue() << std::endl; // Expected: 6

    std::cout << std::endl;

    // Test post-increment (will show the robustness issue)
    Counter c2(10);
    std::cout << "c2 initial: " << c2.getValue() << std::endl; // Expected: 10
    // The expression (c2++) should return 10, but due to the bug, it will return 11.
    std::cout << "Value of (c2++): " << (c2++).getValue() << std::endl; // Expected: 10 (bug: prints 11)
    std::cout << "c2 after post-inc: " << c2.getValue() << std::endl; // Expected: 11

    std::cout << std::endl;

    // Further demonstration of the bug
    Counter c3(20);
    std::cout << "c3 initial: " << c3.getValue() << std::endl; // Expected: 20
    Counter c3_result = c3++;
    std::cout << "c3 after c3++: " << c3.getValue() << std::endl; // Expected: 21
    // Due to the bug, c3_result will be 21, not 20.
    std::cout << "c3_result (from c3++): " << c3_result.getValue() << std::endl; // Expected: 20 (bug: prints 21)

    return 0;
}