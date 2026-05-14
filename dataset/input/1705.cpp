#include <iostream>

// BaseClass definition
class BaseClass {
protected:
    int protectedVar; // Robustness Issue: Not explicitly initialized in constructor
private:
    int privateVar;

public:
    // Constructor for BaseClass
    BaseClass() {
        // protectedVar is not explicitly initialized here. For an 'int' member,
        // it might be zero-initialized by the compiler in this context,
        // but relying on this implicit behavior is a robustness flaw.
        // It could lead to undefined behavior or unexpected values in more complex scenarios
        // or with different types if not explicitly initialized.
        privateVar = 100; // privateVar is explicitly initialized.
        std::cout << "BaseClass constructor called. privateVar = " << privateVar << std::endl;
    }

    // Method to display base class variables
    void displayBaseVars() const {
        std::cout << "BaseClass::protectedVar: " << protectedVar << std::endl;
        std::cout << "BaseClass::privateVar: " << privateVar << std::endl;
    }
};

// DerivedClass definition, inheriting publicly from BaseClass
class DerivedClass : public BaseClass {
public:
    // Constructor for DerivedClass
    DerivedClass() {
        std::cout << "DerivedClass constructor called." << std::endl;
        // The BaseClass constructor is implicitly called here.
        // If BaseClass didn't initialize protectedVar, it might hold an
        // uninitialized/garbage value when accessed by DerivedClass before modification.
    }

    // Method to demonstrate access to base class members
    void demonstrateAccess() {
        std::cout << "\n--- Inside DerivedClass::demonstrateAccess() ---" << std::endl;

        // Accessing protectedVar (demonstrates it's accessible)
        // At this point, protectedVar might contain an unexpected value if BaseClass
        // didn't explicitly initialize it. This highlights the robustness issue.
        std::cout << "Accessing protectedVar in DerivedClass (before modification): " << protectedVar << std::endl;
        protectedVar = 20; // Modifying protectedVar
        std::cout << "Modified protectedVar in DerivedClass: " << protectedVar << std::endl;

        // Attempting to access privateVar (will cause a compile-time error if uncommented)
        // std::cout << "Attempting to access privateVar: " << privateVar << std::endl; // ERROR: 'privateVar' is a private member of 'BaseClass'
        std::cout << "Attempting to access privateVar: (Inaccessible - commented out due to compile error)" << std::endl;
    }
};

int main() {
    // Create an object of DerivedClass
    DerivedClass myDerivedObject;

    std::cout << "\n--- Initial state (protectedVar might be implicitly initialized or garbage) ---" << std::endl;
    myDerivedObject.displayBaseVars(); // Display initial state

    // Demonstrate access and modification in DerivedClass
    myDerivedObject.demonstrateAccess();

    std::cout << "\n--- State after DerivedClass modification ---" << std::endl;
    myDerivedObject.displayBaseVars(); // Display state after modification

    return 0;
}