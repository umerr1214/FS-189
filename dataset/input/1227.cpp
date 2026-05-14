#include <iostream>
#include <string>
#include <vector>

class Counter {
public:
    // Default constructor: Increments the count for a newly created object.
    Counter() {
        _alive_objects++;
    }

    // Copy constructor: Increments the count for a new object created by copying an existing one.
    Counter(const Counter& other) {
        _alive_objects++;
    }

    // Copy assignment operator: An existing object is assigned the value of another.
    // This operation does not create a new object or destroy an existing one
    // (unless self-assignment is not handled, which is not an issue for count).
    // Therefore, the count should not change.
    Counter& operator=(const Counter& other) {
        if (this != &other) {
            // No per-object resources to manage or data to copy that affects the global count.
            // _alive_objects remains unchanged.
        }
        return *this;
    }

    // Destructor: Decrements the count when an object is destroyed.
    ~Counter() {
        _alive_objects--;
    }

    // Static member function: Provides a clean and direct way to access the static count
    // without needing an object instance.
    static int getAliveCount() {
        return _alive_objects;
    }

private:
    // Static member variable: Stores the total number of currently alive Counter objects.
    static int _alive_objects;
};

// Initialize the static member variable outside the class definition.
int Counter::_alive_objects = 0;

// Helper function to print the current count with a message.
void print_count(const std::string& message) {
    std::cout << message << ": " << Counter::getAliveCount() << std::endl;
}

void run_test_case() {
    std::cout << "--- Correct Version Test ---" << std::endl;
    print_count("Initial count"); // Expected: 0

    Counter c1; // Default constructor
    print_count("After creating c1"); // Expected: 1

    { // Inner scope to test object lifecycle
        Counter c2 = c1; // Copy constructor
        print_count("After creating c2 (copy of c1)"); // Expected: 2

        Counter c3; // Default constructor
        print_count("After creating c3"); // Expected: 3

        c3 = c1; // Copy assignment. Count should remain 3.
        print_count("After c3 = c1 (assignment)"); // Expected: 3

        // Test with a vector of Counters
        std::vector<Counter> counters_vec(2); // Two default constructions
        print_count("After creating a vector of 2 Counters"); // Expected: 5

        // counters_vec, c3, c2 go out of scope here.
    } // Destructors called for objects in reverse order of creation within scope:
      // ~counters_vec[1], ~counters_vec[0], ~c3, ~c2.
      // 5 -> 4 -> 3 -> 2 -> 1
    print_count("After inner scope exit"); // Expected: 1

    Counter c4; // Default constructor
    print_count("After creating c4"); // Expected: 2

    // c1, c4 go out of scope at the end of run_test_case().
} // Destructors called: ~c4, ~c1.
  // 2 -> 1 -> 0

int main() {
    run_test_case();
    print_count("Final count after all objects destroyed"); // Expected: 0
    return 0;
}