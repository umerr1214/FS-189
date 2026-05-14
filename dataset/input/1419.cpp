#include <iostream>

class Counter {
private:
    int value;
public:
    // Constructor initializes the counter's value.
    // Uses member initializer list for efficiency and good practice.
    Counter(int v = 0) : value(v) {}

    // Getter method to access the private value.
    // Marked `const` as it does not modify the object's state.
    int getValue() const {
        return value;
    }

    // Pre-increment operator (prefix): `++counter`
    // Increments the internal `value` and returns a reference to the
    // *incremented* object itself. This allows for chaining and is efficient.
    Counter& operator++() {
        ++value; // Increment the private member
        return *this; // Return a reference to the current (incremented) object
    }

    // Post-increment operator (postfix): `counter++`
    // The `int` parameter is a dummy to distinguish it from the pre-increment operator.
    // It returns a copy of the object's state *before* incrementing,
    // then increments the object itself. This requires a temporary copy.
    Counter operator++(int) {
        Counter temp = *this; // Save the current state before modification
        ++value;              // Increment the original object's value
        return temp;          // Return the saved (old) state
    }
};

int main() {
    std::cout << "--- Testing Correct Version ---" << std::endl;

    // Test pre-increment
    Counter c1(5);
    std::cout << "c1 initial: " << c1.getValue() << std::endl; // Expected: 5

    Counter& c1_ref = ++c1; // c1 becomes 6, c1_ref refers to c1
    std::cout << "Value of (++c1): " << c1_ref.getValue() << std::endl; // Prints 6
    std::cout << "c1 after pre-inc: " << c1.getValue() << std::endl; // Expected: 6
    c1_ref.operator++(); // Increment via reference, c1 becomes 7
    std::cout << "c1 after c1_ref increment: " << c1.getValue() << std::endl; // Expected: 7

    std::cout << std::endl;

    // Test post-increment
    Counter c2(10);
    std::cout << "c2 initial: " << c2.getValue() << std::endl; // Expected: 10

    Counter c2_old_val = c2++; // c2 becomes 11, c2_old_val gets 10
    std::cout << "Value of (c2++): " << c2_old_val.getValue() << std::endl; // Prints 10
    std::cout << "c2 after post-inc: " << c2.getValue() << std::endl; // Expected: 11

    std::cout << std::endl;

    // Chaining pre-increment
    Counter c3(1);
    std::cout << "c3 initial: " << c3.getValue() << std::endl; // Expected: 1
    ++(++c3); // c3 becomes 3
    std::cout << "c3 after chained pre-inc: " << c3.getValue() << std::endl; // Expected: 3

    std::cout << std::endl;

    // Using operators directly in output streams
    Counter c4(20);
    std::cout << "c4 initial: " << c4.getValue() << std::endl; // Expected: 20
    std::cout << "Value of (++c4): " << (++c4).getValue() << std::endl; // c4 becomes 21, prints 21
    std::cout << "c4 after ++c4: " << c4.getValue() << std::endl; // Expected: 21

    std::cout << "Value of (c4++): " << (c4++).getValue() << std::endl; // c4 becomes 22, prints 21 (old value)
    std::cout << "c4 after c4++: " << c4.getValue() << std::endl; // Expected: 22

    return 0;
}