#include <iostream>

class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}
    int getValue() const { return value; }

    Counter& operator++() {
        value++;
        return *this;
    }

    Counter operator++(int) {
        Counter temp = *this;
        value++;
        return temp;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Counter c(5);
    std::cout << "Initial value: " << c.getValue() << std::endl;

    ++c;
    std::cout << "After pre-increment: " << c.getValue() << std::endl;

    Counter d = c++;
    std::cout << "After post-increment (original object): " << c.getValue() << std::endl;
    std::cout << "Value returned by post-increment: " << d.getValue() << std::endl;

    Counter x(10);
    std::cout << "--- New Counter x ---" << std::endl;
    std::cout << "Initial x value: " << x.getValue() << std::endl;
    Counter y = x++;
    std::cout << "x after x++: " << x.getValue() << std::endl;
    std::cout << "y (from x++): " << y.getValue() << std::endl;
    ++x;
    std::cout << "x after ++x: " << x.getValue() << std::endl;
    return 0;
}