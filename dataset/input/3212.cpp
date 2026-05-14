#include <iostream> // Essential for standard input and output operations, like printing to the console.
#include <string>   // Included for string manipulation capabilities, though its direct use is minimal in this specific accessibility demonstration.

// Definition of the primary base class. This class serves as the foundation for demonstrating
// various access specifiers (public, protected, private) within a C++ class hierarchy.
class TheFundamentalBaseClassForAccessibilityDemonstration {
protected: // Members declared here are accessible from derived classes and any friend classes.
    int m_protected_integer_data_member_of_the_base_class_for_inheritable_data;
private: // Members declared here are strictly encapsulated, accessible only from within this class or its friends.
    int m_private_integer_data_member_of_the_base_class_for_strict_encapsulation_and_internal_logic;
public: // Members declared here are universally accessible from any part of the program.
    int m_public_integer_data_member_of_the_base_class_for_general_purpose_use;

    // The constructor for TheFundamentalBaseClassForAccessibilityDemonstration.
    // It initializes all the data members with specific integer values.
    TheFundamentalBaseClassForAccessibilityDemonstration()
        : m_public_integer_data_member_of_the_base_class_for_general_purpose_use(101),
          m_protected_integer_data_member_of_the_base_class_for_inheritable_data(202),
          m_private_integer_data_member_of_the_base_class_for_strict_encapsulation_and_internal_logic(303)
    {
        // A verbose message indicating the successful construction of a base class instance.
        std::cout << "  An instance of TheFundamentalBaseClassForAccessibilityDemonstration has been successfully constructed." << std::endl;
    }

    // A public method provided to display the values of all members of the base class.
    // This method is necessary to indirectly show the value of the private member.
    void DisplayAllMembersOfTheBaseClassForVerificationPurposes() const {
        std::cout << "    Current member values within TheFundamentalBaseClassForAccessibilityDemonstration instance:" << std::endl;
        std::cout << "      Public Member (m_public_integer_data_member_of_the_base_class_for_general_purpose_use): "
                  << m_public_integer_data_member_of_the_base_class_for_general_use << std::endl;
        std::cout << "      Protected Member (m_protected_integer_data_member_of_the_base_class_for_inheritable_data): "
                  << m_protected_integer_data_member_of_the_base_class_for_inheritable_data << std::endl;
        std::cout << "      Private Member (m_private_integer_data_member_of_the_base_class_for_strict_encapsulation_and_internal_logic): "
                  << m_private_integer_data_member_of_the_base_class_for_strict_encapsulation_and_internal_logic << std::endl;
    }
}; // End of TheFundamentalBaseClassForAccessibilityDemonstration class definition.

// Definition of the derived class, which publicly inherits from the base class.
// This class illustrates how inherited members are accessed from a derived context.
class TheSpecializedDerivedClassInheritingFromTheBase : public TheFundamentalBaseClassForAccessibilityDemonstration {
public: // A public member specific to this derived class, demonstrating its own data.
    int m_public_integer_data_member_of_the_derived_class_for_specific_functionality_only;

    // The constructor for TheSpecializedDerivedClassInheritingFromTheBase.
    // It initializes its own specific data member.
    TheSpecializedDerivedClassInheritingFromTheBase()
        : m_public_integer_data_member_of_the_derived_class_for_specific_functionality_only(404)
    {
        // Another verbose constructor message for the derived class.
        std::cout << "  An instance of TheSpecializedDerivedClassInheritingFromTheBase has been successfully constructed." << std::endl;
    }

    // A method within the derived class to explicitly demonstrate its access privileges
    // to members inherited from the base class.
    void DemonstrateAccessibilityFromWithinTheDerivedClass() {
        std::cout << "\n--- Detailed Demonstration of Accessibility from Within TheSpecializedDerivedClassInheritingFromTheBase ---" << std::endl;
        std::cout << "  Attempting to access various members inherited from TheFundamentalBaseClassForAccessibilityDemonstration:" << std::endl;

        // Accessing the public member of the base class. This is always allowed.
        std::cout << "    The public member (m_public_integer_data_member_of_the_base_class_for_general_purpose_use) IS fully accessible: "
                  << m_public_integer_data_member_of_the_base_class_for_general_purpose_use << std::endl;

        // Accessing the protected member of the base class. This is allowed within derived classes.
        std::cout << "    The protected member (m_protected_integer_data_member_of_the_base_class_for_inheritable_data) IS fully accessible: "
                  << m_protected_integer_data_member_of_the_base_class_for_inheritable_data << std::endl;

        // Attempting to access the private member of the base class. This would result in a compile-time error.
        // The line is commented out to allow compilation, but its inaccessibility is noted.
        std::cout << "    The private member (m_private_integer_data_member_of_the_base_class_for_strict_encapsulation_and_internal_logic) is INACCESSIBLE (would cause a compile-time error if uncommented)." << std::endl;
        // std::cout << m_private_integer_data_member_of_the_base_class_for_strict_encapsulation_and_internal_logic << std::endl; // Compile error!

        // Also demonstrating access to this derived class's own public member.
        std::cout << "    This derived class's own public member (m_public_integer_data_member_of_the_derived_class_for_specific_functionality_only) IS fully accessible: "
                  << m_public_integer_data_member_of_the_derived_class_for_specific_functionality_only << std::endl;
    }
}; // End of TheSpecializedDerivedClassInheritingFromTheBase class definition.

