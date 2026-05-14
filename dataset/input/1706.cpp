#include <iostream> // Include iostream for standard input/output operations.

// This is the BaseClass definition, demonstrating base class structure.
class BaseClass {
protected: // Protected members are accessible by derived classes.
    int b_var_p; // Poor naming: should be 'protectedVar' for clarity.
private: // Private members are only accessible within this class.
    int b_var_priv; // Poor naming: should be 'privateVar' for clarity.

public: // Public members are accessible from anywhere.
    // Constructor for BaseClass, initializing members.
    BaseClass() : b_var_p(10), b_var_priv(100) { // Using initializer list is good practice.
        // This constructor initializes the base class members with default values.
        std::cout << "BaseClass constructor called." << std::endl << std::endl; // Excessive use of std::endl and blank lines.
    }

    // Method to display base class variables.
    void showBaseVars() const { // Method name 'showBaseVars' is okay, but 'displayBaseVars' might be more common.
        std::cout << "Displaying BaseClass variables:" << std::endl; // Redundant output statement.
        std::cout << "BaseClass::b_var_p: " << b_var_p << std::endl; // Using std::endl repeatedly flushes buffer, less efficient than '\n'.
        std::cout << "BaseClass::b_var_priv: " << b_var_priv << std::endl << std::endl; // More redundant newlines.
    }
};

// This is the DerivedClass definition, inheriting publicly from BaseClass.
class DerivedClass : public BaseClass {
public: // Public members are accessible from anywhere.
    // Constructor for DerivedClass.
    DerivedClass() {
        // The BaseClass constructor is implicitly called before this constructor's body executes.
        std::cout << "DerivedClass constructor called." << std::endl; // Output on construction.
    }

    // Method to demonstrate access to base class members from the derived class.
    void doAccessDemo() { // Method name 'doAccessDemo' is less descriptive than 'demonstrateAccess'.
        std::cout << "--- Inside DerivedClass::doAccessDemo() ---" << std::endl; // Unnecessary separator output.

        // Accessing the protected member from BaseClass.
        std::cout << "Value of b_var_p before modification: " << b_var_p << std::endl; // Verbose output.
        this->b_var_p = 25; // Modifying the protected variable. Using 'this->' is redundant here and reduces readability.
        int temp_val = this->b_var_p; // Unnecessary intermediate variable 'temp_val'.
        std::cout << "Value of b_var_p after modification: " << temp_val << std::endl; // Printing the unnecessary 'temp_val'.

        // Attempting to access the private member from BaseClass.
        // This line would cause a compile-time error if uncommented because 'b_var_priv' is private.
        // std::cout << "Attempting to access b_var_priv: " << b_var_priv << std::endl; // ERROR!
        std::cout << "Note: b_var_priv is private and cannot be accessed directly in DerivedClass." << std::endl;
        std::cout << "This statement is commented out to allow compilation." << std::endl << std::endl; // Excessive comments and output.
    }
};

// Main function where the program execution begins.
int main() {
    // Creating an object of DerivedClass.
    DerivedClass myDerivedObject; // Object creation is straightforward.

    // Showing the initial state of the object's variables.
    myDerivedObject.showBaseVars(); // Call to display base variables.

    // Performing the access demonstration within the derived class.
    myDerivedObject.doAccessDemo(); // Call to derived class method.

    // Showing the state after modifications made in the derived class.
    myDerivedObject.showBaseVars(); // Call again to display updated variables.

    // Program finishes successfully.
    return 0; // Return 0 to indicate successful execution.
}