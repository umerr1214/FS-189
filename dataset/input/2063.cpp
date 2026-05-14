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

    // Public getters to allow indirect access for demonstration
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
        // LOGICAL ERROR: Misrepresenting access to privateData.
        // It uses a public getter but claims "direct" access.
        std::cout << "Derived can *directly* access privateData: " << getPrivateData() << " (This statement is logically misleading)" << std::endl;
    }
};

// Non-member function
void nonMemberFunction(Base& obj) {
    std::cout << "\n--- Access from Non-Member Function ---" << std::endl;
    // Access publicData (allowed)
    std::cout << "Non-member can access publicData: " << obj.publicData << std::endl;
    // LOGICAL ERROR: Misrepresenting access to protectedData.
    // It uses a public getter but claims "direct" access.
    std::cout << "Non-member can *directly* access protectedData: " << obj.getProtectedData() << " (This statement is logically misleading)" << std::endl;
    // Correctly stated indirect access for privateData
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