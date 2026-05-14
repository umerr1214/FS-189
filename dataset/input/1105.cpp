#include <iostream>
#include <vector>
#include <memory>

class Counter {
public:
    // Robustness Issue: The static counter variable is public,
    // allowing external code to directly modify its value.
    static int s_count;

    Counter() {
        s_count++;
        // std::cout << "Counter created. Active count: " << s_count << std::endl;
    }

    ~Counter() {
        s_count--;
        // std::cout << "Counter destroyed. Active count: " << s_count << std::endl;
    }

    static int getTotalCount() {
        return s_count;
    }
};

// Definition and initialization of the static member
int Counter::s_count = 0;

int main() {
    std::cout << "--- Initial state ---" << std::endl;
    std::cout << "Current active counters: " << Counter::getTotalCount() << std::endl; // Expected: 0

    std::cout << "\n--- Creating first batch of counters ---" << std::endl;
    Counter c1;
    {
        Counter c2;
        std::cout << "Inside scope (c1, c2 active). Current active counters: " << Counter::getTotalCount() << std::endl; // Expected: 2
    } // c2 is destroyed here
    std::cout << "After scope (c1 active). Current active counters: " << Counter::getTotalCount() << std::endl; // Expected: 1

    std::vector<Counter> counters_vec(3); // Creates 3 more objects
    std::cout << "After vector creation (c1, 3 in vec active). Current active counters: " << Counter::getTotalCount() << std::endl; // Expected: 1 + 3 = 4

    std::cout << "\n--- Introducing a robustness issue: directly modifying s_count ---" << std::endl;
    // This direct modification bypasses the class's constructor/destructor logic,
    // corrupting the integrity of the counter.
    Counter::s_count = -5; // Malicious or accidental modification
    std::cout << "Counter::s_count manually set to -5. Current active counters: " << Counter::getTotalCount() << std::endl; // Expected: -5

    std::cout << "\n--- Creating more counters after corruption ---" << std::endl;
    Counter c3;
    Counter* c4 = new Counter();
    std::cout << "After creating c3, c4 (c1, 3 in vec, c3, c4 active, but s_count corrupted). Current active counters: " << Counter::getTotalCount() << std::endl; // Expected: -5 + 1 + 1 = -3

    delete c4; // Destroys c4
    std::cout << "After deleting c4. Current active counters: " << Counter::getTotalCount() << std::endl; // Expected: -3 - 1 = -4

    // counters_vec and c1 will be destroyed when main exits
    std::cout << "\n--- End of main function ---" << std::endl;
    // Expected final count will still be incorrect due to the manual modification
    return 0;
}