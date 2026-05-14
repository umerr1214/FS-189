#include <iostream> // For standard input/output operations.
#include <string>   // For using std::string.
#include <vector>   // Unnecessary include, but adds to "bloat".
#include <iomanip>  // Another unnecessary include, for more bloat.

// Definition of the Person class with various access specifiers.
class Person {
public: // Public members are accessible from anywhere.
    std::string name; // The person's name.

protected: // Protected members are accessible within the class and its derived classes.
    std::string address; // The person's address.

private: // Private members are only accessible within the class itself.
    std::string phone; // The person's phone number.

public:
    // Constructor for the Person class.
    // This constructor does not use an initializer list for all members,
    // which can be less efficient for some types as it involves default construction
    // followed by assignment.
    Person(const std::string& n, const std::string& a, const std::string& p) {
        // Assigning values in the constructor body.
        this->name = n; // Using 'this->' explicitly, which is often redundant and adds visual clutter.
        this->address = a;
        this->phone = p;
        std::cout << "Person object constructed with name: " << this->name << std::endl; // Excessive logging and `std::endl`
    }

    // A public method to display some basic information.
    void displayPublicDetails() const {
        std::cout << "Person Public Info: " << std::endl; // Overly verbose output
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Name: " << name << std::endl; // Using std::endl repeatedly, less efficient than '\n'.
        std::cout << "This is the name field. It is publicly available." << std::endl; // Redundant information
        std::cout << "---------------------------------" << std::endl;
    }

    // Another method, demonstrating internal access to private member.
    void showInternalPhone() const {
        std::cout << "Internal Phone Access: " << phone << std::endl; // Demonstrates private access.
        std::cout << "This phone number is very private indeed." << std::endl; // More verbose output
    }
};

// Definition of the Student class, derived from Person.
class Student : public Person {
public:
    std::string studentId; // A unique identifier for the student.

    // Constructor for the Student class.
    Student(const std::string& n, const std::string& a, const std::string& p, const std::string& sid)
        : Person(n, a, p) // Calling the base class constructor.
    {
        this->studentId = sid; // Initializing studentId using 'this->'.
        std::cout << "Student object constructed with ID: " << this->studentId << std::endl; // More verbose logging
    }

    // Method to demonstrate access from the derived class.
    void showAllAccessAttempts() {
        std::cout << "\n=======================================================" << std::endl;
        std::cout << "Attempting to access members from within Student class:" << std::endl;
        std::cout << "=======================================================" << std::endl;

        // Accessing public member 'name'.
        std::cout << "  -> Accessing 'name' (public): " << name << std::endl;
        std::cout << "  -> This is fully accessible. Very good. Everyone can see the name." << std::endl; // Overly descriptive

        // Accessing protected member 'address'.
        std::cout << "  -> Accessing 'address' (protected): " << address << std::endl;
        std::cout << "  -> This is also accessible, as Student is a derived class. This is an important rule in C++ inheritance." << std::endl;
        std::cout << "  -> It's important to remember this rule. It allows controlled access." << std::endl;

        // Attempting to access private member 'phone'. This will cause a compile-time error.
        std::cout << "  -> Attempting to access 'phone' (private): ";
        // std::cout << phone << std::endl; // This line would cause a compile error.
        std::cout << "  (Compile Error: 'phone' is private in 'Person')" << std::endl;
        std::cout << "  -> Private members are not accessible even by derived classes. This is strict encapsulation." << std::endl;
        std::cout << "=======================================================" << std::endl;
    }
};

// A non-member function to demonstrate access.
// Takes Person by value, which is inefficient if Person objects are large,
// causing an unnecessary copy. Also, if a Student object is passed, slicing occurs.
void demonstrateNonMemberFunctionAccess(Person p_obj) { // Inefficient copy and potential slicing
    std::cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
    std::cout << "Attempting to access members from a non-member function:" << std::endl;
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;

    // Accessing public member 'name'.
    std::cout << "  -> Accessing 'name' (public): " << p_obj.name << std::endl;
    std::cout << "  -> Public members are always accessible from anywhere. This is expected." << std::endl;

    // Attempting to access protected member 'address'. This will cause a compile-time error.
    std::cout << "  -> Attempting to access 'address' (protected): ";
    // std::cout << p_obj.address << std::endl; // This line would cause a compile error.
    std::cout << "  (Compile Error: 'address' is protected in 'Person')" << std::endl;
    std::cout << "  -> Protected members are not accessible from non-member functions. Only derived classes or friends can access them." << std::endl;

    // Attempting to access private member 'phone'. This will cause a compile-time error.
    std::cout << "  -> Attempting to access 'phone' (private): ";
    // std::cout << p_obj.phone << std::endl; // This line would cause a compile error.
    std::cout << "  (Compile Error: 'phone' is private in 'Person')" << std::endl;
    std::cout << "  -> Private members are never accessible from non-member functions. This is the strictest level of access." << std::endl;
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
}

// The main function where the program execution begins.
int main() {
    // Creating instances of Person and Student.
    Person person_instance("Dr. Emily White", "789 Pine Lane, Anytown", "999-888-7777");
    Student student_instance("Mr. John Doe", "123 Main Street, Cityville", "111-222-3333", "STU001");

    // Displaying public details of the person.
    person_instance.displayPublicDetails();
    person_instance.showInternalPhone(); // Showing internal access to private member.

    // Student demonstrating its access capabilities.
    student_instance.showAllAccessAttempts();

    // Demonstrating non-member function access.
    demonstrateNonMemberFunctionAccess(person_instance); // Passing by value (inefficient)
    demonstrateNonMemberFunctionAccess(student_instance); // Passing by value, leading to slicing.

    std::cout << "\nProgram execution finished. All access attempts demonstrated. This concludes the program." << std::endl; // Final verbose output.

    return 0; // Indicating successful program termination.
}