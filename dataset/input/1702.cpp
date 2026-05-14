#include <iostream>

class BaseClass {
protected:
    int protectedVar;
private:
    int privateVar;

public:
    BaseClass() : protectedVar(10), privateVar(20) {}
    void printBaseVars() {
        std::cout << "BaseClass: protectedVar = " << protectedVar << ", privateVar = " << privateVar << std::endl;
    }
};

class DerivedClass : public BaseClass {
public:
    void accessBaseMembers() {
        // Accessing protectedVar (should be allowed)
        std::cout << "DerivedClass: Accessing protectedVar. Value = " << protectedVar << std::endl;

        // Showing that privateVar is inaccessible
        std::cout << "DerivedClass: privateVar is inaccessible from DerivedClass." << std::endl;
    }
} // ERROR: Missing semicolon here, causing a syntax error

int main() {
    DerivedClass d;
    d.accessBaseMembers();
    return 0;
}