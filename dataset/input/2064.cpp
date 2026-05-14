#include <iostream>

// Base class with private, protected, and public members
class Base {
private:
    int privateData;
protected:
    int protectedData;
public:
    int publicData;

    // Constructor
    Base(int pvt, int prot, int pub) : privateData(pvt), protectedData(prot), publicData(pub) {}

    // Public getters (not used in error demonstration, but good practice)
    int getPrivateData() const { return privateData; }
    int getProtectedData() const { return protectedData; }

    void displayBasePublic() const {
        std::cout << "Base publicData: " << publicData << std::endl;
    }
};

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
        // SEMANTIC ERROR: Attempt to access privateData directly from Derived
        std::cout << "Derived attempts to access privateData: " << privateData << std::endl; // Compiler error: 'privateData' is private
    }
};

// Non-member function
void nonMemberFunction(Base& obj) {
    std::cout << "\n--- Access from Non-Member Function ---" << std::endl;
    // Access publicData (allowed)
    std::cout << "Non-member can access publicData: " << obj.publicData << std::endl;
    // SEMANTIC ERROR: Attempt to access protectedData directly from a non-member function
    std::cout << "Non-member attempts to access protectedData: " << obj.protectedData << std::endl; // Compiler error: 'protectedData' is protected
    // SEMANTIC ERROR: Attempt to access privateData directly from a non-member function
    std::cout << "Non-member attempts to access privateData: " << obj.privateData << std::endl; // Compiler error: 'privateData' is private
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