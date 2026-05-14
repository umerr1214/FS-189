#include <iostream>
#include <string>
#include <utility> // For std::move

class SSD {
private:
    int capacity; // in GB
    std::string type;

public:
    // Constructor - LOGICAL ERROR: capacity is always initialized to 0
    SSD(int cap, std::string t) : capacity(0), type(std::move(t)) {} // Should be capacity(cap)

    // Getters for demonstration/testing
    int getCapacity() const { return capacity; }
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
    // Test Case 1
    Laptop myLaptop("Dell", 512, "NVMe");
    std::cout << "--- Laptop 1 ---\n";
    myLaptop.printLaptop(); // Expected: 512GB, Actual: 0GB

    // Test Case 2
    Laptop gamingLaptop("Alienware", 1024, "PCIe Gen4");
    std::cout << "--- Laptop 2 ---\n";
    gamingLaptop.printLaptop(); // Expected: 1024GB, Actual: 0GB

    return 0;
}