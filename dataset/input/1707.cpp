#include <iostream>

// BaseClass definition
class BaseClass {
protected:
    int protectedVar; // Protected member, accessible by derived classes
private:
    int privateVar;   // Private member, accessible only within BaseClass

public:
    // Constructor to initialize members using an initializer list for efficiency and correctness.
    BaseClass(int pVar = 10, int privVar = 100)
        : protectedVar(pVar), privateVar(privVar) {
        std::cout << "BaseClass constructor called. protectedVar = " << protectedVar << ", privateVar = " << privateVar << std::endl;
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
    // Constructor, explicitly calling BaseClass constructor with default values.
    // This ensures base class members are properly initialized.
    DerivedClass(int pVar = 10, int privVar = 100) : BaseClass(pVar, privVar) {
        std::cout << "DerivedClass constructor called." << std::endl;
    }

    // Method to demonstrate access to base class members
    void demonstrateAccess() {
        std::cout << "\n--- Inside DerivedClass::demonstrateAccess() ---" << std::endl;

        // Demonstrate accessing protectedVar (it is accessible)
        std::cout << "Accessing protectedVar in DerivedClass (before modification): " << protectedVar << std::endl;
        protectedVar = 25; // Modifying protectedVar directly
        std::cout << "Modified protectedVar in DerivedClass: " << protectedVar << std::endl;

        // Attempting to access privateVar (will cause a compile-time error if uncommented)
        // std::cout << "Attempting to access privateVar: " << privateVar << std::endl; // ERROR: 'privateVar' is a private member of 'BaseClass'
        std::cout << "Attempting to access privateVar: (Inaccessible - commented out due to compile error)" << std::endl;
    }
};

int main() {
    // Create an object of DerivedClass
    DerivedClass myDerivedObject;

    std::cout << "\n--- Initial state ---" << std::endl;
    myDerivedObject.displayBaseVars(); // Display initial state of base and derived members

    // Demonstrate access and modification in DerivedClass
    myDerivedObject.demonstrateAccess();

    std::cout << "\n--- State after DerivedClass modification ---" << std::endl;
    myDerivedObject.displayBaseVars(); // Display state after modification

    return 0;
}