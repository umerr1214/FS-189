#include <iostream>

// Base class with private, protected, and public members
class Base // SYNTAX ERROR: Missing '{' here, should be 'class Base {'
    int privateData; // This line will be parsed as a global variable declaration
protected:
    int protectedData;
public:
    int publicData;

    // Constructor
    Base(int pvt, int prot, int pub) : privateData(pvt), protectedData(prot), publicData(pub) {}

    // Public getters to allow indirect access for demonstration
    int getPrivateData() const { return privateData; }
    int getProtectedData() const { return protectedData; }

    void displayBasePublic() const {
        std::cout << "Base publicData: " << publicData << std::endl;
    }
}; // Missing semicolon for class definition, but the primary error is the missing '{'

// Derived class
class Derived : public Base {
public:
    Derived(int pvt, int prot, int pub) : Base(pvt, prot, pub) {}

    void accessMembers() {
        std::cout << "\n--- Access from Derived Class ---" << std::endl;
        // Access publicData (allowed)
        std::cout << "Derived can access publicData: " << publicData << std::endl;
        // Access protectedData (allowed in Derived)
        std::cout << "Derived can access protectedData: " << protectedData << std::endl;
        // Access privateData (not allowed directly, but can be via public getter)
        std::cout << "Derived accesses privateData via public getter: " << getPrivateData() << std::endl;
    }
};

// Non-member function
void nonMemberFunction(Base& obj) {
    std::cout << "\n--- Access from Non-Member Function ---" << std::endl;
    // Access publicData (allowed)
    std::cout << "Non-member can access publicData: " << obj.publicData << std::endl;
    // Access protectedData (not allowed directly, but can be via public getter)
    std::cout << "Non-member accesses protectedData via public getter: " << obj.getProtectedData() << std::endl;
    // Access privateData (not allowed directly, but can be via public getter)
    std::cout << "Non-member accesses privateData via public getter: " << obj.getPrivateData() << std::endl;
}

int main() {
    Base b(10, 20, 30);
    Derived d(100, 200, 300);

    b.displayBasePublic();
    d.accessMembers();
    nonMemberFunction(b);
    nonMemberFunction(d);

    return 0;
}