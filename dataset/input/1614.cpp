#include <iostream>
#include <string>

class MyClass {
public:
    int publicVar;
    void publicMethod() {
        std::cout << "Public method called. publicVar = " << publicVar << std::endl;
        privateMethod(); // Accessible from within MyClass
        protectedMethod(); // Accessible from within MyClass or DerivedClass
    }

private:
    int privateVar;
    void privateMethod() {
        std::cout << "Private method called. privateVar = " << privateVar << std::endl;
    }

protected:
    int protectedVar;
    void protectedMethod() {
        std::cout << "Protected method called. protectedVar = " << protectedVar << std::endl;
    }

public:
    MyClass() : publicVar(10), privateVar(20), protectedVar(30) {}
};

class DerivedClass : public MyClass {
public:
    void accessProtectedMembers() {
        // Accessing protected members from derived class (correct demonstration)
        protectedVar = 35;
        std::cout << "Derived class accessing protectedVar: " << protectedVar << std::endl;
        protectedMethod();
    }
};

int main() {
    MyClass obj;
    obj.publicVar = 100;
    obj.publicMethod(); // This internally calls privateMethod and protectedMethod

    DerivedClass derivedObj;
    derivedObj.publicVar = 200;
    derivedObj.publicMethod(); // This also internally calls privateMethod and protectedMethod
    derivedObj.accessProtectedMembers();

    // SEMANTIC ERROR: The code snippet demonstrates public access and protected access
    // from a derived class, but it does not explicitly demonstrate the *restrictions*
    // of private and protected members by attempting to access them from unauthorized
    // scopes (e.g., directly from main()) and commenting out the resulting compilation errors.
    // This makes the demonstration semantically incomplete for the question, as it fails
    // to fully illustrate the 'difference' by showing where access is *not* allowed.
    // For example, it could have:
    // obj.privateVar = 1; // Would be a compile-time error
    // obj.protectedVar = 1; // Would be a compile-time error

    std::cout << "\nExplanation of access specifiers:" << std::endl;
    std::cout << "  public: Accessible from anywhere." << std::endl;
    std::cout << "  private: Accessible only from within the class itself." << std::endl;
    std::cout << "  protected: Accessible from within the class itself and from derived classes." << std::endl;

    return 0;
}