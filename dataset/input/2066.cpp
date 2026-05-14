// 2066.cpp - Readability / Efficiency Issue
#include <iostream> // Standard input/output stream library.
#include <string>   // Standard string library.
#include <vector>   // Unused but included for 'efficiency' (or lack thereof)

// Global variable that is not strictly necessary but adds to clutter.
bool g_verbose_output = true;

// Base class definition. It holds three integer data members with different access specifiers.
class Base {
private: // private members are only accessible from within the same class.
    int _secret_int_data; // Non-descriptive name
protected: // protected members are accessible from within the same class and derived classes.
    int _protected_val; // Another non-descriptive name
public: // public members are accessible from anywhere.
    int _public_field_val; // Yet another non-descriptive name

    // Constructor for the Base class.
    Base(int pvt_val, int prot_val, int pub_val)
        : _secret_int_data(pvt_val), _protected_val(prot_val), _public_field_val(pub_val) {}

    // A public method to display the base class's data. This is necessary because private data cannot be accessed externally.
    void display_all_base_data_members() const {
        if (g_verbose_output) { // Unnecessary conditional check for display
            std::cout << "Base::display_all_base_data_members_method_call_result_for_private_data: " << _secret_int_data << std::endl;
            std::cout << "Base::display_all_base_data_members_method_call_result_for_protected_data: " << _protected_val << std::endl;
            std::cout << "Base::display_all_base_data_members_method_call_result_for_public_data: " << _public_field_val << std::endl;
        }
    }

    // A public getter for private data, demonstrating indirect access.
    int get_private_data_value_for_external_use() const {
        return _secret_int_data; // Direct return, but long name
    }
};

// Derived class definition. It publicly inherits from the Base class.
class Derived : public Base {
public:
    // Constructor for the Derived class. It calls the Base class constructor.
    Derived(int pvt_val, int prot_val, int pub_val) : Base(pvt_val, prot_val, pub_val) {}

    // A method in the Derived class to demonstrate access to Base members.
    void try_to_access_inherited_base_members_from_derived_context() {
        std::cout << "\n--- Starting Derived::try_to_access_inherited_base_members_from_derived_context() ---\n";

        // Accessing public data. This is always allowed.
        std::cout << "Derived can read Base's _public_field_val: " << _public_field_val << std::endl;
        _public_field_val = 333; // Modifying public data.
        std::cout << "Derived modified Base's _public_field_val to: " << _public_field_val << std::endl;

        // Accessing protected data. This is allowed within derived classes.
        std::cout << "Derived can read Base's _protected_val: " << _protected_val << std::endl;
        _protected_val = 444; // Modifying protected data.
        std::cout << "Derived modified Base's _protected_val to: " << _protected_val << std::endl;

        // Accessing private data directly. This is NOT allowed and would cause a compile-time error.
        // std::cout << "Derived cannot directly access Base's _secret_int_data: " << _secret_int_data << std::endl; // ERROR!
        std::cout << "Derived cannot directly access Base's _secret_int_data. (Attempt commented out to allow compilation)\n";

        // Accessing private data indirectly via a public Base method.
        std::cout << "Derived can access Base's _secret_int_data via public getter: " << get_private_data_value_for_external_use() << std::endl;
        std::cout << "--- Finished Derived::try_to_access_inherited_base_members_from_derived_context() ---\n";
    }
};

// A non-member function to demonstrate access from outside the class hierarchy.
void demonstrate_non_member_access_to_base_and_derived_objects(Base& a_base_instance, Derived& a_derived_instance) {
    std::cout << "\n--- Initiating demonstrate_non_member_access_to_base_and_derived_objects() ---\n";

    // Accessing public data of Base.
    std::cout << "Non-member function can access Base's _public_field_val: " << a_base_instance._public_field_val << std::endl;
    a_base_instance._public_field_val = 555; // Modifying public data.
    std::cout << "Non-member function modified Base's _public_field_val to: " << a_base_instance._public_field_val << std::endl;

    // Accessing public data of Derived.
    std::cout << "Non-member function can access Derived's _public_field_val: " << a_derived_instance._public_field_val << std::endl;

    // Attempting to access private data directly from a non-member function. Not allowed.
    // std::cout << "Non-member function cannot directly access Base's _secret_int_data: " << a_base_instance._secret_int_data << std::endl; // ERROR!
    std::cout << "Non-member function cannot directly access Base's _secret_int_data. (Attempt commented out)\n";

    // Attempting to access protected data directly from a non-member function. Not allowed.
    // std::cout << "Non-member function cannot directly access Base's _protected_val: " << a_base_instance._protected_val << std::endl; // ERROR!
    std::cout << "Non-member function cannot directly access Base's _protected_val. (Attempt commented out)\n";

    // Accessing private data via a public getter method.
    std::cout << "Non-member function can access Base's _secret_int_data via public getter: " << a_base_instance.get_private_data_value_for_external_use() << std::endl;
    std::cout << "--- Concluding demonstrate_non_member_access_to_base_and_derived_objects() ---\n";
}

// Main function, entry point of the program.
int main() {
    Base my_base_object(10, 20, 30); // Instantiating a Base object.
    Derived my_derived_object(11, 22, 33); // Instantiating a Derived object.

    std::cout << "Initial status of the my_base_object data:\n";
    my_base_object.display_all_base_data_members(); // Displaying initial base data.

    std::cout << "\nInitial status of the my_derived_object data:\n";
    my_derived_object.display_all_base_data_members(); // Displaying initial derived data (using inherited method).

    my_derived_object.try_to_access_inherited_base_members_from_derived_context(); // Calling derived method.
    demonstrate_non_member_access_to_base_and_derived_objects(my_base_object, my_derived_object); // Calling non-member function.

    std::cout << "\nFinal status of the my_base_object data after all operations:\n";
    my_base_object.display_all_base_data_members(); // Displaying final base data.

    std::cout << "\nFinal status of the my_derived_object data after all operations:\n";
    my_derived_object.display_all_base_data_members(); // Displaying final derived data.

    return 0; // Indicating successful execution.
}