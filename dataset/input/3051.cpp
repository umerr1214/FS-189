#include <iostream>

// Base class definition
class Base {
protected:
    int data; // Protected integer member

public:
    Base(int val = 0) : data(val) {
        std::cout << "Base object created with data: " << data << std::endl;
    }

    // Optional: A public getter for Base, primarily for demonstration purposes
    // (though Derived can access directly, a non-member function would need a public interface)
    int getData() const {
        return data;
    }
};

// Derived class definition, inheriting publicly from Base
class Derived : public Base {
public:
    Derived(int val = 0) : Base(val) {
        std::cout << "Derived object created." << std::endl;
    }

    // Method to demonstrate direct access and modification of 'data'
    void accessAndModifyData(int newValue) {
        std::cout << "\nDerived class method: 'accessAndModifyData(int newValue)'" << std::endl;
        std::cout << "Current 'data' value (from Derived): " << data << std::endl; // Direct access
        data = newValue; // Direct modification
        std::cout << "Modified 'data' value (from Derived): " << data << std::endl;
    }

    // A method to display the data, showing it's accessible within Derived
    void displayDataFromDerived() const {
        std::cout << "Derived class method: 'displayDataFromDerived()'" << std::endl;
        std::cout << "Data value from Derived: " << data << std::endl;
    }
};

// A non-member function attempting to access the protected 'data' member
void attemptNonMemberAccess(Derived& obj) {
    std::cout << "\nNon-member function: 'attemptNonMemberAccess(Derived& obj)'" << std::endl;
    std::cout << "Attempting to access 'obj.data' directly..." << std::endl;
    // The following line would cause a compilation error:
    // obj.data = 100; // ERROR: 'int Base::data' is protected within this context
    // std::cout << "Value of obj.data: " << obj.data << std::endl; // Also an error

    std::cout << "Explanation: 'data' is a protected member of the Base class." << std::endl;
    std::cout << "Protected members are accessible by member functions and friend functions/classes of Base, " << std::endl;
    std::cout << "and by member functions and friend functions/classes of classes derived from Base (like Derived)." << std::endl;
    std::cout << "However, 'attemptNonMemberAccess' is a standalone, non-member function. It is neither a member nor a friend of Base or Derived." << std::endl;
    std::cout << "Therefore, it cannot directly access 'obj.data'. It would need to use a public interface (like a getter/setter) provided by the Derived class (or Base, if it had one)." << std::endl;
    std::cout << "For example, to get the data, it would need: obj.getData() (if Derived provided one, or Base if it was public)." << std::endl;
}

int main() {
    std::cout << "--- Demonstrating Protected Member Access ---" << std::endl;

    // Create a Derived object
    Derived myDerivedObject(10);
    myDerivedObject.displayDataFromDerived();

    // Demonstrate direct access and modification from Derived class
    myDerivedObject.accessAndModifyData(25);
    myDerivedObject.displayDataFromDerived();

    // Demonstrate why non-member functions cannot access 'data'
    attemptNonMemberAccess(myDerivedObject);

    // To show that a non-member function *can* access it via a public interface:
    std::cout << "\nNon-member function can access via public interface (if available):" << std::endl;
    // Using Base's public getter (if Base had one, or Derived provides one)
    std::cout << "Value retrieved via public getter: " << myDerivedObject.getData() << std::endl;


    return 0;
}