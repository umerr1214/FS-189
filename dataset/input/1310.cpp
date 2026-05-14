#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::for_each

class Base {
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    // Virtual destructor is present, so polymorphic deletion works.
    // However, the way objects are managed in main() is inefficient/less readable.
    virtual ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
private:
    std::string name; // Simulate a resource with a name
public:
    Derived(const std::string& n = "UnnamedDerived") : Base(), name(n) {
        std::cout << "Derived Constructor (" << name << ")" << std::endl;
    }
    ~Derived() override {
        std::cout << "Derived Destructor (" << name << ")" << std::endl;
    }
};

void demonstrate_readability_efficiency_issue() {
    std::cout << "--- Demonstrating Readability/Efficiency Issue ---" << std::endl;
    std::cout << "Creating multiple objects and storing raw pointers in a vector:" << std::endl;
    
    // Issue: Using raw pointers in a container like std::vector<Base*>
    // This is less readable, error-prone (manual deletion required),
    // and less efficient than using smart pointers (e.g., std::vector<std::unique_ptr<Base>>).
    std::vector<Base*> objects;
    
    objects.push_back(new Derived("Object A"));
    objects.push_back(new Base());
    objects.push_back(new Derived("Object B"));

    std::cout << "\nObjects created. Now manually deleting them from the vector:" << std::endl;

    // Issue: Manual iteration and deletion.
    // While the virtual destructor ensures correct cleanup for each object,
    // this pattern is verbose and introduces opportunities for memory leaks
    // if deletion is forgotten or handled incorrectly (e.g., exceptions).
    for (Base* obj : objects) {
        delete obj; // Correctly calls virtual destructors due to 'virtual ~Base()'
    }
    objects.clear(); // Clear the now invalid pointers to prevent dangling pointer issues

    std::cout << "--- End Demonstration ---" << std::endl;
    std::cout << "Notice: Destructors were called correctly, but the code for managing these objects is verbose and error-prone." << std::endl;
}

int main() {
    demonstrate_readability_efficiency_issue();
    return 0;
}