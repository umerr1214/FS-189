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

    BaseClass() : privateMember(10), protectedMember(20), publicMember(30) {}

    void displayBaseMembers() {
        std::cout << "BaseClass members (from BaseClass itself):" << std::endl;
        std::cout << "  Private: " << privateMember << std::endl;
        std::cout << "  Protected: " << protectedMember << std::endl;
        std::cout << "  Public: " << publicMember << std::endl;
    }

    int getPrivateMember() const { return privateMember; }
};

// DerivedClass definition
class DerivedClass : public BaseClass {
public:
    void accessBaseMembers() {
        std::cout << "\nDerivedClass attempting to access BaseClass members:" << std::endl;
        std::cout << "  Accessing publicMember (allowed): " << publicMember << std::endl;
        std::cout << "  Accessing protectedMember (allowed): " << protectedMember << std::endl;

        // Semantic Error: Attempting to access a private member directly from a derived class.
        // This will result in a compile-time error.
        std::cout << "  Accessing privateMember (NOT allowed directly from derived): " << privateMember << std::endl; // ERROR LINE
    }
};

int main() {
    std::cout << "Demonstrating C++ Access Specifiers (Semantic Error Example)\n" << std::endl;

    BaseClass baseObj;
    baseObj.displayBaseMembers();

    DerivedClass derivedObj;
    derivedObj.accessBaseMembers(); // This call will attempt the forbidden access, causing a compile error.

    std::cout << "\nFrom main() function:" << std::endl;
    std::cout << "  Accessing baseObj.publicMember (allowed): " << baseObj.publicMember << std::endl;
    std::cout << "  Attempting to access baseObj.protectedMember directly: NOT PERMITTED (semantic error if uncommented)" << std::endl;
    std::cout << "  Attempting to access baseObj.privateMember directly: NOT PERMITTED (semantic error if uncommented)" << std::endl;
    std::cout << "  Accessing baseObj.privateMember via public getter (allowed): " << baseObj.getPrivateMember() << std::endl;

    return 0;
}