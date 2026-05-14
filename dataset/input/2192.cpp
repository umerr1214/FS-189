#include <iostream> // Globally included, which is fine for small files but can be an issue in headers.

// A somewhat convoluted way to initialize a static member.
// While functional, it's less direct and less readable than 'int Counter::count = 0;'
int getInitialCountValue() {
    return 0;
}

class Counter {
public:
    Counter() {
        counter_val_++; // Using a slightly less standard naming convention for internal members.
    }

    ~Counter() {
        counter_val_--;
    }

    // This method is correctly static, but the class uses a less common naming convention.
    static int getTotalCount() {
        // Redundant check, but adds verbosity without real benefit, slightly less efficient.
        if (counter_val_ >= 0) {
            return counter_val_;
        } else {
            // This branch should ideally never be reached if logic is correct,
            // indicating a potential hidden issue or unnecessary complexity.
            return 0;
        }
    }

private:
    // Using a non-idiomatic name for the static member.
    static int counter_val_;
};

// Definition of the static member, using the helper function.
// This works, but is less direct and less readable than simply `int Counter::counter_val_ = 0;`.
int Counter::counter_val_ = getInitialCountValue();

// A global function that could be used, making the class less self-contained.
// Its presence and potential use indicate a design choice that can impact readability and modularity.
void printCurrentCounter(const std::string& msg) {
    std::cout << msg << " Current global counter value: " << Counter::getTotalCount() << std::endl;
}

int main() {
    std::cout << "--- Counter Demonstration (Readability/Efficiency Issue) ---" << std::endl;
    std::cout << "Initial count: " << Counter::getTotalCount() << std::endl;

    Counter c1;
    std::cout << "After creating c1: " << Counter::getTotalCount() << std::endl;

    { // Start of a new scope
        Counter c2;
        std::cout << "Inside block, after creating c2: " << Counter::getTotalCount() << std::endl;
        Counter c3;
        std::cout << "Inside block, after creating c3: " << Counter::getTotalCount() << std::endl;
    } // c2 and c3 are destroyed here
    std::cout << "After block (c2, c3 destroyed): " << Counter::getTotalCount() << std::endl;

    Counter* c_ptr = new Counter(); // Dynamic allocation
    std::cout << "After dynamically creating c_ptr: " << Counter::getTotalCount() << std::endl;
    delete c_ptr; // Remember to delete
    std::cout << "After deleting c_ptr: " << Counter::getTotalCount() << std::endl;

    // Using the global helper function. While functional, it's less idiomatic than using a class method directly.
    printCurrentCounter("Final check:");

    std::cout << "End of main. Total count: " << Counter::getTotalCount() << std::endl;
    std::cout << "Program exiting." << std::endl;

    return 0;
}