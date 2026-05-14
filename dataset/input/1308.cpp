#include <iostream>
#include <string>

class Base {
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    // Base destructor is NOT virtual, which is the root cause of the problem.
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor" << std::endl;
    }
    // Semantic error: Making Derived's destructor virtual, but Base's is not.
    // This does NOT achieve polymorphic deletion through a Base* pointer.
    // The 'virtual' keyword must be on the base class destructor for the fix to work.
    virtual ~Derived() { 
        std::cout << "Derived Destructor" << std::endl;
    }
};

void demonstrate_deletion_scenario(const std::string& description, Base* obj) {
    std::cout << "--- " << description << " ---" << std::endl;
    delete obj;
    std::cout << "------------------------------------------" << std::endl;
}

int main() {
    // Part 1: Demonstrate the problem (non-virtual base destructor)
    std::cout << "Demonstrating non-virtual destructor issue (Base destructor is not virtual):" << std::endl;
    Base* problem_ptr = new Derived();
    demonstrate_deletion_scenario("Deleting Derived via Base* (Problem)", problem_ptr);
    // Expected output: Base Constructor, Derived Constructor, Base Destructor (Derived Destructor skipped)

    std::cout << "\nAttempting to fix by making Derived destructor virtual (Semantic Error):" << std::endl;
    Base* fixed_ptr_attempt = new Derived();
    // Even though Derived's destructor is declared 'virtual', Base's is not.
    // Therefore, deleting through Base* still results in non-polymorphic behavior.
    demonstrate_deletion_scenario("Deleting Derived via Base* (Attempted Fix)", fixed_ptr_attempt);
    // Expected output: Base Constructor, Derived Constructor, Base Destructor (Derived Destructor still skipped)

    return 0;
}