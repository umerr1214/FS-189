#include <iostream>
#include <stdexcept> // For demonstrating a potential exception, though not strictly required

class Base {
protected:
    int data;

public:
    Base(int val = 0) : data(val) {
        std::cout << "Base object created with data: " << data << std::endl;
    }
};

class Derived : public Base {
public:
    Derived(int val = 0) : Base(val) {
        std::cout << "Derived object created." << std::endl;
    }

    void accessAndModifyData(int newValue) {
        std::cout << "Derived class: Accessing and modifying 'data'." << std::endl;
        std::cout << "Original data: " << data << std::endl;
        data = newValue; // Directly access and modify protected member
        std::cout << "New data: " << data << std::endl;
    }

    // Robustness Issue: Performs division without checking for zero divisor
    void performRiskyOperation() {
        std::cout << "\nDerived class: Attempting a risky operation (division by data)." << std::endl;
        // This is the robustness issue: no check for data == 0
        // If data is 0, this will cause a runtime error (division by zero).
        // For the purpose of demonstrating the issue, we let it happen.
        int divisor = data;
        std::cout << "Current data (divisor): " << divisor << std::endl;
        std::cout << "Attempting to divide 100 by data..." << std::endl;
        int result = 100 / divisor; // Potential division by zero
        std::cout << "Result of 100 / data: " << result << std::endl;
    }
};

// A non-member function
void demonstrateNonMemberAccess(Derived& obj) {
    std::cout << "\nNon-member function: Attempting to access 'data'." << std::endl;
    // obj.data = 200; // ERROR: 'int Base::data' is protected within this context
    std::cout << "Explanation: 'data' cannot be accessed directly from a non-member function." << std::endl;
    std::cout << "It is protected, meaning only members and friends of Base and members/friends of Derived classes can access it." << std::endl;
    std::cout << "To access it, a public member function of Derived would be needed (e.g., a getter)." << std::endl;
}

int main() {
    std::cout << "--- Demonstrating Robustness Issue ---" << std::endl;

    Derived d_obj(10);
    d_obj.accessAndModifyData(5);
    d_obj.performRiskyOperation(); // Works fine with data = 5

    std::cout << "\n--- Triggering Robustness Issue (Division by Zero) ---" << std::endl;
    d_obj.accessAndModifyData(0); // Set data to 0
    std::cout << "Calling performRiskyOperation() with data = 0. This will cause a runtime error (division by zero)." << std::endl;
    // The program will likely terminate here due to the division by zero.
    d_obj.performRiskyOperation();

    // This part might not be reached if the program crashes.
    // For a real robust program, this would be inside a try-catch or have a check.
    // demonstrateNonMemberAccess(d_obj); // This line is not relevant for the crash demo.

    return 0;
}