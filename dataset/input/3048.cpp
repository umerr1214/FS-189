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

    void accessAndModifyData(int newData) {
        std::cout << "Derived class accessing protected data. Current data: " << data << std::endl;
        data = newData; // Direct access and modification
        std::cout << "Derived class modified protected data. New data: " << data << std::endl;
    }
};

// A non-member function
void nonMemberAccess(Base& obj) {
    // Semantic Error: The question asks to "demonstrate" why data cannot be accessed
    // from a non-member function. This function only *explains* the restriction,
    // but does not include any actual code (even commented-out) that attempts to
    // access 'data' directly and would result in a compile-time error.
    // By merely stating the rule without showing a problematic line, it semantically
    // fails to fulfill the "demonstrate" aspect of the question's requirement.
    std::cout << "\n--- Non-member function attempt ---" << std::endl;
    std::cout << "Explanation: The 'data' member is protected in the Base class." << std::endl;
    std::cout << "This means it can only be accessed by members of Base itself and its Derived classes." << std::endl;
    std::cout << "A non-member function, even if it has an object of Base or Derived, cannot directly access 'data'." << std::endl;
    std::cout << "Attempting to do so (e.g., 'obj.data = 100;') would result in a compile-time error due to access protection." << std::endl;
    std::cout << "--- End non-member function attempt ---\n" << std::endl;
}

int main() {
    Base b(10);
    Derived d(20);

    b.displayBaseData();
    d.accessAndModifyData(25); // Correctly modifies data
    d.displayBaseData(); // Should show derived object's data (inherited from Base)

    // Demonstrate non-member function restriction
    nonMemberAccess(b);

    return 0;
}