#include <iostream>

class Base {
public:
    void show(int val) {
        std::cout << "  Base::show(int) called with value: " << val << std::endl;
    }
};

class Derived : public Base {
public:
    // This hides Base::show(int val)
    void show(int val) {
        std::cout << "  Derived::show(int) called with value: " << val << std::endl;
    }

    // This overloads show in Derived
    void show(double val) {
        std::cout << "  Derived::show(double) called with value: " << val << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Method Hiding and Overloading (Robustness Issue: Incomplete Hiding Demo) ---" << std::endl;

    Base b_obj;
    Derived d_obj;

    // 1. Calling show using Base class object
    std::cout << "\n=== Using Base Object ===" << std::endl;
    b_obj.show(10); // Calls Base::show(int)

    // 2. Calling show using Derived class object
    std::cout << "\n=== Using Derived Object ===" << std::endl;
    std::cout << "  - Calling show(int) on Derived object (Hiding Base::show(int)):" << std::endl;
    d_obj.show(20);      // Calls Derived::show(int)
    std::cout << "  - Calling show(double) on Derived object (Overloading):" << std::endl;
    d_obj.show(20.5);    // Calls Derived::show(double)

    // 3. Calling show using Base class pointer pointing to Base object
    std::cout << "\n=== Using Base Pointer to Base Object ===" << std::endl;
    Base* b_ptr_base = &b_obj;
    b_ptr_base->show(30); // Calls Base::show(int)

    // 4. Calling show using Base class pointer pointing to Derived object
    // This demonstrates method hiding: Base pointer can only see Base methods.
    std::cout << "\n=== Using Base Pointer to Derived Object (Method Hiding) ===" << std::endl;
    Base* b_ptr_derived = &d_obj;
    b_ptr_derived->show(40); // Calls Base::show(int), NOT Derived::show(int)

    // Attempting to call Derived::show(double) through a Base pointer would cause a compile-time error
    // b_ptr_derived->show(40.5); // Error: 'class Base' has no member named 'show' with 'double' argument

    // 5. Calling show using Derived class pointer pointing to Derived object
    std::cout << "\n=== Using Derived Pointer to Derived Object ===" << std::endl;
    Derived* d_ptr_derived = &d_obj;
    std::cout << "  - Calling show(int) on Derived pointer:" << std::endl;
    d_ptr_derived->show(50);      // Calls Derived::show(int)
    std::cout << "  - Calling show(double) on Derived pointer:" << std::endl;
    d_ptr_derived->show(50.5);    // Calls Derived::show(double)

    std::cout << "\n--- End of Demonstration ---" << std::endl;
    std::cout << "NOTE: This demonstration shows method hiding where Derived::show(int) hides Base::show(int)." << std::endl;
    std::cout << "However, it does not explicitly show how to call the hidden Base::show(int) method using a Derived object (e.g., d_obj.Base::show(int))." << std::endl;
    std::cout << "This omission makes the demonstration of method hiding incomplete, which can be a robustness issue in understanding for a learner." << std::endl;

    return 0;
}