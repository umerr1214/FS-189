#include <iostream>
#include <string>

// The Person base class with public, protected, and private members.
class Person {
public:
    std::string name; // Public: Accessible from anywhere.

protected:
    std::string address; // Protected: Accessible within Person and its derived classes.

private:
    std::string phone; // Private: Accessible only within the Person class.

public:
    // Constructor to initialize all members using an initializer list for efficiency and correctness.
    Person(const std::string& n, const std::string& a, const std::string& p)
        : name(n), address(a), phone(p) {}

    // Public method to display information accessible to the public.
    void displayPublicInfo() const {
        std::cout << "Person (Public Info): Name - " << name << "\n";
    }

    // Public method to demonstrate internal access to private members.
    // This is the only way for code outside the 'phone' member's own scope to access it.
    void displayInternalPhone() const {
        std::cout << "Person (Internal Access): Phone - " << phone << "\n";
    }
};

// The Student derived class, inheriting publicly from Person.
class Student : public Person {
public:
    std::string studentId;

    // Constructor for Student, calling the base class constructor efficiently.
    Student(const std::string& n, const std::string& a, const std::string& p, const std::string& sid)
        : Person(n, a, p), studentId(sid) {}

    // Method to demonstrate member access from within the derived class (Student).
    void demonstrateDerivedClassAccess() const {
        std::cout << "\n--- Student (Derived Class) Access Demonstration ---\n";

        // 1. Accessing public member 'name': Directly accessible.
        std::cout << "  - Accessible: name (public) = " << name << "\n";

        // 2. Accessing protected member 'address': Directly accessible in derived classes.
        std::cout << "  - Accessible: address (protected) = " << address << "\n";

        // 3. Attempting to access private member 'phone': This will cause a compile-time error.
        // Uncommenting the line below would result in a compilation error:
        // error: 'std::string Person::phone' is private within this context
        // std::cout << "  - Inaccessible: phone (private) = " << phone << "\n";
        std::cout << "  - Inaccessible: phone (private) -- Cannot access directly (compile error).\n";
        std::cout << "  (Private members of base class are not accessible in derived classes).\n";

        std::cout << "  - Student ID: " << studentId << "\n";
    }
};

// Non-member function to demonstrate access rules from outside the class hierarchy.
void demonstrateNonMemberAccess(const Person& p) { // Takes Person by const reference for efficiency and safety.
    std::cout << "\n--- Non-Member Function Access Demonstration ---\n";

    // 1. Accessing public member 'name': Directly accessible.
    std::cout << "  - Accessible: name (public) = " << p.name << "\n";

    // 2. Attempting to access protected member 'address': This will cause a compile-time error.
    // Uncommenting the line below would result in a compilation error:
    // error: 'std::string Person::address' is protected within this context
    // std::cout << "  - Inaccessible: address (protected) = " << p.address << "\n";
    std::cout << "  - Inaccessible: address (protected) -- Cannot access directly (compile error).\n";
    std::cout << "  (Protected members are only accessible in derived classes, not arbitrary non-member functions).\n";

    // 3. Attempting to access private member 'phone': This will cause a compile-time error.
    // Uncommenting the line below would result in a compilation error:
    // error: 'std::string Person::phone' is private within this context
    // std::cout << "  - Inaccessible: phone (private) = " << p.phone << "\n";
    std::cout << "  - Inaccessible: phone (private) -- Cannot access directly (compile error).\n";
    std::cout << "  (Private members are never accessible from outside the class, even for non-member functions).\n";
}

int main() {
    // Create instances of Person and Student.
    Person person_obj("Alice Smith", "123 Main St", "555-1234");
    Student student_obj("Bob Johnson", "456 Oak Ave", "555-5678", "S98765");

    std::cout << "--- Initial Object Information ---\n";
    person_obj.displayPublicInfo();
    person_obj.displayInternalPhone(); // Only Person can access its private phone directly.

    // Student inherits public methods from Person.
    student_obj.displayPublicInfo(); 

    // Demonstrate access from the derived class (Student).
    student_obj.demonstrateDerivedClassAccess();

    // Demonstrate access from a non-member function.
    demonstrateNonMemberAccess(person_obj);
    // Passing a Student object to a function expecting a Person reference is safe (upcasting).
    demonstrateNonMemberAccess(student_obj); 

    std::cout << "\nDemonstration complete.\n";

    return 0;
}