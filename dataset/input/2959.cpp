#include <iostream>
#include <string>
#include <memory> // Not strictly needed for this file, but good practice for C++ programs

// Forward declaration of Tenant
class Tenant;

class Building {
private:
    Tenant* owner; // Stores a pointer to Tenant
    std::string address;

public:
    // Constructor takes a raw pointer to a Tenant.
    // In this robustnes issue, Building assumes ownership but doesn't manage lifetime.
    Building(const std::string& addr, Tenant* initialOwner)
        : address(addr), owner(initialOwner) {
        std::cout << "Building at " << address << " constructed. Owner assigned." << std::endl;
    }

    // IMPORTANT: Missing a destructor to 'delete owner;'
    // This leads to a memory leak because Building takes ownership but doesn't free the memory.
    // ~Building() {
    //     std::cout << "Building at " << address << " destructed. Deleting owner." << std::endl;
    //     delete owner; // This line is intentionally omitted for the robustness issue
    // }

    void displayInfo() const; // Declaration only, definition below
};

// Full definition of Tenant
class Tenant {
private:
    std::string name;
    int tenantId;

public:
    Tenant(const std::string& n, int id) : name(n), tenantId(id) {}

    std::string getName() const { return name; }
    int getId() const { return tenantId; }
};

// Definition of Building::displayInfo, requiring the full Tenant definition
void Building::displayInfo() const {
    std::cout << "Building at address: " << address << std::endl;
    if (owner) {
        std::cout << "Owner: " << owner->getName() << " (ID: " << owner->getId() << ")" << std::endl;
    } else {
        std::cout << "No owner assigned." << std::endl;
    }
}

int main() {
    // Demonstrate the memory leak:
    // A Tenant object is allocated on the heap.
    Tenant* alice = new Tenant("Alice", 101);

    // A Building is created and "owns" this Tenant.
    // When 'myBuilding' goes out of scope, its destructor is called.
    // However, the Building class is missing a destructor to delete 'owner'.
    // Thus, the 'alice' Tenant object is never deleted, leading to a memory leak.
    {
        Building myBuilding("123 Main St", alice);
        myBuilding.displayInfo();
    } // myBuilding goes out of scope here, but 'alice' is leaked

    std::cout << "\nProgram finished. The Tenant object for 'Alice' was leaked." << std::endl;
    // To fix the leak, we would need to manually delete alice here,
    // or, more correctly, have Building manage its lifetime.
    // delete alice; // If this line is added, the leak is prevented, but it shows the issue of manual management.

    return 0;
}