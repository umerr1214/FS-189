#include <iostream>
#include <string>
#include <vector> // Unnecessary include, adding to potential bloat

class Person {
public:
    std::string name; // Public: Accessible from anywhere.

protected:
    std::string address; // Protected: Accessible within Person and its derived classes.

private:
    std::string phone; // Private: Accessible only within the Person class.

public:
    Person(const std::string& n, const std::string& a, const std::string& p)
        : name(n), address(a), phone(p) {}

    void displayPersonPublicInfo() const {
        std::cout << "Person (Public): Name - " << name << "\n";
    }

    // Robustness Issue: This method publicly exposes a pointer to a protected member.
    // This breaks encapsulation and allows external code to modify a protected member.
    std::string* getAddressPtr() {
        return &address; // Directly returning a pointer to a protected member.
    }

    // A method to access private info (only accessible within Person)
    void displayPersonPrivateInfo() const {
        std::cout << "Person (Private): Phone - " << phone << "\n";
    }
};

class Student : public Person {
public:
    std::string studentId;

    Student(const std::string& n, const std::string& a, const std::string& p, const std::string& sid)
        : Person(n, a, p), studentId(sid) {}

    void demonstrateAccess() {
        std::cout << "\n--- Student (Derived Class) Access Demonstration ---\n";
        std::cout << "  - Accessible: name (public) - " << name << "\n";
        std::cout << "  - Accessible: address (protected) - " << address << "\n";
        // std::cout << "  - Inaccessible: phone (private) - " << phone << "\n"; // This line would cause a compile error.
        std::cout << "  - Inaccessible: phone (private) -- Cannot access directly (compile error).\n";
        std::cout << "  - Student ID: " << studentId << "\n";

        // Demonstrating the robustness issue: using the leaked protected member pointer.
        std::string* leakedAddress = getAddressPtr(); // Calling the problematic method.
        if (leakedAddress) {
            std::cout << "  Robustness Issue: Leaked address pointer used: " << *leakedAddress << "\n";
            *leakedAddress = "123 Leaked St., Modified City"; // Modification through leaked pointer.
            std::cout << "  Robustness Issue: Address modified via leaked pointer: " << address << "\n";
        }
    }
};

// Non-member function
void demonstrateNonMemberAccess(Person& p) {
    std::cout << "\n--- Non-Member Function Access Demonstration ---\n";
    std::cout << "  - Accessible: name (public) - " << p.name << "\n";
    // std::cout << "  - Inaccessible: address (protected) - " << p.address << "\n"; // This line would cause a compile error.
    std::cout << "  - Inaccessible: address (protected) -- Cannot access directly (compile error).\n";
    // std::cout << "  - Inaccessible: phone (private) - " << p.phone << "\n";     // This line would cause a compile error.
    std::cout << "  - Inaccessible: phone (private) -- Cannot access directly (compile error).\n";

    std::cout << "  (Non-member functions can only access public members directly).\n";
}

int main() {
    Person p("Alice Wonderland", "101 Main St", "555-1111");
    Student s("Bob The Builder", "202 Oak Ave", "555-2222", "S12345");

    std::cout << "Initial Person Info:\n";
    p.displayPersonPublicInfo();
    p.displayInternalPhone(); // Only accessible via Person's own method.

    std::cout << "\nInitial Student Info:\n";
    s.displayPersonPublicInfo(); // Inherited public method.

    s.demonstrateAccess(); // Student demonstrates its access and the robustness flaw.
    demonstrateNonMemberAccess(s); // Pass Student object as Person reference.

    std::cout << "\n--- After Student's demonstrateAccess (showing modification via leak) ---\n";
    s.displayPersonPublicInfo(); // Check if name is still correct.
    // Re-access the address to confirm the modification made via the leaked pointer.
    std::cout << "  Student's address after potential leak modification: " << *(s.getAddressPtr()) << "\n";

    return 0;
}