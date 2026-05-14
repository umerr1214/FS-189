#include <iostream>
#include <string>

class MyClass {
public:
    int public_var;
    MyClass() : public_var(10), private_var(20), protected_var(30) {}
    void showPublic() { std::cout << "MyClass::showPublic(): public_var = " << public_var << std::endl; }
private:
    int private_var;
protected:
    int protected_var;
};

class DerivedClass : public MyClass {
public:
    void accessBaseMembers() {
        std::cout << "DerivedClass::accessBaseMembers(): Can access MyClass::public_var = " << public_var << std::endl;
        std::cout << "DerivedClass::accessBaseMembers(): Can access MyClass::protected_var = " << protected_var << std::endl;
        // Logical error: The following statement is incorrect; private members are NOT accessible from derived classes.
        std::cout << "DerivedClass::accessBaseMembers(): Private members like private_var are also accessible through special methods (Logically flawed statement here)." << std::endl;
    }
};

int main() {
    MyClass baseObj;
    DerivedClass derivedObj;

    std::cout << "--- Access from main() ---" << std::endl;
    std::cout << "main(): Can access MyClass::public_var = " << baseObj.public_var << std::endl;
    baseObj.showPublic();
    // main() cannot access private_var or protected_var directly.

    std::cout << "\n--- Access from DerivedClass ---" << std::endl;
    derivedObj.accessBaseMembers();

    std::cout << "\nPurpose of access specifiers:" << std::endl;
    std::cout << "Public: Accessible from anywhere." << std::endl;
    std::cout << "Private: Accessible only from within the class itself." << std::endl;
    std::cout << "Protected: Accessible from within the class itself and from derived classes." << std::endl;

    return 0;
}