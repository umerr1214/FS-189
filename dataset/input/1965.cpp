#include <iostream> // Required for input/output operations
#include <string>   // Required for string manipulation, though not heavily used here

// Base class: MyClass
// Demonstrates public, protected, and private members
class MyClass {
public: // Accessible from anywhere
    int publicMember;

protected: // Accessible from MyClass itself, and from derived classes
    int protectedMember;

private: // Accessible only from within MyClass
    int privateMember;

public:
    // Constructor to initialize all members
    MyClass(int pub, int prot, int priv)
        : publicMember(pub), protectedMember(prot), privateMember(priv) {
        std::cout << "MyClass constructor called with: " << publicMember << ", "
                  << protectedMember << ", " << privateMember << '\n';
    }

    // Public method to display public and private members (private via a getter)
    void displayMyClassData() const {
        std::cout << "  MyClass Data (from within MyClass):\n";
        std::cout << "    Public Member: " << publicMember << '\n';
        std::cout << "    Protected Member: " << protectedMember << '\n'; // Accessible within MyClass
        std::cout << "    Private Member (via public getter): " << getPrivateMember() << '\n';
    }

    // Public getter method for the private member
    int getPrivateMember() const {
        return privateMember;
    }
};

// Derived class: DerivedClass
// Inherits publicly from MyClass
class DerivedClass : public MyClass {
public:
    int derivedPublicMember;

    // Constructor for DerivedClass, explicitly calling the base class constructor
    DerivedClass(int basePub, int baseProt, int basePriv, int derivedPub)
        : MyClass(basePub, baseProt, basePriv), derivedPublicMember(derivedPub) {
        std::cout << "DerivedClass constructor called. Derived public member: " << derivedPublicMember << '\n';
    }

    // Method to demonstrate access to base class members from within DerivedClass
    void demonstrateDerivedAccess() const {
        std::cout << "\n--- Access from DerivedClass member function (`demonstrateDerivedAccess`) ---\n";
        // Public members of MyClass are accessible
        std::cout << "  Derived can access MyClass::publicMember: " << publicMember << '\n';

        // Protected members of MyClass are accessible
        std::cout << "  Derived can access MyClass::protectedMember: " << protectedMember << '\n';

        // Private members of MyClass are NOT accessible (compile-time error)
        // std::cout << "  Derived cannot directly access MyClass::privateMember: " << privateMember << '\n'; // This line would cause a compile error
        std::cout << "  Derived cannot directly access MyClass::privateMember (compile-time error).\n";

        // DerivedClass's own public member is accessible
        std::cout << "  DerivedClass's own publicMember: " << derivedPublicMember << '\n';
    }
};

int main() {
    std::cout << "--- Correct Version: C++ Access Specifiers (public, private, protected) ---\n";

    // 1. Demonstrating access with a MyClass object
    MyClass baseObject(10, 20, 30);
    std::cout << "\n--- Access from main (MyClass object `baseObject`) ---\n";

    // Public member: Directly accessible
    std::cout << "  main can access MyClass::publicMember directly: " << baseObject.publicMember << '\n';

    // Protected member: Not directly accessible from outside the class or its derived classes (compile-time error)
    // std::cout << "  main cannot access MyClass::protectedMember directly: " << baseObject.protectedMember << '\n'; // This line would cause a compile error
    std::cout << "  main cannot directly access MyClass::protectedMember (compile-time error).\n";

    // Private member: Not directly accessible from outside the class (compile-time error)
    // std::cout << "  main cannot access MyClass::privateMember directly: " << baseObject.privateMember << '\n'; // This line would cause a compile error
    std::cout << "  main cannot directly access MyClass::privateMember (compile-time error).\n";

    // Accessing private member via a public getter method
    std::cout << "  main can access MyClass::privateMember via public getter: " << baseObject.getPrivateMember() << '\n';
    baseObject.displayMyClassData(); // Calls a public method to show internal data

    // 2. Demonstrating access with a DerivedClass object
    DerivedClass derivedObject(100, 200, 300, 400);
    std::cout << "\n--- Access from main (DerivedClass object `derivedObject`) ---\n";

    // Inherited public member: Directly accessible
    std::cout << "  main can access DerivedClass::publicMember (inherited from MyClass): " << derivedObject.publicMember << '\n';
    // Derived class's own public member: Directly accessible
    std::cout << "  main can access DerivedClass::derivedPublicMember: " << derivedObject.derivedPublicMember << '\n';

    // Inherited protected member: Not directly accessible from outside (compile-time error)
    // std::cout << "  main cannot access DerivedClass::protectedMember (inherited): " << derivedObject.protectedMember << '\n'; // This line would cause a compile error
    std::cout << "  main cannot directly access DerivedClass::protectedMember (inherited, compile-time error).\n";

    // Inherited private member: Not directly accessible from outside (compile-time error)
    // std::cout << "  main cannot access DerivedClass::privateMember (inherited): " << derivedObject.privateMember << '\n'; // This line would cause a compile error
    std::cout << "  main cannot directly access DerivedClass::privateMember (inherited, compile-time error).\n";

    derivedObject.displayMyClassData();     // Calls inherited public method
    derivedObject.demonstrateDerivedAccess(); // Calls derived class's own public method

    std::cout << "\n--- End of Demonstration ---\n";

    return 0;
}