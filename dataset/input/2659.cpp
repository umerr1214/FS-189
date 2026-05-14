#include <iostream>
#include <limits> // For INT_MAX for testing potential overflow

class DataHolder {
private:
    int value; // No explicit constructor, so 'value' is uninitialized (garbage) by default.

public:
    // A setter for controlled testing, but the robustness issue is in the lack of checks in processData
    void setValue(int val) {
        value = val;
    }

    void displayValue() const {
        // Warning: Accessing uninitialized 'value' here is UB if not set first.
        std::cout << "DataHolder value: " << value << std::endl;
    }

    // Friend declaration for the free function `processData`
    friend void processData(DataHolder& dh);
};

// Processor class (as per question, but not directly used by processData if it's a free function)
class Processor {
public:
    // This class is created as per the question's requirement.
    // It doesn't directly interact with processData in this design,
    // as processData is a free function.
};

// Friend function definition
void processData(DataHolder& dh) {
    // Robustness issue 1: Operating on potentially uninitialized data.
    // If dh.value was never set, it's garbage. Incrementing it is still UB.
    // Robustness issue 2: No check for integer overflow when incrementing.
    // If dh.value is INT_MAX, incrementing it leads to undefined behavior.
    dh.value++;
    std::cout << "processData: Attempted to increment value." << std::endl;
}

int main() {
    // Test Case 1: Operating on uninitialized DataHolder
    DataHolder myDataUninitialized;
    std::cout << "--- Test Case 1: Uninitialized DataHolder ---" << std::endl;
    std::cout << "Initial state (uninitialized value): ";
    myDataUninitialized.displayValue(); // UB if value not set
    processData(myDataUninitialized);
    std::cout << "After processData (uninitialized): ";
    myDataUninitialized.displayValue(); // Value is now whatever garbage + 1

    std::cout << "\n--- Test Case 2: Potential Overflow ---" << std::endl;
    DataHolder myDataOverflow;
    myDataOverflow.setValue(std::numeric_limits<int>::max()); // Set to max
    std::cout << "Initial state (INT_MAX): ";
    myDataOverflow.displayValue();
    processData(myDataOverflow); // This will cause integer overflow (UB)
    std::cout << "After processData (INT_MAX + 1): ";
    myDataOverflow.displayValue(); // Undefined behavior output (often wraps to INT_MIN)

    return 0;
}