#include <iostream>

class Counter {
public:
    Counter() {
        s_count++;
    }

    ~Counter() {
        s_count--;
    }

    // No explicit copy constructor or assignment operator is defined.
    // The implicitly-declared copy constructor will perform a member-wise copy,
    // which does NOT call the Counter() constructor and thus does NOT increment s_count.
    // However, the destructor ~Counter() WILL be called for the copied object,
    // incorrectly decrementing s_count. This leads to an inaccurate and potentially negative count.

    static int getCount() {
        return s_count;
    }

private:
    static int s_count;
};

// Initialize static member
int Counter::s_count = 0;

void create_and_copy_in_scope() {
    Counter c3;
    // Default copy constructor is used: c4 is created, but s_count is NOT incremented.
    Counter c4 = c3; 
    std::cout << "Inside create_and_copy_in_scope: After c3, c4 created. Count: " << Counter::getCount() << std::endl;
} // c4 and c3 are destroyed here. Both call ~Counter(), decrementing s_count twice.

int main() {
    std::cout << "Initial count: " << Counter::getCount() << std::endl;

    Counter c1;
    std::cout << "After c1 created. Count: " << Counter::getCount() << std::endl;

    // Default copy constructor is used: c2 is created, but s_count is NOT incremented.
    Counter c2 = c1; 
    std::cout << "After c2 (copy of c1) created. Count: " << Counter::getCount() << std::endl;

    create_and_copy_in_scope(); // This function will create and destroy objects, demonstrating the issue.

    std::cout << "After create_and_copy_in_scope returned. Count: " << Counter::getCount() << std::endl;

    Counter c5;
    std::cout << "After c5 created. Count: " << Counter::getCount() << std::endl;

    // c5, c2, c1 are destroyed when main exits.
    // c2's destruction will decrement s_count, causing a further undercount.
    // c1's destruction will decrement s_count.
    std::cout << "End of test. Final count before main exit: " << Counter::getCount() << std::endl;

    return 0;
}