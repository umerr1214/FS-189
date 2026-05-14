#include <iostream>

class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}
    int getValue() const { return value; }

    Counter& operator++() { // Correct pre-increment
        value++;
        return *this;
    }

    // Logical Error: Post-increment behaves like pre-increment
    Counter operator++(int) {
        // Correct implementation would be:
        // Counter temp = *this;
        // value++;
        // return temp;
        value++; // Increments the object
        return *this; // Returns the *incremented* object, not the original value
    }
};

int main() {
    Counter c(5);
    std::cout << "Initial value: " << c.getValue() << std::endl; // Expected: 5

    ++c;
    std::cout << "After pre-increment: " << c.getValue() << std::endl; // Expected: 6

    Counter d = c++; // c is 6. With error: c becomes 7, d gets 7. (Should be: c becomes 7, d gets 6)
    std::cout << "After post-increment (original object): " << c.getValue() << std::endl; // Expected: 7
    std::cout << "Value returned by post-increment: " << d.getValue() << std::endl; // Expected: 6, but will be 7

    Counter x(10);
    std::cout << "--- New Counter x ---" << std::endl;
    std::cout << "Initial x value: " << x.getValue() << std::endl; // Expected: 10
    Counter y = x++; // x is 10. With error: x becomes 11, y gets 11. (Should be: x becomes 11, y gets 10)
    std::cout << "x after x++: " << x.getValue() << std::endl; // Expected: 11
    std::cout << "y (from x++): " << y.getValue() << std::endl; // Expected: 10, but will be 11
    ++x; // x becomes 12
    std::cout << "x after ++x: " << x.getValue() << std::endl; // Expected: 12
    return 0;
}