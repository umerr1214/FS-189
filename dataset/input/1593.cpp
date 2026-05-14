#include <iostream> // Standard header for input/output operations

// Base class definition
class Base {
public:
    // Public method to be defined in Base
    void show(int val) {
        std::cout << "  Base::show(int) called with value: " << val << std::endl;
    }
};

// Derived class definition, inheriting publicly from Base
class Derived : public Base {
public:
    // 1. Define show(int val) in Derived:
    // This method *hides* Base::show(int val) for Derived objects and pointers.
    void show(int val) {
        std::cout << "  Derived::show(int) called with value: " << val << std::endl;
    }

    // 2. Overload show(double val) in Derived:
    // This method provides an additional overload specific to the Derived class.
    void show(double val) {
        std::cout << "  Derived::show(double) called with value: " << val << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Method Hiding vs. Overloading ---" << std::endl;

    // Create objects of Base and Derived classes
    Base base_object;
    Derived derived_object;

    std::cout << "\n=== Using Objects ===" << std::endl;

    // 1. Calling show using Base class object
    std::cout << "Scenario: Base object calling show(int)" << std::endl;
    base_object.show(10); // Calls Base::show(int)

    // 2. Calling show using Derived class object
    std::cout << "\nScenario: Derived object calling show(int) and show(double)" << std::endl;
    std::cout << "  - Calling show(int) on Derived object (demonstrates HIDING):" << std::endl;
    derived_object.show(20);      // Calls Derived::show(int) because Base::show(int) is hidden by name lookup.
    std::cout << "  - Calling show(double) on Derived object (demonstrates OVERLOADING):" << std::endl;
    derived_object.show(20.5);    // Calls Derived::show(double) as it's an available overload in Derived.
    std::cout << "  - Explicitly calling hidden Base::show(int) on Derived object:" << std::endl;
    derived_object.Base::show(25); // Explicitly calls the hidden Base::show(int) method using scope resolution.

    std::cout << "\n=== Using Pointers ===" << std::endl;

    // 3. Calling show using Base class pointer pointing to Base object
    std::cout << "Scenario: Base pointer to Base object" << std::endl;
    Base* base_ptr_to_base = &base_object;
    base_ptr_to_base->show(30); // Calls Base::show(int)

    // 4. Calling show using Base class pointer pointing to Derived object
    // This is a crucial point for understanding method hiding.
    std::cout << "\nScenario: Base pointer to Derived object (demonstrates HIDING)" << std::endl;
    Base* base_ptr_to_derived = &derived_object;
    base_ptr_to_derived->show(40); // Calls Base::show(int), NOT Derived::show(int),
                                   // because the Base pointer's static type only sees Base's methods.
    // Note: base_ptr_to_derived->show(40.5) would be a compile-time error
    // because the Base class does not have a show(double) method.

    // 5. Calling show using Derived class pointer pointing to Derived object
    std::cout << "\nScenario: Derived pointer to Derived object" << std::endl;
    Derived* derived_ptr_to_derived = &derived_object;
    std::cout << "  - Calling show(int) on Derived pointer:" << std::endl;
    derived_ptr_to_derived->show(50);      // Calls Derived::show(int)
    std::cout << "  - Calling show(double) on Derived pointer:" << std::endl;
    derived_ptr_to_derived->show(50.5);    // Calls Derived::show(double)
    std::cout << "  - Explicitly calling hidden Base::show(int) on Derived pointer:" << std::endl;
    derived_ptr_to_derived->Base::show(55); // Explicitly calls the hidden Base::show(int) method.

    std::cout << "\n--- End of Demonstration ---" << std::endl;

    return 0; // Indicate successful execution
}