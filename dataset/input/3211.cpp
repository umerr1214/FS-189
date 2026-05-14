#include <iostream>
#include <string>
#include <memory> // For smart pointers, to highlight the robustness issue

// Base class definition
class Base {
protected:
    int protectedMember;
private:
    int privateMember;
public:
    int publicMember;

    // Constructor to initialize members
    Base() : publicMember(10), protectedMember(20), privateMember(30) {
        std::cout << "  Base constructor called." << std::endl;
    }

    // Robustness Issue: Missing 'virtual' keyword for destructor.
    // If a Derived object is deleted via a Base* pointer,
    // the Derived destructor will not be called, leading to undefined behavior
    // (e.g., resource leaks if Derived had dynamically allocated resources).
    ~Base() {
        std::cout << "  Base destructor called." << std::endl;
    }

    // Public method to display all members (allows access to private member)
    void displayMembers() const {
        std::cout << "    Base::publicMember: " << publicMember << std::endl;
        std::cout << "    Base::protectedMember: " << protectedMember << std::endl;
        std::cout << "    Base::privateMember: " << privateMember << std::endl;
    }
};

// Derived class definition, inheriting publicly from Base
class Derived : public Base {
public:
    int derivedPublicMember;

    // Constructor
    Derived() : derivedPublicMember(40) {
        std::cout << "  Derived constructor called." << std::endl;
    }

    ~Derived() {
        std::cout << "  Derived destructor called." << std::endl;
    }

    // Method to demonstrate accessibility from within the Derived class
    void demonstrateAccessFromDerived() {
        std::cout << "\n--- Access from Derived Class ---" << std::endl;
        std::cout << "  Accessing Base members from Derived:" << std::endl;

        // Public member: Accessible
        std::cout << "    Base::publicMember (accessible): " << publicMember << std::endl;

        // Protected member: Accessible
        std::cout << "    Base::protectedMember (accessible): " << protectedMember << std::endl;

        // Private member: Inaccessible (would cause a compile error if uncommented)
        std::cout << "    Base::privateMember (inaccessible from Derived)" << std::endl;
        // std::cout << privateMember << std::endl; // Compile error
    }
};

// External class definition (unrelated to Base or Derived inheritance)
class External {
public:
    // Method to demonstrate accessibility from an External class
    void demonstrateAccessFromExternal(const Base* obj) {
        std::cout << "\n--- Access from External Class (via const Base*) ---" << std::endl;
        std::cout << "  Attempting to access Base members from External:" << std::endl;

        // Public member: Accessible
        std::cout << "    Base::publicMember (accessible): " << obj->publicMember << std::endl;

        // Protected member: Inaccessible (would cause a compile error if uncommented)
        std::cout << "    Base::protectedMember (inaccessible from External)" << std::endl;
        // std::cout << obj->protectedMember << std::endl; // Compile error

        // Private member: Inaccessible (would cause a compile error if uncommented)
        std::cout << "    Base::privateMember (inaccessible from External)" << std::endl;
        // std::cout << obj->privateMember << std::endl; // Compile error

        // To access private/protected members from External,
        // only public methods of Base/Derived can be used.
        std::cout << "\n  Using public method to display all Base members (indirect access):" << std::endl;
        obj->displayMembers();
    }
};

int main() {
    std::cout << "--- Demonstrating Class Accessibility and Robustness Issue (Missing Virtual Destructor) ---" << std::endl;

    // Create instances of the classes
    Base baseObject;
    Derived derivedObject;
    External externalObject;

    std::cout << "\n--- Initial Object States ---" << std::endl;
    std::cout << "Base Object:" << std::endl;
    baseObject.displayMembers();
    std::cout << "\nDerived Object (inherits Base members and has its own context):" << std::endl;
    derivedObject.displayMembers(); // Inherited public method
    std::cout << "    Derived::derivedPublicMember: " << derivedObject.derivedPublicMember << std::endl;

    // Demonstrate accessibility from Derived class
    derivedObject.demonstrateAccessFromDerived();

    // Demonstrate accessibility from External class
    externalObject.demonstrateAccessFromExternal(&baseObject);
    externalObject.demonstrateAccessFromExternal(&derivedObject); // Polymorphism: pass Derived* as Base*

    std::cout << "\n--- Demonstrating Robustness Issue (Polymorphic Deletion) ---" << std::endl;
    std::cout << "Creating a Derived object managed by a Base unique_ptr (polymorphism):" << std::endl;
    {
        std::unique_ptr<Base> polyPtr = std::make_unique<Derived>(); // A Derived object
        // When polyPtr goes out of scope, only Base's destructor is called because
        // Base's destructor is not virtual. Derived's destructor is skipped.
        // This is the robustness issue.
        std::cout << "  polyPtr (Derived object via Base*):" << std::endl;
        polyPtr->displayMembers();
        std::cout << "  polyPtr going out of scope now..." << std::endl;
    } // Derived destructor is NOT called here, only Base's.

    std::cout << "\n--- Demonstration Complete ---" << std::endl;

    return 0;
}