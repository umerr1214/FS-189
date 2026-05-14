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
        // Logical Error: The actual value of protectedVar is 10, but the code prints an incorrect hardcoded value.
        std::cout << "DerivedClass: Accessing protectedVar. Value = " << 50 << std::endl; 
        
        // Showing that privateVar is inaccessible by stating it
        std::cout << "DerivedClass: privateVar is inaccessible from DerivedClass." << std::endl;
    }
};

int main() {
    DerivedClass d;
    d.accessBaseMembers();
    return 0;
}