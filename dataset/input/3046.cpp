#include <iostream>

class Base {
protected:
    int data;
public:
    Base(int d) : data(d) {}
    void displayBaseData() const {
        std::cout << "Base data: " << data << std::endl;
    }
}; // ERROR: Missing semicolon here, intentionally placed for syntax error demonstration

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
    // Attempting to access 'data' directly from a non-member function
    // This would result in a compile-time error: 'data' is protected
    // obj.data = 100; // If uncommented, this line would cause a compile error
    std::cout << "\n--- Non-member function attempt ---" << std::endl;
    std::cout << "Attempting non-member access to Base::data (would fail compilation if uncommented)." << std::endl;
    std::cout << "Protected members like 'data' cannot be accessed directly from non-member functions." << std::endl;
    std::cout << "--- End non-member function attempt ---\n" << std::endl;
}

int main() {
    Base b(10);
    Derived d(20);

    b.displayBaseData();
    d.accessAndModifyData(25);
    d.displayBaseData(); // Should show derived object's data (inherited from Base)

    // Demonstrate non-member function restriction
    nonMemberAccess(b);

    return 0;
}