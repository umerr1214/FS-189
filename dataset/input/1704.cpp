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

        // Semantic Error: Attempting to access privateVar (a private member of BaseClass)
        // This line will cause a compile-time semantic error, demonstrating its inaccessibility.
        std::cout << "DerivedClass: Attempting to access privateVar. Value = " << privateVar << std::endl; 
    }
};

int main() {
    DerivedClass d;
    d.accessBaseMembers();
    return 0;
}