#include <iostream>
#include <vector>
#include <atomic> // Unnecessary for single-threaded context, less efficient than plain int

class Counter {
private:
    // Readability/Efficiency Issue: Using std::atomic<int> for a single-threaded counter
    // introduces unnecessary overhead and is less efficient than a simple int.
    static std::atomic<int> g_total_instances;

public:
    // Readability/Efficiency Issue: Verbose and less idiomatic increment/decrement syntax.
    Counter() { g_total_instances.operator++(); /*std::cout << "A new counter has been instantiated. Current count: " << g_total_instances.load() << std::endl;*/ }
    ~Counter() { g_total_instances.operator--(); /*std::cout << "An existing counter has been de-instantiated. Current count: " << g_total_instances.load() << std::endl;*/ }

    // Readability/Efficiency Issue: Overly long and verbose method name.
    static int get_total_num_active_counters() { return g_total_instances.load(); }
};

// Definition and initialization of the static member
std::atomic<int> Counter::g_total_instances(0); // Using explicit constructor for atomic

int main() {
    // Readability Issue: Inconsistent spacing and formatting.
    std::cout << "Beginning of program execution." << std::endl;
    std::cout << "Active counter count at start: " << Counter::get_total_num_active_counters() << std::endl; // Expected: 0

    Counter first_counter_obj;
    {
        Counter second_counter_obj;
        std::vector<Counter> some_vector_of_counters(2); // Creates 2 more objects
        std::cout << "Count with 4 objects: " << Counter::get_total_num_active_counters() << std::endl; // Expected: 4
    } // second_counter_obj and some_vector_of_counters are destroyed here
    std::cout << "Count after scope exit (1 object): " << Counter::get_total_num_active_counters() << std::endl; // Expected: 1

    Counter* dynamically_allocated_counter = new Counter();
    std::cout << "Count with dynamically allocated object (2 objects): " << Counter::get_total_num_active_counters() << std::endl; // Expected: 2

    delete dynamically_allocated_counter;
    std::cout << "Count after deleting dynamically allocated object (1 object): " << Counter::get_total_num_active_counters() << std::endl; // Expected: 1

    std::cout << "End of program execution." << std::endl;
    return 0;
}