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

    // Semantic Error: Post-increment attempts to return a reference to a local temporary object.
    Counter& operator++(int) { // Return type changed from Counter to Counter&
        Counter temp = *this; // 'temp' is a local variable
        value++;
        return temp; // Semantic error: Returning a reference to a local variable 'temp'
                     // This results in a dangling reference and undefined behavior.
    }
};

int main() {
    Counter c(5);
    std::cout << "Initial value: " << c.getValue() << std::endl; // Expected: 5

    ++c;
    std::cout << "After pre-increment: " << c.getValue() << std::endl; // Expected: 6

    // If this compiles, 'd' will be a dangling reference, potentially causing a crash or garbage output.
    Counter& d = c++; // c is 6. With error: d refers to a destroyed temporary object.
    std::cout << "After post-increment (original object): " << c.getValue() << std::endl; // Expected: 7
    std::cout << "Value returned by post-increment: " << d.getValue() << std::endl; // Undefined behavior

    Counter x(10);
    std::cout << "--- New Counter x ---" << std::endl;
    std::cout << "Initial x value: " << x.getValue() << std::endl; // Expected: 10
    Counter& y = x++; // x is 10. With error: y refers to a destroyed temporary object.
    std::cout << "x after x++: " << x.getValue() << std::endl; // Expected: 11
    std::cout << "y (from x++): " << y.getValue() << std::endl; // Undefined behavior
    ++x; // x becomes 12
    std::cout << "x after ++x: " << x.getValue() << std::endl; // Expected: 12
    return 0;
}