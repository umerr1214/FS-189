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

    // ROBUSTNESS ISSUE: Non-virtual destructor.
    // If a DerivedClass object is deleted through a BaseClass pointer,
    // only the BaseClass destructor will be called, leading to resource leaks
    // or undefined behavior if DerivedClass has its own resources.
    ~BaseClass() {
        std::cout << "BaseClass destructor called." << std::endl;
    }

    void displayBaseMembers() {
        std::cout << "--- BaseClass Context (from BaseClass member function) ---" << std::endl;
        std::cout << "BaseClass::privateMember: " << privateMember << " (Accessible from BaseClass)" << std::endl;
        std::cout << "BaseClass::protectedMember: " << protectedMember << " (Accessible from BaseClass)" << std::endl;
        std::cout << "BaseClass::publicMember: " << publicMember << " (Accessible from BaseClass)" << std::endl;
    }
};

// DerivedClass definition
class DerivedClass : public BaseClass {
private:
    std::string derivedData;
public:
    DerivedClass() : derivedData("I am derived data.") {
        std::cout << "DerivedClass constructor called." << std::endl;
    }

    ~DerivedClass() {
        std::cout << "DerivedClass destructor called. Derived data: '" << derivedData << "' cleaned up." << std::endl;
    }

    void accessBaseMembers() {
        std::cout << "\n--- DerivedClass Context (within member function) ---" << std::endl;
        // Attempt to access privateMember - compilation error if uncommented
        // std::cout << "DerivedClass attempting to access privateMember: " << privateMember << std::endl;
        std::cout << "DerivedClass attempting to access privateMember: NOT PERMITTED (Compilation Error)" << std::endl;
        std::cout << "DerivedClass attempting to access protectedMember: " << protectedMember << " (PERMITTED)" << std::endl;
        std::cout << "DerivedClass attempting to access publicMember: " << publicMember << " (PERMITTED)" << std::endl;
    }

    void displayDerivedData() {
        std::cout << "DerivedClass::derivedData: " << derivedData << std::endl;
    }
};

// main function to demonstrate access
int main() {
    std::cout << "--- Demonstrating Access Specifiers ---" << std::endl;

    // 1. Access from BaseClass object
    BaseClass baseObj;
    baseObj.displayBaseMembers();
    std::cout << "\n--- External (main function) Context for BaseClass ---" << std::endl;
    // Attempt to access privateMember from main - compilation error if uncommented
    // std::cout << "Accessing baseObj.privateMember: " << baseObj.privateMember << std::endl;
    // Attempt to access protectedMember from main - compilation error if uncommented
    // std::cout << "Accessing baseObj.protectedMember: " << baseObj.protectedMember << std::endl;
    std::cout << "Accessing baseObj.privateMember: NOT PERMITTED (Compilation Error)" << std::endl;
    std::cout << "Accessing baseObj.protectedMember: NOT PERMITTED (Compilation Error)" << std::endl;
    std::cout << "Accessing baseObj.publicMember: " << baseObj.publicMember << " (PERMITTED)" << std::endl;

    // 2. Access from DerivedClass object
    DerivedClass derivedObj;
    derivedObj.accessBaseMembers();
    std::cout << "\n--- External (main function) Context for DerivedClass ---" << std::endl;
    // Attempt to access privateMember from main - compilation error if uncommented
    // std::cout << "Accessing derivedObj.privateMember: " << derivedObj.privateMember << std::endl;
    // Attempt to access protectedMember from main - compilation error if uncommented
    // std::cout << "Accessing derivedObj.protectedMember: " << derivedObj.protectedMember << std::endl;
    std::cout << "Accessing derivedObj.privateMember: NOT PERMITTED (Compilation Error)" << std::endl;
    std::cout << "Accessing derivedObj.protectedMember: NOT PERMITTED (Compilation Error)" << std::endl;
    std::cout << "Accessing derivedObj.publicMember: " << derivedObj.publicMember << " (PERMITTED)" << std::endl;
    derivedObj.displayDerivedData();


    std::cout << "\n--- Demonstrating Robustness Issue: Non-virtual destructor ---" << std::endl;
    BaseClass* ptr = new DerivedClass(); // Create DerivedClass object, point to it with BaseClass pointer
    // This will call BaseClass constructor, then DerivedClass constructor
    // When 'delete ptr' is called, only BaseClass destructor will be invoked
    // leading to DerivedClass's destructor not being called and 'derivedData' not being "cleaned up"
    // This is undefined behavior and a common source of resource leaks in polymorphic hierarchies.
    std::cout << "Deleting DerivedClass object via BaseClass pointer..." << std::endl;
    delete ptr; // Only BaseClass destructor called. DerivedClass destructor is skipped.

    std::cout << "\nExplanation of Access Rules:" << std::endl;
    std::cout << "1. Private members: Accessible only from within the class where they are declared." << std::endl;
    std::cout << "   - Not accessible from derived classes." << std::endl;
    std::cout << "   - Not accessible from outside the class (e.g., in main function)." << std::endl;
    std::cout << "2. Protected members: Accessible from within the class where they are declared AND from derived classes." << std::endl;
    std::cout << "   - Not accessible from outside the class (e.g., in main function)." << std::endl;
    std::cout << "3. Public members: Accessible from anywhere (within the class, derived classes, and outside the class)." << std::endl;

    return 0;
}