#include <iostream> // For input/output operations

// Define the Counter class as specified
class Counter {
public:
    // Constructor: Increments the static count
    Counter() {
        s_count++;
    }

    // Destructor: Decrements the static count
    ~Counter() {
        s_count--;
    }

    // Static method: Returns the current value of the static count
    static int getTotalCount() {
        return s_count;
    }

private:
    // Static integer member initialized to 0
    static int s_count; // Using 's_' prefix for static members for clarity and good practice
};

// Initialize the static member outside the class definition
int Counter::s_count = 0;

// Function to demonstrate object creation and destruction within a scope
void demonstrateScope() {
    std::cout << "\n--- Entering demonstrateScope() ---" << std::endl;
    std::cout << "Current count before objects in scope: " << Counter::getTotalCount() << std::endl;

    Counter temp1;
    std::cout << "Current count after temp1 created: " << Counter::getTotalCount() << std::endl;

    { // Inner block to show nested scope
        Counter temp2;
        std::cout << "Current count after temp2 created in inner block: " << Counter::getTotalCount() << std::endl;
    } // temp2 is destroyed here
    std::cout << "Current count after temp2 destroyed: " << Counter::getTotalCount() << std::endl;

    std::cout << "--- Exiting demonstrateScope() ---" << std::endl;
} // temp1 is destroyed here

int main() {
    std::cout << "--- Counter Demonstration (Correct Version) ---" << std::endl;

    // Initial state
    std::cout << "Initial total count: " << Counter::getTotalCount() << std::endl; // Expected: 0

    // Create a Counter object
    Counter c1;
    std::cout << "After creating c1. Total count: " << Counter::getTotalCount() << std::endl; // Expected: 1

    // Create another Counter object
    Counter c2;
    std::cout << "After creating c2. Total count: " << Counter::getTotalCount() << std::endl; // Expected: 2

    // Demonstrate object lifecycle within a local scope
    demonstrateScope();
    std::cout << "After demonstrateScope() call. Total count: " << Counter::getTotalCount() << std::endl; // Expected: 2 (c1 and c2 still exist)

    // Demonstrate temporary object creation and immediate destruction
    std::cout << "Creating a temporary object (e.g., in a function call): " << Counter::getTotalCount() << std::endl;
    // This creates a temporary Counter object, increments count, then immediately destroys it, decrementing count.
    // So the total count should not change outside this line.
    (void)Counter(); // Explicitly create a temporary object, cast to void to suppress unused warning if any.
    std::cout << "After temporary object (should be same): " << Counter::getTotalCount() << std::endl; // Expected: 2

    // Demonstrate dynamically allocated object
    Counter* c_ptr = new Counter();
    std::cout << "After dynamically creating c_ptr. Total count: " << Counter::getTotalCount() << std::endl; // Expected: 3
    delete c_ptr; // Don't forget to delete dynamically allocated objects
    std::cout << "After deleting c_ptr. Total count: " << Counter::getTotalCount() << std::endl; // Expected: 2

    // End of main function, c1 and c2 will be destroyed automatically
    std::cout << "\nBefore main ends. Total count: " << Counter::getTotalCount() << std::endl; // Expected: 2

    std::cout << "Program exiting. c1 and c2 will be destroyed." << std::endl;

    return 0;
} // c2 and c1 are destroyed here, count becomes 0