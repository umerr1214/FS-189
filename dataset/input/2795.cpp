#include <iostream>

class Counter {
private:
    int count;

public:
    Counter(int initial_count = 0) : count(initial_count) {}

    int get_count() const {
        return count;
    }

    void set_count(int val) {
        count = val;
    }

    // Prefix increment: ++prefix
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Postfix decrement: postfix--
    // LOGICAL ERROR: Returns the *decremented* value as the temporary,
    // instead of the value *before* decrementing, as required.
    Counter operator--(int) { // The 'int' parameter is a dummy for postfix
        --count;              // Decrement FIRST
        Counter temp = *this; // THEN save current (already decremented) state
        return temp;          // Return saved (already decremented) state
    }
};

int main() {
    // This main function is just for compilation and basic demonstration.
    // The actual testing logic is in the JSON driver.
    Counter c(5);
    std::cout << "Initial count: " << c.get_count() << std::endl; // 5

    ++c;
    std::cout << "After ++c: " << c.get_count() << std::endl; // 6

    Counter old_c = c--;
    std::cout << "After c-- (returned value): " << old_c.get_count() << std::endl; // EXPECTED: 6, ACTUAL: 5 (Logical Error)
    std::cout << "After c-- (new value of c): " << c.get_count() << std::endl;     // 5

    return 0;
}