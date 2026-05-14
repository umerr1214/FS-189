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
        // displayPrivate(); // Would be a semantic error if uncommented
    }
};

class External {
public:
    void accessBaseMembersFromExternal(Base& obj) {
        std::cout << "\n--- From External Class ---" << std::endl;
        std::cout << "External can access public_member_base: " << obj.public_member_base << std::endl;
        obj.displayPublic();
        // SEMANTIC ERROR: Attempting to access protected member from External class
        // 'protected_member_base' is a protected member of 'Base', and cannot be accessed
        // directly from an unrelated 'External' class instance.
        std::cout << "External attempting to access protected_member_base: " << obj.protected_member_base << std::endl;
        // obj.displayProtected(); // This would also be a semantic error
        std::cout << "External CANNOT access private_member_base directly." << std::endl;
        // obj.private_member_base; // Would also be a semantic error
    }
};

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