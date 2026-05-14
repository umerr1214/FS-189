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
    // Returns a temporary object before decrementing
    Counter operator--(int) { // The 'int' parameter is a dummy for postfix
        Counter temp = *this; // Save current state
        --count;              // Decrement
        return temp;          // Return saved state
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    // This main function is just to make the file a complete C++ program
    // It will not compile due to the syntax error.
    // The actual testing logic is in the JSON driver.
    Counter c(0);
    ++c;
    c--;
    std::cout << "Count: " << c.get_count() << std::endl;
    return 0;
}