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
        // Cannot access private_var here
    }
};

int main() {
    MyClass baseObj;
    DerivedClass derivedObj;

    std::cout << "--- Access from main() ---" << std::endl;
    std::cout << "main(): Can access MyClass::public_var = " << baseObj.public_var << std::endl;
    baseObj.showPublic();

    // Semantic error: Attempting to access a private member directly from main()
    std::cout << "main(): Trying to access MyClass::private_var = " << baseObj.private_var << std::endl;

    std::cout << "\n--- Access from DerivedClass ---" << std::endl;
    derivedObj.accessBaseMembers();

    std::cout << "\nPurpose of access specifiers:" << std::endl;
    std::cout << "Public: Accessible from anywhere." << std::endl;
    std::cout << "Private: Accessible only from within the class itself." << std::endl;
    std::cout << "Protected: Accessible from within the class itself and from derived classes." << std::endl;

    return 0;
}