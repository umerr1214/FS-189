#include <iostream>

class Counter {
public:
    Counter() {
        count++;
    }

    Counter(const Counter& other) {
        count++;
    }

    ~Counter() {
        count--;
    }

    static int getCount() {
        return count;
    }

private:
    static int count;
} // SYNTAX ERROR: Missing semicolon after class definition

int Counter::count = 0;

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl;

    Counter c1;
    std::cout << "After c1 creation: " << Counter::getCount() << std::endl;

    {
        Counter c2;
        std::cout << "After c2 creation: " << Counter::getCount() << std::endl;
        Counter c3 = c1;
        std::cout << "After c3 (copy of c1) creation: " << Counter::getCount() << std::endl;
    }
    std::cout << "After c2 and c3 destroyed: " << Counter::getCount() << std::endl;

    Counter* p = new Counter();
    std::cout << "After p created with new: " << Counter::getCount() << std::endl;
    delete p;
    std::cout << "After p deleted: " << Counter::getCount() << std::endl;

    return 0;
}