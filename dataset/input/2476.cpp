#include <iostream>
#include <string>

// BaseClass definition
class BaseClass
{ // Syntax Error: Missing semicolon here after class definition
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
}; // Correct semicolon here, but the one above the class body is missing.

// DerivedClass definition
class DerivedClass : public BaseClass {
public:
    void accessBaseMembers() {
        std::cout << "\nDerivedClass attempting to access BaseClass members:" << std::endl;
        std::cout << "  Accessing publicMember (allowed): " << publicMember << std::endl;
        std::cout << "  Accessing protectedMember (allowed): " << protectedMember << std::endl;
        std::cout << "  Attempting to access privateMember directly: NOT PERMITTED" << std::endl;
        std::cout << "  Accessing privateMember via public getter (allowed): " << getPrivateMember() << std::endl;
    }
};

int main() {
    std::cout << "Demonstrating C++ Access Specifiers (Syntax Error Example)\n" << std::endl;

    BaseClass baseObj;
    baseObj.displayBaseMembers();

    DerivedClass derivedObj;
    derivedObj.accessBaseMembers();

    std::cout << "\nFrom main() function:" << std::endl;
    std::cout << "  Accessing baseObj.publicMember (allowed): " << baseObj.publicMember << std::endl;
    std::cout << "  Attempting to access baseObj.protectedMember directly: NOT PERMITTED" << std::endl;
    std::cout << "  Attempting to access baseObj.privateMember directly: NOT PERMITTED" << std::endl;
    std::cout << "  Accessing baseObj.privateMember via public getter (allowed): " << baseObj.getPrivateMember() << std::endl;

    return 0;
}