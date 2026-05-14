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
        // LOGICAL ERROR: Misleading statement about private member accessibility
        // The following line implies accessibility without actual direct access,
        // which is incorrect according to C++ rules.
        std::cout << "Derived can access private_member_base: " << " (via some internal mechanism - value not shown)" << std::endl;
        // If uncommented, 'std::cout << private_member_base;' would be a semantic error.
    }
};

class External {
public:
    void accessBaseMembersFromExternal(Base& obj) {
        std::cout << "\n--- From External Class ---" << std::endl;
        std::cout << "External can access public_member_base: " << obj.public_member_base << std::endl;
        obj.displayPublic();
        // LOGICAL ERROR: Misleading statements about protected and private member accessibility
        // The following lines imply accessibility without actual direct access,
        // which is incorrect according to C++ rules.
        std::cout << "External can access protected_member_base: " << " (via some internal mechanism - value not shown)" << std::endl;
        // If uncommented, 'obj.protected_member_base;' would be a semantic error.
        std::cout << "External can access private_member_base: " << " (via some internal mechanism - value not shown)" << std::endl;
        // If uncommented, 'obj.private_member_base;' would be a semantic error.
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