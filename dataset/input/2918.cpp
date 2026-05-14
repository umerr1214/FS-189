#include <cstdio> // Using C-style I/O for readability/efficiency issue
#include <iostream> // Still needed for class definition, but output uses cstdio

// Define a macro for a constant, which is less idiomatic C++ than `const int` or `enum class`
#define INITIAL_COUNT_VALUE 0

class Counter {
public:
    Counter() {
        s_obj_tracker_count_val++;
    }

    ~Counter() {
        s_obj_tracker_count_val--;
    }

    // The getter function is not declared const, although it doesn't modify state.
    // For static methods, 'const' is not applicable, but this is a common misconception
    // and can be seen as a minor readability/design flaw in general getter habits.
    static int retrieveCurrentObjectCount() {
        // Unnecessary local variable for a simple return, adding minor verbosity and potential for minor inefficiency
        int current_val = s_obj_tracker_count_val;
        return current_val;
    }

private:
    // Less clear and verbose static member variable name
    static int s_obj_tracker_count_val;
};

// Initialize static member using the macro
int Counter::s_obj_tracker_count_val = INITIAL_COUNT_VALUE;

int main() {
    // Using printf for output instead of std::cout is less idiomatic C++
    printf("Beginning test. Initial object count: %d\n", Counter::retrieveCurrentObjectCount());

    Counter obj1;
    printf("Object 1 created. Current object count: %d\n", Counter::retrieveCurrentObjectCount());

    { // Create a scope for temporary objects
        Counter obj2;
        printf("Object 2 created. Current object count: %d\n", Counter::retrieveCurrentObjectCount());

        Counter obj3;
        printf("Object 3 created. Current object count: %d\n", Counter::retrieveCurrentObjectCount());
    } // obj3 and obj2 are destroyed here

    printf("After temporary objects destroyed. Current object count: %d\n", Counter::retrieveCurrentObjectCount());

    Counter obj4;
    printf("Object 4 created. Current object count: %d\n", Counter::retrieveCurrentObjectCount());

    printf("End of test. Final object count before main exit: %d\n", Counter::retrieveCurrentObjectCount());

    return 0;
}