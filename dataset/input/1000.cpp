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

    // Postfix increment: obj++
    Counter operator++(int) {
        Counter temp = *this; // Save current state
        ++count;             // Increment actual object
        return temp;         // Return saved state
    }

    // For printing
    friend std::ostream& operator<<(std::ostream& os, const Counter& c) {
        os << c.count;
        return os;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    std::cout << "--- Testing Counter class ---" << std::endl;

    Counter c1(0);
    std::cout << "Initial c1: " << c1.getCount() << std::endl;

    // Test Prefix Increment
    Counter& c1_ref = ++c1;
    std::cout << "After ++c1: c1 = " << c1.getCount() << ", c1_ref = " << c1_ref.getCount() << std::endl; // Should be 1, 1

    // Test Postfix Increment
    Counter c2(5);
    std::cout << "Initial c2: " << c2.getCount() << std::endl;
    Counter c2_old_value = c2++;
    std::cout << "After c2++: c2 = " << c2.getCount() << ", c2_old_value = " << c2_old_value.getCount() << std::endl; // Should be 6, 5

    // Test Chaining Prefix Increment
    Counter c3(10);
    std::cout << "Initial c3: " << c3.getCount() << std::endl;
    Counter& c3_ref2 = ++(++c3); // c3 should become 12
    std::cout << "After ++(++c3): c3 = " << c3.getCount() << ", c3_ref2 = " << c3_ref2.getCount() << std::endl; // Should be 12, 12

    // Test Chaining Postfix Increment (less common, but possible)
    Counter c4(15);
    std::cout << "Initial c4: " << c4.getCount() << std::endl;
    // Counter c4_intermediate = c4++; // c4=16, c4_intermediate=15
    // Counter c4_final_value = c4_intermediate++; // c4_intermediate is a temporary, increments its copy, not c4
    // This isn't a good test for postfix chaining effect on original object.
    // Let's just do a simple check.
    Counter c4_val = c4++;
    std::cout << "After c4++: c4 = " << c4.getCount() << ", c4_val = " << c4_val.getCount() << std::endl; // Should be 16, 15

    return 0;
}