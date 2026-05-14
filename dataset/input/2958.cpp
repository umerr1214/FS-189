#include <iostream>
#include <string>

// Forward declaration of Tenant
class Tenant;

class Building {
private:
    // Semantic Error: Cannot declare a member of an incomplete type (Tenant) by value.
    // At this point, the compiler only knows that `Tenant` is a class, but not its size
    // or internal structure, which is required to allocate space for `owner` directly.
    Tenant owner; 
    std::string address;

public:
    // The constructor and setter signatures are also inconsistent with `owner` being an object,
    // as they expect a `Tenant*`. This adds to the semantic issues.
    Building(std::string addr, Tenant* t);
    void setOwner(Tenant* t);
    void displayBuildingInfo();
};

// Full definition of Tenant
class Tenant {
private:
    std::string name;
    int tenantId;

public:
    Tenant(std::string n, int id) : name(n), tenantId(id) {}
    std::string getName() const { return name; }
    int getId() const { return tenantId; }
};

// Building method definitions (these will also fail due to `owner` being an incomplete type
// at the point of Building's declaration, and type mismatch with the pointer parameters).
Building::Building(std::string addr, Tenant* t) : address(addr), owner(*t) {}

void Building::setOwner(Tenant* t) {
    owner = *t;
}

void Building::displayBuildingInfo() {
    std::cout << "Building Address: " << address << std::endl;
    // This line attempts to access members of `owner`, which is valid only after `Tenant`'s full definition,
    // but the primary error is at the member declaration.
    std::cout << "Owner: " << owner.getName() << " (ID: " << owner.getId() << ")" << std::endl;
}

int main() {
    Tenant tenant1("Alice Smith", 101);
    // This line will cause a compilation error due to the incomplete type of `Building::owner`.
    Building b1("123 Main St", &tenant1);
    b1.displayBuildingInfo();

    Tenant tenant2("Bob Johnson", 102);
    b1.setOwner(&tenant2);
    b1.displayBuildingInfo();

    return 0;
}