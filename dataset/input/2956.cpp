#include <iostream>
#include <string>

// Forward declaration of Tenant
class Tenant;

class Building {
private:
    Tenant* owner;
    std::string address;

public:
    Building(std::string addr, Tenant* t);
    // No explicit destructor needed if Tenant objects are managed externally
    void setOwner(Tenant* t);
    void displayBuildingInfo();
}; // Syntax Error: Missing semicolon here

class Tenant {
private:
    std::string name;
    int tenantId;

public:
    Tenant(std::string n, int id) : name(n), tenantId(id) {}
    std::string getName() const { return name; }
    int getId() const { return tenantId; }
};

// Building method definitions (require full Tenant definition)
Building::Building(std::string addr, Tenant* t) : address(addr), owner(t) {}

void Building::setOwner(Tenant* t) {
    owner = t;
}

void Building::displayBuildingInfo() {
    std::cout << "Building Address: " << address << std::endl;
    if (owner) {
        std::cout << "Owner: " << owner->getName() << " (ID: " << owner->getId() << ")" << std::endl;
    } else {
        std::cout << "Owner: Not assigned" << std::endl;
    }
}

int main() {
    Tenant tenant1("Alice Smith", 101);
    Building b1("123 Main St", &tenant1);
    b1.displayBuildingInfo();

    Tenant tenant2("Bob Johnson", 102);
    b1.setOwner(&tenant2);
    b1.displayBuildingInfo();

    return 0;
}