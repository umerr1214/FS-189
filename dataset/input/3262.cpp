#include <iostream>

class Counter {
private:
    int count;

public:
    Counter(int initialCount = 0) : count(initialCount) {}

    // Prefix increment operator
    Counter& operator++() {
        ++count;
        return *this;
    }

    // Postfix increment operator
    Counter operator++(int) {
        Counter temp = *this; // Save current state
        ++count;             // Increment actual object
        return temp;         // Return saved state
    }

    int getCount() const {
        return count;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Counter c1(5);
    std::cout << "c1 initial: " << c1.getCount() << std::endl;

    ++c1;
    std::cout << "c1 after prefix ++: " << c1.getCount() << std::endl;

    Counter c2 = c1++;
    std::cout << "c1 after postfix ++ (assigned to c2): " << c1.getCount() << std::endl;
    std::cout << "c2 (value before increment): " << c2.getCount() << std::endl;

    Counter c3(10);
    std::cout << "c3 initial: " << c3.getCount() << std::endl;
    Counter c4 = ++c3;
    std::cout << "c3 after prefix ++ (assigned to c4): " << c3.getCount() << std::endl;
    std::cout << "c4 (value after increment): " << c4.getCount() << std::endl;

    return 0;
}