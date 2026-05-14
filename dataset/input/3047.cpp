#include <iostream>

class Base {
protected:
    int data;
public:
    Base(int d) : data(d) {}
    void displayBaseData() const {
        std::cout << "Base data: " << data << std::endl;
    }
};

class Derived : public Base {
public:
    Derived(int d) : Base(d) {}

    // Logical Error: This method only accesses and prints 'data', but does not *modify* it
    // as explicitly requested by the question ("access and modify").
    void accessDataButNotModify() { 
        std::cout << "Derived class accessing protected data. Current data: " << data << std::endl;
        // data = newData; // The modification logic is missing here, making it a logical error.
    }
};

// A non-member function
void nonMemberAccess(Base& obj) {
    // This function correctly does not attempt to access 'obj.data' directly.
    // The explanation is present but could be more detailed about the 'protected' access rules
    // and how they specifically relate to inheritance vs. non-member functions.
    std::cout << "\n--- Non-member function attempt ---" << std::endl;
    std::cout << "A non-member function cannot directly access 'data'." << std::endl;
    std::cout << "This is because 'data' is a protected member of 'Base'." << std::endl;
    // obj.data = 100; // If uncommented, this would cause a compile-time error.
    std::cout << "Only members of 'Base' itself and its 'Derived' classes can access protected members." << std::endl;
    std::cout << "--- End non-member function attempt ---\n" << std::endl;
}

int main() {
    Base b(10);
    Derived d(20);

    b.displayBaseData();
    d.accessDataButNotModify(); // Calls the method with the logical flaw
    
    // Demonstrate non-member function restriction
    nonMemberAccess(b);

    // To highlight the logical error, we display the derived object's data again.
    // It will show that the data was not modified.
    std::cout << "After Derived::accessDataButNotModify(), Derived object's data: ";
    d.displayBaseData(); // Still 20, because accessDataButNotModify() didn't modify it.

    return 0;
}