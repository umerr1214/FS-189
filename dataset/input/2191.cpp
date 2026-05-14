#include <iostream>

class Counter {
public:
    Counter() {
        count++;
    }

    ~Counter() {
        count--;
    }

    static int getTotalCount() {
        return count;
    }

private:
    static int count;
};

// Initialize static member
int Counter::count = 0;

int main() {
    std::cout << "Initial total count: " << Counter::getTotalCount() << std::endl; // 0

    Counter c1;
    std::cout << "After creating c1. Total count: " << Counter::getTotalCount() << std::endl; // 1

    // This uses the default copy constructor.
    // The default copy constructor performs a shallow copy of member variables.
    // Since 'count' is static, it's not a member variable of individual objects.
    // Therefore, the Counter constructor is NOT called for 'c2'.
    // 'count' remains 1. This is a robustness issue as c2 is a new object instance.
    Counter c2 = c1;
    std::cout << "After creating c2 (copy of c1). Total count: " << Counter::getTotalCount() << std::endl; // 1 (Incorrect, should be 2 if c2 was a distinct object)

    {
        Counter c3;
        std::cout << "Inside block, after creating c3. Total count: " << Counter::getTotalCount() << std::endl; // 2
    } // c3 is destroyed here, count becomes 1
    std::cout << "After c3 destroyed. Total count: " << Counter::getTotalCount() << std::endl; // 1

    // At this point: c1 and c2 exist. count is 1.
    // When main exits, c3 is already destroyed.
    // c2's destructor is called: count becomes 0. (Incorrect, c1 still exists)
    // c1's destructor is called: count becomes -1. (Incorrect, count should not go negative)
    // This is the robustness issue: count goes negative while objects logically exist or after their destruction.
    // The problem is that c2 was created without incrementing the counter, but its destruction decrements it.
    std::cout << "Before main returns. Total count: " << Counter::getTotalCount() << std::endl;

    std::cout << "Program ending." << std::endl;

    return 0;
}