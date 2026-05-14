#include <iostream>
#include <vector>
#include <string>

class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}
    int getCount() const { return count; }

    // Overload prefix ++ operator - Readability/Efficiency Issue: verbose increment
    Counter& operator++() {
        int temp_count = count + 1; // Unnecessary temporary variable
        count = temp_count;         // Extra assignment
        return *this;
    }
};

int main() {
    std::cout << "Running tests for Counter prefix increment operator (Readability/Efficiency Issue):" << std::endl;

    // Test 1: Basic increment
    Counter c1(5);
    ++c1;
    std::cout << "Test 1: Initial count: 5, after ++: " << c1.getCount() << std::endl;

    // Test 2: Chained increment
    Counter c2(0);
    ++(++c2); // This works correctly
    std::cout << "Test 2: Initial count: 0, after ++(++): " << c2.getCount() << std::endl;

    // Test 3: Negative increment
    Counter c3(-3);
    ++c3;
    std::cout << "Test 3: Initial count: -3, after ++: " << c3.getCount() << std::endl;

    // Test 4: Another basic increment
    Counter c4(100);
    ++c4;
    std::cout << "Test 4: Initial count: 100, after ++: " << c4.getCount() << std::endl;

    return 0;
}