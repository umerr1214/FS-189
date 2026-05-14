#include <iostream>
#include <string>
#include <utility> // For std::move

class SSD {
private: // These members are private
    int capacity; // in GB
    std::string type;

public:
    // Constructor
    SSD(int cap, std::string t) : capacity(cap), type(std::move(t)) {}

    // Only exposing type, not capacity, to set up the semantic error
    const std::string& getType() const { return type; }

    // For printing
    void printSSD() const {
        std::cout << "SSD: " << type << " " << capacity << "GB\n";
    }
};

class Laptop {
private:
    std::string brand;
    SSD internalSSD; // Composition

public:
    // Constructor for Laptop
    Laptop(std::string b, int ssd_capacity, std::string ssd_type)
        : brand(std::move(b)), internalSSD(ssd_capacity, std::move(ssd_type)) {}

    // Getters for demonstration/testing
    const std::string& getBrand() const { return brand; }
    const SSD& getSSD() const { return internalSSD; }

    // For printing
    void printLaptop() const {
        std::cout << "Laptop Brand: " << brand << "\n";
        internalSSD.printSSD();
    }
};

int main() {
    Laptop myLaptop("Dell", 512, "NVMe");
    myLaptop.printLaptop();

    // SEMANTIC ERROR: Attempting to access private member 'capacity' of 'SSD'
    // directly from main without a public getter. This violates encapsulation.
    std::cout << "Laptop 1 SSD Capacity (direct access attempt): " << myLaptop.getSSD().capacity << "GB\n";

    Laptop gamingLaptop("Alienware", 1024, "PCIe Gen4");
    gamingLaptop.printLaptop();

    return 0;
}