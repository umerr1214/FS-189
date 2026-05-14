#include <iostream>

class Counter {
private:
    int count;

public:
    Counter(int initial_count = 0) : count(initial_count) {}

    int get_count() const {
        return count;
    }

    void set_count(int val) { // Added for testing the reference semantic
        count = val;
    }

    // Prefix increment: ++prefix
    // SEMANTIC ERROR: Returns by value (Counter) instead of by reference (Counter&)
    // This violates the contract specified in the question ("return a reference to the modified object").
    Counter operator++() { // Should be Counter&
        ++count;
        return *this;
    }

    // Postfix decrement: postfix--
    // Correct implementation for postfix decrement
    Counter operator--(int) { // The 'int' parameter is a dummy for postfix
        Counter temp = *this; // Save current state
        --count;              // Decrement
        return temp;          // Return saved state
    }
};

int main() {
    // This main function is just for compilation and basic demonstration.
    // The actual testing logic is in the JSON driver.
    Counter c(5);
    std::cout << "Initial count: " << c.get_count() << std::endl; // 5

    ++c; // This calls the operator++
    std::cout << "After ++c: " << c.get_count() << std::endl; // 6

    // This line demonstrates the semantic error:
    // If operator++ returned a reference, c.count would become 10.
    // Since it returns by value, a temporary copy is modified, not 'c'.
    (++c).set_count(10); 
    std::cout << "After (++c).set_count(10): " << c.get_count() << std::endl; // EXPECTED: 10, ACTUAL: 7 (Semantic Error)

    Counter old_c = c--;
    std::cout << "After c-- (returned value): " << old_c.get_count() << std::endl; // 7
    std::cout << "After c-- (new value of c): " << c.get_count() << std::endl;     // 6

    return 0;
}