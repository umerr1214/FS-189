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
        // Accessing public member (allowed)
        std::cout << "  Accessing publicMember (allowed): " << publicMember << std::endl;

        // Accessing protected member (allowed in derived class)
        std::cout << "  Accessing protectedMember (allowed): " << protectedMember << std::endl;

        // Logical error: Misleading explanation. It claims direct access is allowed,
        // but it's actually using a public getter. Direct access to privateMember
        // would be a semantic error. The explanation is logically flawed.
        std::cout << "  Accessing privateMember directly (allowed from derived): " << getPrivateMember() << std::endl;
    }
};

int main() {
    std::cout << "Demonstrating C++ Access Specifiers (Logical Error Example)\n" << std::endl;

    BaseClass baseObj;
    baseObj.displayBaseMembers();

    DerivedClass derivedObj;
    derivedObj.accessBaseMembers();

    std::cout << "\nFrom main() function:" << std::endl;
    std::cout << "  Accessing baseObj.publicMember (allowed): " << baseObj.publicMember << std::endl;
    // Logical error: Misleading explanation. It claims protected is allowed from main,
    // but prints the value of a public member. Direct access to protectedMember
    // from main would be a semantic error.
    std::cout << "  Accessing baseObj.protectedMember (allowed from main): " << baseObj.publicMember << std::endl;
    std::cout << "  Attempting to access baseObj.privateMember directly: NOT PERMITTED" << std::endl;
    std::cout << "  Accessing baseObj.privateMember via public getter (allowed): " << baseObj.getPrivateMember() << std::endl;

    return 0;
}