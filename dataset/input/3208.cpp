#include <iostream>

class Base {
public:
    int public_member_base;
    Base() : public_member_base(1), protected_member_base(2), private_member_base(3) {}
    void displayPublic() {
        std::cout << "Base public_member_base: " << public_member_base << std::endl;
    }
protected:
    int protected_member_base;
    void displayProtected() {
        std::cout << "Base protected_member_base (from Base): " << protected_member_base << std::endl;
    }
private:
    int private_member_base;
    void displayPrivate() {
        std::cout << "Base private_member_base (from Base): " << private_member_base << std::endl;
    }
};

class Derived : public Base {
public:
    void accessBaseMembersFromDerived() {
        std::cout << "\n--- From Derived Class ---" << std::endl;
        std::cout << "Derived can access public_member_base: " << public_member_base << std::endl;
        displayPublic();
        std::cout << "Derived can access protected_member_base: " << protected_member_base << std::endl;
        displayProtected();
        // Private member from Base is NOT accessible in Derived
        std::cout << "Derived CANNOT access private_member_base directly." << std::endl;
        // displayPrivate(); // Would be a semantic error
    }
};

class External {
public:
    void accessBaseMembersFromExternal(Base& obj) {
        std::cout << "\n--- From External Class ---" << std::endl;
        std::cout << "External can access public_member_base: " << obj.public_member_base << std::endl;
        obj.displayPublic();
        // Protected and Private members from Base are NOT accessible in External
        std::cout << "External CANNOT access protected_member_base directly." << std::endl;
        std::cout << "External CANNOT access private_member_base directly." << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Base baseObj;
    Derived derivedObj;
    External externalObj;

    std::cout << "--- Base Object direct access ---" << std::endl;
    baseObj.displayPublic();

    derivedObj.accessBaseMembersFromDerived();
    externalObj.accessBaseMembersFromExternal(baseObj);

    return 0;
}