#include <iostream>
#include <string>
#include <memory> // Required for std::shared_ptr and std::make_shared

// Forward declaration of Tenant
class Tenant;

class Building {
private:
    std::shared_ptr<Tenant> owner; // Stores a shared pointer to Tenant
    std::string address;

public:
    // Constructor takes a shared_ptr.
    // Using shared_ptr for unique ownership is an efficiency/readability issue.
    Building(const std::string& addr, std::shared_ptr<Tenant> initialOwner)
        : address(addr), owner(initialOwner) {
        std::cout << "Building at " << address << " constructed." << std::endl;
    }

    // Destructor is implicitly handled by std::shared_ptr, correctly freeing memory
    // when the last shared_ptr goes out of scope.

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
    // Create a Tenant using make_shared
    std::shared_ptr<Tenant> bob = std::make_shared<Tenant>("Bob", 202);

    // Create a Building, passing the shared_ptr.
    // Although functionally correct, using shared_ptr when unique_ptr would suffice
    // for exclusive ownership introduces unnecessary overhead (atomic reference counting)
    // and might obscure the intent of unique ownership.
    Building myBuilding("456 Oak Ave", bob);
    myBuilding.displayInfo();

    // The 'bob' shared_ptr still exists here, so the Tenant object is not yet destroyed.
    // This demonstrates shared ownership, but if Building is truly the sole owner,
    // unique_ptr would be more appropriate and efficient.
    std::cout << "\nBob's shared_ptr still exists, Tenant object is alive." << std::endl;

    return 0;
}