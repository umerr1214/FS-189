#include <iostream>

class Counter {
    int count;
public:
    Counter(int c = 0) : count(c) {}

    int getCount() const {
        return count;
    }

    // Prefix increment operator
    // Increments the count and returns a reference to the modified object.
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Postfix increment operator
    // ROBUSTNESS ISSUE: This implementation incorrectly returns *this (the incremented object)
    // instead of a copy of the object's state *before* the increment.
    // This violates the expected semantics of the postfix operator.
    Counter operator++(int) {
        count++; // Increment the internal count
        return *this; // Incorrect: Should return the object's state *before* incrementing
    }
};

int main() {
    // Test Case 1: Prefix increment basic
    Counter c1(10);
    std::cout << "Test 1: Prefix basic\n";
    std::cout << "Before ++c1: " << c1.getCount() << "\n";
    Counter& ref_c1 = ++c1; // Store reference to check identity
    std::cout << "After ++c1: " << c1.getCount() << "\n";
    std::cout << "Ref value: " << ref_c1.getCount() << "\n";
    std::cout << "c1 == ref_c1: " << (&c1 == &ref_c1 ? "true" : "false") << "\n";

    std::cout << "---\n";

    // Test Case 2: Postfix increment basic
    Counter c2(20);
    std::cout << "Test 2: Postfix basic\n";
    std::cout << "Before c2++: " << c2.getCount() << "\n";
    Counter old_c2_val = c2++; // old_c2_val should be 20, c2 should be 21
    std::cout << "After c2++ (c2): " << c2.getCount() << "\n";
    std::cout << "Value returned by c2++: " << old_c2_val.getCount() << "\n";

    std::cout << "---\n";

    // Test Case 3: Chained prefix increment
    Counter c3(30);
    std::cout << "Test 3: Chained prefix\n";
    std::cout << "Before ++(++c3): " << c3.getCount() << "\n";
    Counter& ref_c3 = ++(++c3); // Should be 32, ref_c3 should be c3
    std::cout << "After ++(++c3): " << c3.getCount() << "\n";
    std::cout << "Ref value: " << ref_c3.getCount() << "\n";
    std::cout << "c3 == ref_c3: " << (&c3 == &ref_c3 ? "true" : "false") << "\n";

    std::cout << "---\n";

    // Test Case 4: Assignment with postfix increment
    Counter c4(40);
    std::cout << "Test 4: Assignment with postfix\n";
    std::cout << "Before val = c4++: " << c4.getCount() << "\n";
    int val4 = (c4++).getCount();
    std::cout << "After val = c4++ (c4): " << c4.getCount() << "\n";
    std::cout << "val4 (returned value): " << val4 << "\n";

    std::cout << "---\n";

    // Test Case 5: Assignment with prefix increment
    Counter c5(50);
    std::cout << "Test 5: Assignment with prefix\n";
    std::cout << "Before val = ++c5: " << c5.getCount() << "\n";
    int val5 = (++c5).getCount();
    std::cout << "After val = ++c5 (c5): " << c5.getCount() << "\n";
    std::cout << "val5 (returned value): " << val5 << "\n";

    return 0;
}