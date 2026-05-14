#include <iostream>

class Counter {
private:
    int count;

public:
    Counter(int initialCount = 0) : count(initialCount) {}

    // Prefix increment operator (correct)
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Postfix increment operator (LOGICAL ERROR: returns the incremented object, not the original value)
    Counter operator++(int) {
        // Correct implementation would save 'this' to a temp variable before incrementing
        // Counter temp = *this;
        ++count;             // Increment actual object
        return *this;        // LOGICAL ERROR: Returns the incremented object, should return the 'temp' (original) object
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter c1(5);
    std::cout << "c1 initial: " << c1.getCount() << std::endl; // Expected: 5

    ++c1;
    std::cout << "c1 after prefix ++: " << c1.getCount() << std::endl; // Expected: 6

    Counter c2 = c1++; // c1 becomes 7. c2 should capture c1's value *before* increment (6), but due to error, it captures 7.
    std::cout << "c1 after postfix ++ (assigned to c2): " << c1.getCount() << std::endl; // Expected: 7
    std::cout << "c2 (value before increment): " << c2.getCount() << std::endl; // Expected: 6 (correct), but will be 7 (buggy)

    Counter c3(10);
    std::cout << "c3 initial: " << c3.getCount() << std::endl; // Expected: 10
    Counter c4 = ++c3; // c3 becomes 11, c4 gets 11
    std::cout << "c3 after prefix ++ (assigned to c4): " << c3.getCount() << std::endl; // Expected: 11
    std::cout << "c4 (value after increment): " << c4.getCount() << std::endl; // Expected: 11

    return 0;
}