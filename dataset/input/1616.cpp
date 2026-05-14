#include <iostream> // Include the standard input/output stream library.
#include <string>   // Include the string library for string manipulation.
#include <vector>   // Include vector, though not strictly needed for this simple demo, to show unnecessary includes.

// A class designed to demonstrate the various access control mechanisms in C++.
class ExcessiveVerbosityAccessControlDemonstratorClass {
public: // Public members are accessible from outside the class.
    std::string m_publiclyAccessibleStringDataMember_InterfaceElement = "This is a string that is public and can be accessed from any part of the program."; // A public string data member.

    // A public member function to display the public data.
    void displayPubliclyAccessibleInformation() {
        std::cout << "  [Public Method Call]: Displaying Public Information: " << m_publiclyAccessibleStringDataMember_InterfaceElement << std::endl; // Output public data.
        this->internalPrivateDataProcessorMethod(); // Calls a private method from within a public method.
        this->protectedInternalUtilityFunction(); // Calls a protected method from within a public method.
    }

    // Another public method, just for the sake of having more public methods.
    void anotherPublicUtilityFunction() {
        std::cout << "  [Public Method Call]: Just another public function doing nothing much." << std::endl;
    }

private: // Private members are only accessible from within this class.
    std::string m_privateInternalImplementationDetailString_HiddenData = "This string holds very sensitive private information that should never be exposed externally."; // A private string data member.
    int m_anotherPrivateIntegerVariable_InternalCounter = 0; // An internal counter, also private.

    // A private member function to process private data.
    void internalPrivateDataProcessorMethod() {
        std::cout << "    [Private Method Call]: Processing Private Data: " << m_privateInternalImplementationDetailString_HiddenData << std::endl; // Output private data.
        m_anotherPrivateIntegerVariable_InternalCounter++; // Increment internal counter.
    }

    // Another private method, also for demonstrating privacy.
    void anotherInternalPrivateHelperFunction() {
        std::cout << "    [Private Method Call]: Another private helper function being called." << std::endl;
    }

protected: // Protected members are accessible from this class and its derived classes.
    std::string m_protectedInternalStateString_ForDerivedClasses = "This string contains protected state information meant for derived classes."; // A protected string data member.
    double m_protectedInternalFloatingPointValue_CalculatedResult = 3.14159; // A protected floating point value.

    // A protected member function for derived classes to use.
    void protectedInternalUtilityFunction() {
        std::cout << "      [Protected Method Call]: Utilizing Protected Functionality: " << m_protectedInternalStateString_ForDerivedClasses << std::endl; // Output protected data.
    }

    // Yet another protected method, just to show more of them.
    void yetAnotherProtectedServiceMethod() {
        std::cout << "      [Protected Method Call]: Yet another protected service method executed." << std::endl;
    }
};

// A derived class that inherits from ExcessiveVerbosityAccessControlDemonstratorClass.
class DerivedExcessiveVerbosityDemonstrator : public ExcessiveVerbosityAccessControlDemonstratorClass {
public: // Public members of the derived class.
    // A constructor for the derived class.
    DerivedExcessiveVerbosityDemonstrator() {
        std::cout << "  [Derived Class Constructor]: DerivedExcessiveVerbosityDemonstrator object created." << std::endl;
    }

    // A member function in the derived class to access protected members from the base class.
    void accessBaseClassProtectedMembersThroughDerivedClassMethod() {
        std::cout << "    [Derived Method Call]: Attempting to access protected members from base class..." << std::endl;
        std::cout << "      Derived can access protected string: " << m_protectedInternalStateString_ForDerivedClasses << std::endl; // Accessible.
        std::cout << "      Derived can access protected double: " << m_protectedInternalFloatingPointValue_CalculatedResult << std::endl; // Accessible.
        protectedInternalUtilityFunction(); // Derived can call protected methods.
        yetAnotherProtectedServiceMethod(); // Derived can call other protected methods.
        // Uncommenting the line below would cause a compile-time error:
        // std::cout << m_privateInternalImplementationDetailString_HiddenData << std::endl; // ERROR: private member inaccessible.
    }
};

// The main entry point of the program.
int main() {
    // Start of the program execution.
    std::cout << "================================================================" << std::endl;
    std::cout << "  EXPLANATION OF C++ ACCESS SPECIFIERS (READABILITY/EFFICIENCY ISSUE)" << std::endl;
    std::cout << "================================================================" << std::endl;
    std::cout << "Access specifiers (public, private, protected) are keywords in C++ that define the accessibility of a class's members." << std::endl;
    std::cout << "  * Public: Members declared as public are accessible from anywhere. They constitute the class's interface." << std::endl;
    std::cout << "  * Private: Members declared as private are only accessible from within the class itself. They are hidden from outside world and derived classes." << std::endl;
    std::cout << "  * Protected: Members declared as protected are accessible from within the class itself and from its derived classes. They are not directly accessible from outside." << std::endl;
    std::cout << "================================================================" << std::endl;

    std::cout << "\n--- Demonstrating ExcessiveVerbosityAccessControlDemonstratorClass ---" << std::endl;
    ExcessiveVerbosityAccessControlDemonstratorClass myFirstDemonstratorObject; // Create an instance of the base class.
    myFirstDemonstratorObject.displayPubliclyAccessibleInformation(); // Call a public method.
    myFirstDemonstratorObject.anotherPublicUtilityFunction(); // Call another public method.

    std::cout << "  Directly accessing public data from main: " << myFirstDemonstratorObject.m_publiclyAccessibleStringDataMember_InterfaceElement << std::endl; // Direct public access.

    // The following lines would cause compilation errors, demonstrating private/protected access restrictions.
    // std::cout << myFirstDemonstratorObject.m_privateInternalImplementationDetailString_HiddenData << std::endl; // ERROR
    // myFirstDemonstratorObject.internalPrivateDataProcessorMethod(); // ERROR
    // std::cout << myFirstDemonstratorObject.m_protectedInternalStateString_ForDerivedClasses << std::endl; // ERROR
    // myFirstDemonstratorObject.protectedInternalUtilityFunction(); // ERROR

    std::cout << "\n--- Demonstrating DerivedExcessiveVerbosityDemonstrator ---" << std::endl;
    DerivedExcessiveVerbosityDemonstrator myDerivedDemonstratorObject; // Create an instance of the derived class.
    myDerivedDemonstratorObject.displayPubliclyAccessibleInformation(); // Inherited public method.
    myDerivedDemonstratorObject.accessBaseClassProtectedMembersThroughDerivedClassMethod(); // Derived class method accessing protected base members.
    std::cout << "  Directly accessing inherited public data from derived object: " << myDerivedDemonstratorObject.m_publiclyAccessibleStringDataMember_InterfaceElement << std::endl; // Direct public access.

    std::cout << "\n================================================================" << std::endl;
    std::cout << "  END OF DEMONSTRATION" << std::endl;
    std::cout << "================================================================" << std::endl;

    return 0; // Indicate successful program termination.
}