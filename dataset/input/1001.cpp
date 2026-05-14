#include <iostream>

class Counter {
private:
    int count;

public:
    Counter(int initial_count = 0) : count(initial_count) {}

    int getCount() const {
        return count;
    }

    // Prefix increment: ++obj
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Postfix increment: obj++ - LOGICAL ERROR
    // Should return the object's state *before* incrementing.
    // This implementation returns the object's state *after* incrementing.
    Counter operator++(int) {
        ++count;             // Increment actual object
        return *this;        // LOGICAL ERROR: Should return a copy of the object *before* incrementing
    }

    // For printing
    friend std::ostream& operator<<(std::ostream& os, const Counter& c) {
        os << c.count;
        return os;
    }
};

int main() {
    std::cout << "--- Testing Counter class ---" << std::endl;

    Counter c1(0);
    std::cout << "Initial c1: " << c1.getCount() << std::endl;

    // Test Prefix Increment (should work correctly)
    Counter& c1_ref = ++c1;
    std::cout << "After ++c1: c1 = " << c1.getCount() << ", c1_ref = " << c1_ref.getCount() << std::endl; // Expected: 1, 1

    // Test Postfix Increment (will show logical error)
    Counter c2(5);
    std::cout << "Initial c2: " << c2.getCount() << std::endl;
    Counter c2_old_value = c2++;
    std::cout << "After c2++: c2 = " << c2.getCount() << ", c2_old_value = " << c2_old_value.getCount() << std::endl; // Expected: 6, 5 (Actual: 6, 6)

    // Test Chaining Prefix Increment (should work correctly)
    Counter c3(10);
    std::cout << "Initial c3: " << c3.getCount() << std::endl;
    Counter& c3_ref2 = ++(++c3);
    std::cout << "After ++(++c3): c3 = " << c3.getCount() << ", c3_ref2 = " << c3_ref2.getCount() << std::endl; // Expected: 12, 12

    // Test Postfix Increment again for clarity
    Counter c4(15);
    std::cout << "Initial c4: " << c4.getCount() << std::endl;
    Counter c4_val = c4++;
    std::cout << "After c4++: c4 = " << c4.getCount() << ", c4_val = " << c4_val.getCount() << std::endl; // Expected: 16, 15 (Actual: 16, 16)

    return 0;
}