// Definition of an external, unrelated class. This class demonstrates access to
// members of the base class from a completely independent context.
class TheCompletelyExternalAndUnrelatedClassForAccessibilityTesting {
public: // A public method within this external class to perform the demonstration.
    // It takes a pointer to a base class object to interact with it.
    void PerformExternalAccessibilityDemonstration(TheFundamentalBaseClassForAccessibilityDemonstration* p_base_object_reference_for_external_access) {
        std::cout << "\n--- Detailed Demonstration of Accessibility from TheCompletelyExternalAndUnrelatedClassForAccessibilityTesting ---" << std::endl;
        std::cout << "  Attempting to access members of TheFundamentalBaseClassForAccessibilityDemonstration via a pointer from an external context:" << std::endl;

        // Accessing the public member of the base class. This is always allowed.
        std::cout << "    The public member (m_public_integer_data_member_of_the_base_class_for_general_purpose_use) IS fully accessible: "
                  << p_base_object_reference_for_external_access->m_public_integer_data_member_of_the_base_class_for_general_purpose_use << std::endl;

        // Attempting to access the protected member of the base class. This would result in a compile-time error.
        // The line is commented out, but its inaccessibility from an external class is stated.
        std::cout << "    The protected member (m_protected_integer_data_member_of_the_base_class_for_inheritable_data) is INACCESSIBLE (would cause a compile-time error if uncommented)." << std::endl;
        // std::cout << p_base_object_reference_for_external_access->m_protected_integer_data_member_of_the_base_class_for_inheritable_data << std::endl; // Compile error!

        // Attempting to access the private member of the base class. This would also result in a compile-time error.
        // The line is commented out, and its inaccessibility from an external class is noted.
        std::cout << "    The private member (m_private_integer_data_member_of_the_base_class_for_strict_encapsulation_and_internal_logic) is INACCESSIBLE (would cause a compile-time error if uncommented)." << std::endl;
        // std::cout << p_base_object_reference_for_external_access->m_private_integer_data_member_of_the_base_class_for_strict_encapsulation_and_internal_logic << std::endl; // Compile error!

        // To access private or protected members from an external class, one must use public methods
        // provided by the Base or Derived classes.
        std::cout << "\n  Utilizing a public method (DisplayAllMembersOfTheBaseClassForVerificationPurposes) for indirect access to all Base members:" << std::endl;
        p_base_object_reference_for_external_access->DisplayAllMembersOfTheBaseClassForVerificationPurposes();
    }
}; // End of TheCompletelyExternalAndUnrelatedClassForAccessibilityTesting class definition.

// The actual main function that orchestrates the program's execution.
// This function creates instances of the classes and calls their demonstration methods.
int main_function_for_program_execution() {
    std::cout << "--- Program Initialization and Object Creation Phase ---" << std::endl;
    // Creating instances of the defined classes to use for demonstration.
    TheFundamentalBaseClassForAccessibilityDemonstration base_instance_one;
    TheSpecializedDerivedClassInheritingFromTheBase derived_instance_one;
    TheCompletelyExternalAndUnrelatedClassForAccessibilityTesting external_instance_one;

    std::cout << "\n--- Initial State of All Constructed Objects ---" << std::endl;
    std::cout << "State of the Base object (base_instance_one):" << std::endl;
    base_instance_one.DisplayAllMembersOfTheBaseClassForVerificationPurposes();

    std::cout << "\nState of the Derived object (derived_instance_one) - showing inherited Base members and its own specific member:" << std::endl;
    derived_instance_one.DisplayAllMembersOfTheBaseClassForVerificationPurposes(); // Inherited public method call
    std::cout << "      Derived-specific Public Member: " << derived_instance_one.m_public_integer_data_member_of_the_derived_class_for_specific_functionality_only << std::endl;

    // Initiating the accessibility demonstrations from different contexts.
    derived_instance_one.DemonstrateAccessibilityFromWithinTheDerivedClass();
    external_instance_one.PerformExternalAccessibilityDemonstration(&base_instance_one);
    external_instance_one.PerformExternalAccessibilityDemonstration(&derived_instance_one); // Demonstrating polymorphism by passing Derived* as Base*

    std::cout << "\n--- Program Execution and Accessibility Demonstration Completed ---" << std::endl;
    return 0; // Signifying successful completion of the program.
}

// A simple wrapper for the actual main function. This adds an unnecessary layer of indirection
// and contributes to the readability/efficiency issue by complicating the entry point.
int main() {
    return main_function_for_program_execution();
}