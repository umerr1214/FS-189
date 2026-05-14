#include <iostream>
#include <vector>

// Global variable to keep track of the count, violating encapsulation
int global_counter_count = 0;

// Global functions to manage the count, instead of static class members
void increment_global_counter() {
    global_counter_count++;
}

void decrement_global_counter() {
    global_counter_count--;
}

int get_global_counter_count() {
    return global_counter_count;
}

// The Counter class itself, but it delegates to global functions/variables,
// failing to use a static member variable directly.
class Counter {
public:
    Counter() {
        increment_global_counter(); // Calls global function
    }

    ~Counter() {
        decrement_global_counter(); // Calls global function
    }

    static int getCount() {
        return get_global_counter_count(); // Calls global function
    }
};

int main() {
    std::cout << Counter::getCount() << std::endl; // Expected: 0

    Counter c1;
    std::cout << Counter::getCount() << std::endl; // Expected: 1

    {
        Counter c2;
        Counter c3;
        std::cout << Counter::getCount() << std::endl; // Expected: 3
    } // c2, c3 destructed here
    std::cout << Counter::getCount() << std::endl; // Expected: 1

    Counter* p_c4 = new Counter();
    std::cout << Counter::getCount() << std::endl; // Expected: 2

    std::vector<Counter> vec_counters;
    vec_counters.emplace_back(); // c5
    vec_counters.emplace_back(); // c6
    std::cout << Counter::getCount() << std::endl; // Expected: 4

    delete p_c4; // Destruct p_c4
    std::cout << Counter::getCount() << std::endl; // Expected: 3

    vec_counters.clear(); // Destruct c5, c6
    std::cout << Counter::getCount() << std::endl; // Expected: 1

    // c1 will be destructed when main exits
    return 0;
}