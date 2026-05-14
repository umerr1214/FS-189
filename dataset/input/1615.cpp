#include <iostream>
#include <string>

// Base class demonstrating access specifiers
class AccessDemo {
public:
    std::string publicData = "I am public data.";

    void displayPublicData() {
        std::cout << "Accessing public data from inside the class: " << publicData << std::endl;
        displayPrivateData(); // Can access private from inside
        displayProtectedData(); // Can access protected from inside
    }

private:
    std::string privateData = "I am private data.";

    void displayPrivateData() {
        std::cout << "Accessing private data from inside the class: " << privateData << std::endl;
    }

protected:
    std::string protectedData = "I am protected data.";

    void displayProtectedData() {
        std::cout << "Accessing protected data from inside the class: " << protectedData << std::endl;
    }
};

// Derived class to demonstrate protected access
class DerivedAccessDemo : public AccessDemo {
public:
    void accessBaseProtectedData() {
        std::cout << "Accessing protected data from derived class: " << protectedData << std::endl;
        // std::cout << privateData << std::endl; // ERROR: privateData is inaccessible
    }
};

int main() {
    std::cout << "--- Explanation of Access Specifiers ---" << std::endl;
    std::cout << "In C++, access specifiers (public, private, protected) control the visibility and accessibility of class members (data members and member functions)." << std::endl;

    std::cout << "\n1. Public:" << std::endl;
    std::cout << "   Public members are accessible from anywhere, both inside and outside the class. They form the interface of the class." << std::endl;

    std::cout << "\n2. Private:" << std::endl;
    std::cout << "   Private members are only accessible from within the class itself. They are hidden from outside the class and from derived classes. This is useful for internal implementation details." << std::endl;

    std::cout << "\n3. Protected:" << std::endl;
    std::cout << "   Protected members are accessible from within the class itself and from its derived classes. They are not accessible directly from outside the class (e.g., from main()), similar to private members." << std::endl;
    std::cout << "   This allows derived classes to interact with certain base class internals while keeping them hidden from the general public." << std::endl;

    std::cout << "\n--- Code Demonstration ---" << std::endl;

    AccessDemo baseObj;
    std::cout << "\nFrom main (AccessDemo object):" << std::endl;
    std::cout << "Public data directly accessible: " << baseObj.publicData << std::endl; // OK
    baseObj.displayPublicData(); // OK, calls internal methods

    // Attempting to access private/protected directly from main() would result in a compile-time error.
    // Uncommenting the lines below would prevent compilation:
    // std::cout << baseObj.privateData << std::endl; // ERROR
    // baseObj.displayPrivateData(); // ERROR
    // std::cout << baseObj.protectedData << std::endl; // ERROR
    // baseObj.displayProtectedData(); // ERROR

    DerivedAccessDemo derivedObj;
    std::cout << "\nFrom main (DerivedAccessDemo object):" << std::endl;
    std::cout << "Public data of derived object directly accessible: " << derivedObj.publicData << std::endl; // OK
    derivedObj.displayPublicData(); // OK, inherited public method
    derivedObj.accessBaseProtectedData(); // OK, derived class method accessing protected base member

    std::cout << "\nSummary:" << std::endl;
    std::cout << "Public: Accessible everywhere." << std::endl;
    std::cout << "Private: Accessible only within the defining class." << std::endl;
    std::cout << "Protected: Accessible within the defining class and its derived classes." << std::endl;

    return 0;
}