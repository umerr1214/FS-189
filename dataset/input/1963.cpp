#include <iostream>
#include <string>

// Base class MyClass
class MyClass {
public:
    int public_data_base;
protected:
    int protected_data_base;
private:
    int private_data_base;

public:
    // Constructor for MyClass
    MyClass(int pub, int prot, int priv)
        : public_data_base(pub), protected_data_base(prot), private_data_base(priv) {
        std::cout << "MyClass constructor called. Initialized with: " << pub << ", " << prot << ", " << priv << std::endl;
    }

    // Public method to display public and private data (private via getter)
    void showMyClassData() const {
        std::cout << "  MyClass Public Data (from within MyClass): " << public_data_base << std::endl;
        std::cout << "  MyClass Private Data (via getter): " << getPrivateDataBase() << std::endl;
    }

    // Public getter for private data (demonstrates internal access)
    int getPrivateDataBase() const {
        return private_data_base;
    }
};

// Derived class DerivedClass
class DerivedClass : public MyClass {
public:
    int public_data_derived;

    // Derived class constructor, explicitly calls base class constructor
    DerivedClass(int pub_base, int prot_base, int priv_base, int pub_derived)
        : MyClass(pub_base, prot_base, priv_base), public_data_derived(pub_derived) {
        std::cout << "DerivedClass constructor called. Derived public: " << pub_derived << std::endl;
    }

    // Method to demonstrate access to base class members from within DerivedClass
    void demonstrateDerivedAccess() const {
        std::cout << "\n*** Access from DerivedClass member function ***" << std::endl;
        std::cout << "  Can access MyClass::public_data_base: " << public_data_base << std::endl;
        std::cout << "  Can access MyClass::protected_data_base: " << protected_data_base << std::endl;
        // Attempting to access private_data_base directly will result in a compile-time error.
        // std::cout << "  Cannot access MyClass::private_data_base: " << private_data_base << std::endl; // Compile Error
        std::cout << "  Cannot directly access MyClass::private_data_base (compile-time error)." << std::endl;
        std::cout << "  DerivedClass's own public_data_derived: " << public_data_derived << std::endl;
    }

    // ROBUSTNESS ISSUE: A public method exposing a protected base member.
    // This design choice can weaken encapsulation. While it compiles and works,
    // it makes a 'protected' member effectively 'public' through the derived class's interface.
    int getProtectedBaseData() const {
        std::cout << "  Accessing MyClass::protected_data_base via public DerivedClass method." << std::endl;
        return protected_data_base;
    }
};

int main() {
    std::cout << "--- Robustness Issue Example: C++ Access Specifiers ---" << std::endl;

    // Create an object of MyClass
    MyClass myObject(10, 20, 30);
    std::cout << "\n*** Access from main (MyClass object) ***" << std::endl;
    std::cout << "  Accessing MyClass::public_data_base directly: " << myObject.public_data_base << std::endl;
    // Attempting to access protected_data_base directly will result in a compile-time error.
    // std::cout << "  Accessing MyClass::protected_data_base directly: " << myObject.protected_data_base << std::endl; // Compile Error
    std::cout << "  Cannot directly access MyClass::protected_data_base from main." << std::endl;
    // Attempting to access private_data_base directly will result in a compile-time error.
    // std::cout << "  Accessing MyClass::private_data_base directly: " << myObject.private_data_base << std::endl; // Compile Error
    std::cout << "  Cannot directly access MyClass::private_data_base from main." << std::endl;
    std::cout << "  Accessing MyClass::private_data_base via public getter: " << myObject.getPrivateDataBase() << std::endl;
    myObject.showMyClassData();

    // Create an object of DerivedClass
    DerivedClass derivedObject(100, 200, 300, 400);
    derivedObject.showMyClassData(); // Inherited public method
    derivedObject.demonstrateDerivedAccess(); // Derived class's own method

    std::cout << "\n*** Access from main (DerivedClass object) ***" << std::endl;
    std::cout << "  Accessing DerivedClass::public_data_base (inherited): " << derivedObject.public_data_base << std::endl;
    std::cout << "  Accessing DerivedClass::public_data_derived: " << derivedObject.public_data_derived << std::endl;
    // Attempting to access protected_data_base directly from derivedObject will result in a compile-time error.
    // std::cout << "  Accessing DerivedClass::protected_data_base: " << derivedObject.protected_data_base << std::endl; // Compile Error
    std::cout << "  Cannot directly access DerivedClass::protected_data_base from main." << std::endl;

    // ROBUSTNESS ISSUE DEMONSTRATION: Accessing protected base member via public derived method
    std::cout << "  Robustness Issue: Accessing protected_data_base via public DerivedClass::getProtectedBaseData(): "
              << derivedObject.getProtectedBaseData() << std::endl;

    std::cout << "\n--- End of Robustness Example ---" << std::endl;

    return 0;
}