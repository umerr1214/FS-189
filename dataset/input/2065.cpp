// 2065.cpp - Robustness Issue
#include <iostream>
#include <string>

// Base class with different access specifiers
class Base {
private:
    int privateData;
protected:
    int protectedData;
public:
    int publicData;

    Base(int pvt, int prot, int pub)
        : privateData(pvt), protectedData(prot), publicData(pub) {}

    void displayBaseData() const {
        std::cout << "Base::privateData (via Base method): " << privateData << std::endl;
        std::cout << "Base::protectedData (via Base method): " << protectedData << std::endl;
        std::cout << "Base::publicData (via Base method): " << publicData << std::endl;
    }

    // A method to get privateData for display, demonstrating indirect access.
    int getPrivateDataForDisplay() const {
        return privateData;
    }
};

// Derived class publicly inheriting from Base
class Derived : public Base {
public:
    Derived(int pvt, int prot, int pub) : Base(pvt, prot, pub) {}

    // Robustness Issue: Exposing protectedData via a non-const reference.
    // This allows external functions (like non-member functions if they get a Derived object)
    // to modify protectedData directly, bypassing any potential validation Base might want to enforce.
    int& getProtectedDataRef() {
        std::cout << "Derived::getProtectedDataRef() returning reference to protectedData." << std::endl;
        return protectedData;
    }

    void accessBaseMembers() {
        std::cout << "\n--- Inside Derived::accessBaseMembers() ---" << std::endl;
        // Accessing publicData (allowed)
        std::cout << "Derived can access publicData: " << publicData << std::endl;

        // Accessing protectedData (allowed)
        std::cout << "Derived can access protectedData: " << protectedData << std::endl;
        protectedData = 200; // Modifying protectedData directly - no validation
        std::cout << "Derived modified protectedData to: " << protectedData << std::endl;

        // Accessing privateData (not allowed - would be a compile error if uncommented)
        // std::cout << "Derived cannot access privateData directly." << std::endl;
        // std::cout << privateData << std::endl; // ERROR: 'privateData' is private
        std::cout << "Derived cannot directly access privateData. (Attempt commented out)" << std::endl;

        // Can access privateData via a public Base method (if one exists)
        std::cout << "Derived can access privateData via Base's public method: " << getPrivateDataForDisplay() << std::endl;
    }
};

// Non-member function trying to access members
void nonMemberFunctionAccess(Base& baseObj, Derived& derivedObj) {
    std::cout << "\n--- Inside nonMemberFunctionAccess() ---" << std::endl;

    // Accessing publicData of Base object (allowed)
    std::cout << "Non-member can access Base::publicData: " << baseObj.publicData << std::endl;
    baseObj.publicData = 1000; // Modifying publicData
    std::cout << "Non-member modified Base::publicData to: " << baseObj.publicData << std::endl;

    // Accessing publicData of Derived object (allowed)
    std::cout << "Non-member can access Derived::publicData: " << derivedObj.publicData << std::endl;

    // Accessing privateData (not allowed - would be a compile error if uncommented)
    // std::cout << "Non-member cannot access Base::privateData directly." << std::endl;
    // std::cout << baseObj.privateData << std::endl; // ERROR: 'privateData' is private
    std::cout << "Non-member cannot directly access Base::privateData. (Attempt commented out)" << std::endl;

    // Accessing protectedData (not allowed - would be a compile error if uncommented)
    // std::cout << "Non-member cannot access Base::protectedData directly." << std::endl;
    // std::cout << baseObj.protectedData << std::endl; // ERROR: 'protectedData' is protected
    std::cout << "Non-member cannot directly access Base::protectedData. (Attempt commented out)" << std::endl;

    // Robustness Issue demonstration:
    // Using the Derived class's getProtectedDataRef() method to modify protectedData.
    // This bypasses Base's encapsulation for protectedData.
    std::cout << "\nRobustness Issue: Using Derived::getProtectedDataRef() to modify protectedData externally." << std::endl;
    int& protRef = derivedObj.getProtectedDataRef();
    protRef = 999; // Directly modifying protectedData of derivedObj through a reference
    std::cout << "Non-member modified Derived::protectedData via reference to: " << derivedObj.protectedData << std::endl;

    // Accessing Base's privateData via its public method
    std::cout << "Non-member can access Base::privateData via Base's public method: " << baseObj.getPrivateDataForDisplay() << std::endl;
}

int main() {
    Base baseObj(10, 20, 30);
    Derived derivedObj(11, 22, 33);

    std::cout << "Initial Base object data:" << std::endl;
    baseObj.displayBaseData();
    std::cout << "\nInitial Derived object data:" << std::endl;
    derivedObj.displayBaseData(); // Derived inherits Base's public methods

    derivedObj.accessBaseMembers();
    nonMemberFunctionAccess(baseObj, derivedObj);

    std::cout << "\n--- After all operations ---" << std::endl;
    std::cout << "Final Base object data:" << std::endl;
    baseObj.displayBaseData();
    std::cout << "\nFinal Derived object data:" << std::endl;
    derivedObj.displayBaseData();

    return 0;
}