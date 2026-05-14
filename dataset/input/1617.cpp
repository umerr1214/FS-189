#include <iostream>
#include <string>

// A simple class to demonstrate C++ access specifiers: public, private, and protected.
class AccessSpecifierDemo {
public:
    // Public members are accessible from anywhere.
    std::string publicMember = "This is a public string.";

    void displayPublicMember() {
        std::cout << "  (Inside class) Public member: " << publicMember << std::endl;
        displayPrivateMember();   // Can call private member from inside
        displayProtectedMember(); // Can call protected member from inside
    }

private:
    // Private members are only accessible from within the class itself.
    std::string privateMember = "This is a private string.";

    void displayPrivateMember() {
        std::cout << "  (Inside class) Private member: " << privateMember << std::endl;
    }

protected:
    // Protected members are accessible from within the class and its derived classes.
    std::string protectedMember = "This is a protected string.";

    void displayProtectedMember() {
        std::cout << "  (Inside class) Protected member: " << protectedMember << std::endl;
    }
};

// A derived class to specifically demonstrate protected member access.
class DerivedDemo : public AccessSpecifierDemo {
public:
    void accessProtectedFromDerived() {
        std::cout << "  (Inside derived class) Accessing protected member: " << protectedMember << std::endl;
        // Cannot access privateMember here:
        // std::cout << privateMember << std::endl; // Compile-time ERROR: 'privateMember' is private
    }
};

int main() {
    std::cout << "--- Explanation of C++ Access Specifiers ---" << std::endl;
    std::cout << "Access specifiers (public, private, protected) define the accessibility of class members." << std::endl;

    std::cout << "\n1. Public:" << std::endl;
    std::cout << "   - Members declared as 'public' are accessible from anywhere: inside the class, from derived classes, and from objects outside the class (e.g., in main())." << std::endl;
    std::cout << "   - They form the public interface of the class." << std::endl;

    std::cout << "\n2. Private:" << std::endl;
    std::cout << "   - Members declared as 'private' are only accessible from within the class itself." << std::endl;
    std::cout << "   - They are hidden from outside the class and from derived classes, used for internal implementation details." << std::endl;

    std::cout << "\n3. Protected:" << std::endl;
    std::cout << "   - Members declared as 'protected' are accessible from within the class itself and from its derived classes." << std::endl;
    std::cout << "   - They are NOT accessible directly from objects outside the class (similar to private members)." << std::endl;
    std::cout << "   - This provides a way for derived classes to interact with base class internals while maintaining encapsulation from the outside world." << std::endl;

    std::cout << "\n--- Code Demonstration ---" << std::endl;

    AccessSpecifierDemo baseObject;
    std::cout << "\nAccessing members from main() (using a base class object):" << std::endl;
    std::cout << "  Public member directly accessible: " << baseObject.publicMember << std::endl; // OK
    baseObject.displayPublicMember(); // OK, calls public method which in turn accesses private/protected

    // Attempting to access private or protected members directly from main() will result in a compile-time error:
    // std::cout << baseObject.privateMember << std::endl;   // COMPILE ERROR: 'privateMember' is private
    // baseObject.displayPrivateMember();                    // COMPILE ERROR: 'displayPrivateMember' is private
    // std::cout << baseObject.protectedMember << std::endl; // COMPILE ERROR: 'protectedMember' is protected
    // baseObject.displayProtectedMember();                  // COMPILE ERROR: 'displayProtectedMember' is protected
    std::cout << "  (Attempting to access private/protected members directly from main() would cause compile errors.)" << std::endl;


    DerivedDemo derivedObject;
    std::cout << "\nAccessing members from main() (using a derived class object):" << std::endl;
    std::cout << "  Public member (inherited) directly accessible: " << derivedObject.publicMember << std::endl; // OK
    derivedObject.displayPublicMember(); // OK, inherited public method
    derivedObject.accessProtectedFromDerived(); // OK, derived method accesses protected base member

    std::cout << "\n--- Summary ---" << std::endl;
    std::cout << "Public: Accessible everywhere." << std::endl;
    std::cout << "Private: Accessible only within the defining class." << std::endl;
    std::cout << "Protected: Accessible within the defining class and its derived classes." << std::endl;

    return 0;
}