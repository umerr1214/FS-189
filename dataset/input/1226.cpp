#include <iostream>
#include <vector>

class Counter {
public:
    // Default constructor increments the alive count
    Counter() {
        m_total_alive_objects++;
    }

    // Destructor decrements the alive count
    ~Counter() {
        m_total_alive_objects--;
    }

    // Readability/Efficiency Issue:
    // This getter should be a static member function as it accesses a static member.
    // Making it non-static means an object instance is required to call it,
    // which is less intuitive and can lead to unnecessary object creation just to get the count.
    int get_current_alive_count() const {
        return m_total_alive_objects;
    }

private:
    // Static member variable to keep track of alive objects
    static int m_total_alive_objects;
};

// Initialize the static member variable outside the class definition
int Counter::m_total_alive_objects = 0;

void run_test_case() {
    std::cout << "--- Readability / Efficiency Issue Test ---" << std::endl;

    // To get the initial count, we need to create a temporary object or have an existing one.
    // This is an efficiency and readability issue.
    std::cout << "Initial alive count (using temp object): " << Counter().get_current_alive_count() << "\n"; // Creates and destroys a temp object

    Counter obj_a;
    std::cout << "After creating obj_a: " << obj_a.get_current_alive_count() << "\n"; // Requires obj_a instance

    {
        Counter obj_b;
        Counter obj_c;
        std::cout << "Alive count in inner scope: " << obj_b.get_current_alive_count() << "\n"; // Requires obj_b instance
        // Calling obj_c.get_current_alive_count() would yield the same result, but it's redundant.
    } // obj_b, obj_c go out of scope. Destructors called.

    std::cout << "Alive count after inner scope: " << obj_a.get_current_alive_count() << "\n"; // Requires obj_a instance

    // Another example of needing a temporary object to query the static state
    std::cout << "Final count before obj_a destroyed (using temp object): " << Counter().get_current_alive_count() << "\n"; // Creates and destroys a temp object
}

int main() {
    run_test_case();
    // After main function, obj_a is destroyed.
    // To confirm the final count is 0, we again need a temporary object.
    std::cout << "Final count after all objects destroyed (using temp object): " << Counter().get_current_alive_count() << "\n";
    return 0;
}