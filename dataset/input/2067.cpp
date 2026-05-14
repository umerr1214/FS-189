// 2067.cpp - Correct Version
#include <iostream> // Required for standard input/output operations.
#include <string>   // Not strictly needed for this example, but often useful.

// Base class definition with private, protected, and public members.
class Base {
private:
    int privateData;    // Accessible only within the Base class.
protected:
    int protectedData;  // Accessible within the Base class and its derived classes.
public:
    int publicData;     // Accessible from anywhere.

    // Constructor to initialize the data members.
    Base(int pvt, int prot, int pub)
        : privateData(pvt), protectedData(prot), publicData(pub) {}

    // Public method to display Base's data members.
    // This is the only way for external code to "see" privateData.
    void displayBaseData() const {
        std::cout << "Base::privateData (via Base method): " << privateData << std::endl;
        std::cout << "Base::protectedData (via Base method): " << protectedData << std::endl;
        std::cout << "Base::publicData (via Base method): " << publicData << std::endl;
    }

    // Public getter for privateData, demonstrating controlled access.
    int getPrivateData() const {
        return privateData;
    }
};

// Derived class publicly inheriting from Base.
class Derived : public Base {
public:
    // Constructor for Derived, calls Base's constructor.
    Derived(int pvt, int prot, int pub) : Base(pvt, prot, pub) {}

    // Method to demonstrate access to inherited members from within Derived.
    void accessBaseMembers() {
        std::cout << "\n--- Inside Derived::accessBaseMembers() ---" << std::endl;

        // 1. Accessing publicData: Allowed.
        std::cout << "Derived can access publicData: " << publicData << std::endl;
        publicData = 300; // Derived can modify publicData.
        std::cout << "Derived modified publicData to: " << publicData << std::endl;

        // 2. Accessing protectedData: Allowed.
        std::cout << "Derived can access protectedData: " << protectedData << std::endl;
        protectedData = 400; // Derived can modify protectedData.
        std::cout << "Derived modified protectedData to: " << protectedData << std::endl;

        // 3. Accessing privateData: NOT allowed directly.
        // Uncommenting the line below would result in a compile-time error.
        // std::cout << "Derived cannot directly access privateData: " << privateData << std::endl; // ERROR!
        std::cout << "Derived cannot directly access privateData. (Attempt commented out)" << std::endl;

        // Derived can access privateData via a public method inherited from Base.
        std::cout << "Derived can access privateData via Base's public method: " << getPrivateData() << std::endl;
    }
};

// Non-member function to demonstrate access from outside the class hierarchy.
void nonMemberFunctionAccess(Base& baseObj, Derived& derivedObj) {
    std::cout << "\n--- Inside nonMemberFunctionAccess() ---" << std::endl;

    // 1. Accessing publicData of Base object: Allowed.
    std::cout << "Non-member can access Base::publicData: " << baseObj.publicData << std::endl;
    baseObj.publicData = 500; // Non-member can modify publicData.
    std::cout << "Non-member modified Base::publicData to: " << baseObj.publicData << std::endl;

    // 2. Accessing publicData of Derived object: Allowed.
    std::cout << "Non-member can access Derived::publicData: " << derivedObj.publicData << std::endl;

    // 3. Accessing privateData of Base object: NOT allowed directly.
    // Uncommenting the line below would result in a compile-time error.
    // std::cout << "Non-member cannot directly access Base::privateData: " << baseObj.privateData << std::endl; // ERROR!
    std::cout << "Non-member cannot directly access Base::privateData. (Attempt commented out)" << std::endl;

    // 4. Accessing protectedData of Base object: NOT allowed directly.
    // Uncommenting the line below would result in a compile-time error.
    // std::cout << "Non-member cannot directly access Base::protectedData: " << baseObj.protectedData << std::endl; // ERROR!
    std::cout << "Non-member cannot directly access Base::protectedData. (Attempt commented out)" << std::endl;

    // Non-member can access privateData via a public method of Base.
    std::cout << "Non-member can access Base::privateData via Base's public method: " << baseObj.getPrivateData() << std::endl;
}

int main() {
    // Instantiate Base and Derived objects.
    Base baseObj(10, 20, 30);
    Derived derivedObj(11, 22, 33);

    // Display initial states.
    std::cout << "Initial Base object data:" << std::endl;
    baseObj.displayBaseData();
    std::cout << "\nInitial Derived object data:" << std::endl;
    derivedObj.displayBaseData(); // Derived inherits public methods like displayBaseData.

    // Demonstrate access from Derived class.
    derivedObj.accessBaseMembers();

    // Demonstrate access from a non-member function.
    nonMemberFunctionAccess(baseObj, derivedObj);

    // Display final states after all operations.
    std::cout << "\n--- After all operations ---" << std::endl;
    std::cout << "Final Base object data:" << std::endl;
    baseObj.displayBaseData();
    std::cout << "\nFinal Derived object data:" << std::endl;
    derivedObj.displayBaseData();

    return 0; // Indicate successful program execution.
}