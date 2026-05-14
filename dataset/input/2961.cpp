#include <iostream>
#include <string>
#include <memory> // Required for std::unique_ptr and std::make_unique
#include <utility> // Required for std::move

// Forward declaration of Tenant
class Tenant;

class Building {
private:
    std::unique_ptr<Tenant> owner; // Stores an exclusive owner (unique_ptr)
    std::string address;

public:
    // Constructor takes a unique_ptr by rvalue reference, signifying transfer of ownership.
    // This correctly demonstrates how Building takes exclusive ownership of the Tenant.
    Building(const std::string& addr, std::unique_ptr<Tenant> initialOwner)
        : address(addr), owner(std::move(initialOwner)) {
        std::cout << "Building at " << address << " constructed. Ownership transferred." << std::endl;
    }

    // Default move constructor and move assignment operator are implicitly generated
    // or can be explicitly defaulted. Copy operations are deleted due to unique_ptr.
    Building(Building&&) = default;
    Building& operator=(Building&&) = default;
    // Destructor is implicitly handled by std::unique_ptr, which calls delete on its managed object.
    ~Building() {
        std::cout << "Building at " << address << " destructed." << std::endl;
    }

    void displayInfo() const; // Declaration only, definition below
};

// Full definition of Tenant
class Tenant {
private:
    std::string name;
    int tenantId;

public:
    Tenant(const std::string& n, int id) : name(n), tenantId(id) {
        std::cout << "Tenant '" << name << "' (ID: " << id << ") constructed." << std::endl;
    }
    ~Tenant() {
        std::cout << "Tenant '" << name << "' (ID: " << tenantId << ") destructed." << std::endl;
    }

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
    // Create a Tenant using make_unique.
    // This creates a unique_ptr that exclusively owns the Tenant object.
    std::unique_ptr<Tenant> charlie = std::make_unique<Tenant>("Charlie", 303);

    // Create a Building, transferring ownership of the Tenant from 'charlie' to 'myBuilding'.
    // After this line, 'charlie' unique_ptr becomes null.
    {
        Building myBuilding("789 Pine St", std::move(charlie));
        myBuilding.displayInfo();
        std::cout << "Is charlie unique_ptr null after move? " << (charlie == nullptr ? "Yes" : "No") << std::endl;
    } // myBuilding goes out of scope here. Its unique_ptr member 'owner' will delete the Tenant object.

    std::cout << "\nProgram finished. Tenant object for 'Charlie' was properly destructed." << std::endl;

    return 0;
}