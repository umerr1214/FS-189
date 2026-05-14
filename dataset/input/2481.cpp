#include <iostream>
#include <string>

// BaseClass definition
class BaseClass {
private:
    int privateMember;
protected:
    int protectedMember;
public:
    int publicMember;

    BaseClass() : privateMember(10), protectedMember(20), publicMember(30) {
        std::cout << "BaseClass constructor called." << std::endl;
    }

    // CORRECT PRACTICE: Virtual destructor for polymorphic base classes.
    // Ensures that the correct destructor is called when deleting a derived
    // object through a base class pointer, preventing resource leaks.
    virtual ~BaseClass() {
        std::cout << "BaseClass destructor called." << std::endl;
    }

    void displayBaseMembers() {
        std::cout << "--- BaseClass Context (from BaseClass member function) ---" << std::endl;
        std::cout << "  privateMember: " << privateMember << " (Accessible from BaseClass)" << std::endl;
        std::cout << "  protectedMember: " << protectedMember << " (Accessible from BaseClass)" << std::endl;
        std::cout << "  publicMember: " << publicMember << " (Accessible from BaseClass)" << std::endl;
    }
};

// DerivedClass definition
class DerivedClass : public BaseClass {
private:
    std::string derivedData;
public:
    DerivedClass() : derivedData("Derived data content.") {
        std::cout << "DerivedClass constructor called." << std::endl;
    }

    // Derived class destructor with 'override' keyword for clarity and compile-time checking
    ~DerivedClass() override {
        std::cout << "DerivedClass destructor called. Derived data: '" << derivedData << "' cleaned up." << std::endl;
    }

    void accessBaseMembersFromDerived() {
        std::cout << "\n--- DerivedClass Context (from DerivedClass member function) ---" << std::endl;
        // Attempt to access privateMember: This would be a compilation error if uncommented.
        // std::cout << "  privateMember: " << privateMember << std::endl;
        std::cout << "  privateMember: NOT PERMITTED (Compilation Error - private to BaseClass)" << std::endl;
        std::cout << "  protectedMember: " << protectedMember << " (PERMITTED - accessible in derived classes)" << std::endl;
        std::cout << "  publicMember: " << publicMember << " (PERMITTED - always accessible)" << std::endl;
    }
};

// main function to demonstrate access
int main() {
    std::cout << "--- Illustrating C++ Access Specifiers ---" << std::endl;

    // 1. Demonstrate access from BaseClass object
    std::cout << "\nCreating a BaseClass object..." << std::endl;
    BaseClass baseObj;
    baseObj.displayBaseMembers();

    std::cout << "\n--- External (main function) Context for BaseClass object ---" << std::endl;
    // Attempt to access privateMember: Compilation Error if uncommented
    // std::cout << "  baseObj.privateMember: " << baseObj.privateMember << std::endl;
    std::cout << "  baseObj.privateMember: NOT PERMITTED (Compilation Error - private)" << std::endl;
    // Attempt to access protectedMember: Compilation Error if uncommented
    // std::cout << "  baseObj.protectedMember: " << baseObj.protectedMember << std::endl;
    std::cout << "  baseObj.protectedMember: NOT PERMITTED (Compilation Error - protected)" << std::endl;
    std::cout << "  baseObj.publicMember: " << baseObj.publicMember << " (PERMITTED - public)" << std::endl;

    // 2. Demonstrate access from DerivedClass object
    std::cout << "\nCreating a DerivedClass object..." << std::endl;
    DerivedClass derivedObj;
    derivedObj.accessBaseMembersFromDerived();

    std::cout << "\n--- External (main function) Context for DerivedClass object ---" << std::endl;
    // Attempt to access privateMember (inherited): Compilation Error if uncommented
    // std::cout << "  derivedObj.privateMember: " << derivedObj.privateMember << std::endl;
    std::cout << "  derivedObj.privateMember: NOT PERMITTED (Compilation Error - private to BaseClass)" << std::endl;
    // Attempt to access protectedMember (inherited): Compilation Error from outside if uncommented
    // std::cout << "  derivedObj.protectedMember: " << derivedObj.protectedMember << std::endl;
    std::cout << "  derivedObj.protectedMember: NOT PERMITTED (Compilation Error - protected, not public)" << std::endl;
    std::cout << "  derivedObj.publicMember: " << derivedObj.publicMember << " (PERMITTED - public)" << std::endl;


    // 3. Demonstrate virtual destructor (Robustness improvement)
    std::cout << "\n--- Demonstrating Virtual Destructor (Good Practice) ---" << std::endl;
    BaseClass* polyPtr = new DerivedClass(); // Polymorphic creation
    // This will call BaseClass constructor, then DerivedClass constructor
    std::cout << "Deleting DerivedClass object via BaseClass pointer (with virtual destructor)..." << std::endl;
    delete polyPtr; // Calls DerivedClass destructor, then BaseClass destructor (correct behavior)

    std::cout << "\n--- Summary of Access Rules ---" << std::endl;
    std::cout << "1. private:   Accessible ONLY within the class where it is declared." << std::endl;
    std::cout << "              - Not accessible in derived classes." << std::cout << "              - Not accessible from outside the class (e.g., in main)." << std::endl;
    std::cout << "2. protected: Accessible within the class where it is declared AND from its derived classes." << std::endl;
    std::cout << "              - Not accessible from outside the class (e.g., in main)." << std::endl;
    std::cout << "3. public:    Accessible from ANYWHERE (within its class, derived classes, and outside the class)." << std::endl;

    return 0;
}