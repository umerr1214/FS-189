#include <iostream>
#include <string>

class MyClass {
public:
    int publicVar;
    void publicMethod() {
        std::cout << "Public method called. publicVar = " << publicVar << std::endl;
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
    MyClass() : publicVar(1), privateVar(2), protectedVar(3) {}
};

class DerivedClass : public MyClass {
public:
    void accessProtectedAndPrivate() {
        // Accessing protected members (correct demonstration)
        protectedVar = 30;
        std::cout << "Derived class accessing protectedVar: " << protectedVar << std::endl;
        protectedMethod();

        // Attempting to access private members would cause a compile error:
        // privateVar = 20;
        // privateMethod();
    }
};

int main() {
    MyClass obj;
    obj.publicVar = 100;
    obj.publicMethod();

    DerivedClass derivedObj;
    derivedObj.publicVar = 200;
    derivedObj.publicMethod();
    derivedObj.accessProtectedAndPrivate();

    std::cout << "\nDemonstration of access specifiers:" << std::endl;
    std::cout << "  public: Accessible from anywhere." << std::endl;
    std::cout << "  private: Accessible only from within the class itself." << std::endl;
    // LOGICAL ERROR: The explanation for protected is incorrect here.
    std::cout << "  protected: Accessible only from within the class itself, just like private." << std::endl;

    return 0;
}