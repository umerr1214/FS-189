#include <iostream>
#include <string>

class MyClass {
public:
    int publicVar;
    void publicMethod() {
        std::cout << "Public method called." << std::endl;
    }

private:
    int privateVar;
    void privateMethod() {
        std::cout << "Private method called." << std::endl;
    }

protected:
    int protectedVar;
    void protectedMethod() {
        std::cout << "Protected method called." << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

class DerivedClass : public MyClass {
public:
    void accessProtected() {
        protectedVar = 20;
        std::cout << "Derived class accessing protectedVar: " << protectedVar << std::endl;
        protectedMethod();
    }
};

int main() {
    // This part of the code is intended to demonstrate usage but will not compile
    // due to the syntax error above.
    // MyClass obj;
    // obj.publicVar = 100;
    // obj.publicMethod();

    // DerivedClass derivedObj;
    // derivedObj.publicVar = 200;
    // derivedObj.publicMethod();
    // derivedObj.accessProtected();

    std::cout << "Program contains a syntax error and cannot execute fully." << std::endl;

    return 0;
}