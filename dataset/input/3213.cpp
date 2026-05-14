#include <iostream>
#include <string>

// Base class definition
class Base {
protected:
    int protectedMember; // Accessible from Derived classes
private:
    int privateMember;   // Accessible only within Base class
public:
    int publicMember;    // Universally accessible

    // Constructor to initialize members
    Base() : publicMember(10), protectedMember(20), privateMember(30) {
        std::cout << "  Base constructor called." << std::endl;
    }

    // Destructor (simple, no dynamic resources)
    ~Base() {
        std::cout << "  Base destructor called." << std::endl;
    }

    // Public method to display all members. This is the only way for external
    // code to indirectly access private and protected members' values.
    void displayMembers() const {
        std::cout << "    Base::publicMember: " << publicMember << std::endl;
        std::cout << "    Base::protectedMember: " << protectedMember << std::endl;
        std::cout << "    Base::privateMember: " << privateMember << std::endl;
    }
};

// Derived class definition, inheriting publicly from Base
class Derived : public Base {
public:
    // Constructor
    Derived() {
        std::cout << "  Derived constructor called." << std::endl;
    }

    // Destructor
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
        // The following line would cause a compile error:
        // std::cout << privateMember << std::endl;
    }
};

// External class definition (unrelated to Base or Derived inheritance hierarchy)
class External {
public:
    // Method to demonstrate accessibility from an External class.
    // Takes a const Base* to ensure no modification and demonstrate general external access.
    void demonstrateAccessFromExternal(const Base* obj) {
        std::cout << "\n--- Access from External Class (via const Base*) ---" << std::endl;
        std::cout << "  Attempting to access Base members from External:" << std::endl;

        // Public member: Accessible
        std::cout << "    Base::publicMember (accessible): " << obj->publicMember << std::endl;

        // Protected member: Inaccessible (would cause a compile error if uncommented)
        std::cout << "    Base::protectedMember (inaccessible from External)" << std::endl;
        // The following line would cause a compile error:
        // std::cout << obj->protectedMember << std::endl;

        // Private member: Inaccessible (would cause a compile error if uncommented)
        std::cout << "    Base::privateMember (inaccessible from External)" << std::endl;
        // The following line would cause a compile error:
        // std::cout << obj->privateMember << std::endl;

        // To access private/protected members from an External class,
        // one must use public methods provided by the Base/Derived classes.
        std::cout << "\n  Using public method to display all Base members (indirect access):" << std::endl;
        obj->displayMembers();
    }
};

int main() {
    std::cout << "--- Demonstrating C++ Class Member Accessibility ---" << std::endl;

    // Create instances of the classes
    Base baseObject;
    Derived derivedObject;
    External externalObject;

    std::cout << "\n--- Initial Object States ---" << std::endl;
    std::cout << "Base Object:" << std::endl;
    baseObject.displayMembers();

    std::cout << "\nDerived Object (inherits Base members and has its own context):" << std::endl;
    derivedObject.displayMembers(); // Inherited public method

    // Demonstrate accessibility from Derived class
    derivedObject.demonstrateAccessFromDerived();

    // Demonstrate accessibility from External class
    externalObject.demonstrateAccessFromExternal(&baseObject);
    externalObject.demonstrateAccessFromExternal(&derivedObject); // Polymorphism: pass Derived* as Base*

    std::cout << "\n--- Demonstration Complete ---" << std::endl;

    return 0;
}