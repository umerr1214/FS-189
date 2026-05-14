#include <iostream>

class Counter {
private:
    static int count;

public:
    Counter() {
        count++;
        std::cout << "Counter object created. Current count: " << count << std::endl;
    }

    ~Counter() {
        // LOGICAL ERROR: The destructor fails to decrement the static count.
        // count--; // This line is missing, leading to an incorrect total count of alive objects.
        std::cout << "Counter object destroyed. Current count: " << count << std::endl; // Prints current count before actual destruction
    }

    static int getCount() {
        return count;
    }
};

int Counter::count = 0;

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl; // Expected: 0, Actual: 0

    Counter c1; // Expected: 1, Actual: 1
    std::cout << "After c1 creation: " << Counter::getCount() << std::endl;

    {
        Counter c2; // Expected: 2, Actual: 2
        Counter c3; // Expected: 3, Actual: 3
        std::cout << "Inside block, count: " << Counter::getCount() << std::endl;
    } // c2, c3 are destroyed, but count remains 3 due to logical error. Expected: 1, Actual: 3
    std::cout << "After block, count: " << Counter::getCount() << std::endl;

    Counter* c4 = new Counter(); // Expected: 2, Actual: 4
    std::cout << "After c4 (new) creation: " << Counter::getCount() << std::endl;

    delete c4; // c4 is destroyed, but count remains 4. Expected: 1, Actual: 4
    std::cout << "After c4 (new) destruction: " << Counter::getCount() << std::endl;

    return 0;
}