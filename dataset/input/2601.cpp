#include <iostream>
#include <string>
#include <utility> // For std::move

// ERROR TYPE: Correct Version
// This version demonstrates best practices for C++ inheritance:
// 1. Virtual destructors in base classes to ensure proper polymorphic cleanup.
// 2. Use of constructor initializer lists for efficient member initialization.
// 3. Use of `std::move` for string parameters passed by value to constructors for efficiency.
// 4. Const correctness for methods that do not modify the object's state.
// 5. Use of '\n' instead of `std::endl` for better performance (avoids flushing the buffer).
// 6. Proper encapsulation (`private` attributes, `public` methods).
// 7. Clear and consistent formatting.

class Electronics {
private:
    double powerConsumption;
    std::string manufacturer;

public:
    // Constructor using initializer list and std::move for efficiency with string
    Electronics(double pc, std::string m)
        : powerConsumption(pc), manufacturer(std::move(m)) {}

    virtual ~Electronics() = default; // Virtual destructor for proper polymorphic cleanup

    // const-correctness: method does not modify object state
    void displayElectronicsDetails() const {
        std::cout << "Electronics Details:\n";
        std::cout << "  Power Consumption: " << powerConsumption << "W\n";
        std::cout << "  Manufacturer: " << manufacturer << "\n";
    }
};

class Smartphone : public Electronics {
private:
    std::string operatingSystem;

public:
    // Constructor using initializer list and std::move
    Smartphone(double pc, std::string m, std::string os)
        : Electronics(pc, std::move(m)), operatingSystem(std::move(os)) {}

    virtual ~Smartphone() = default; // Virtual destructor

    // const-correctness
    void displaySmartphoneDetails() const {
        Electronics::displayElectronicsDetails(); // Call base class display
        std::cout << "Smartphone Details:\n";
        std::cout << "  Operating System: " << operatingSystem << "\n";
    }
};

class PremiumSmartphone : public Smartphone {
private:
    int cameraMP;

public:
    // Constructor using initializer list
    PremiumSmartphone(double pc, std::string m, std::string os, int cmp)
        : Smartphone(pc, std::move(m), std::move(os)), cameraMP(cmp) {}

    virtual ~PremiumSmartphone() = default; // Virtual destructor

    // const-correctness
    void displayPremiumSmartphoneDetails() const {
        Smartphone::displaySmartphoneDetails(); // Call base class display
        std::cout << "Premium Smartphone Details:\n";
        std::cout << "  Camera Megapixels: " << cameraMP << "MP\n";
    }
};

int main() {
    // Create an instance of PremiumSmartphone
    PremiumSmartphone myPremiumPhone(9.8, "NextGen Corp", "HarmonyOS 4.0", 200);

    std::cout << "--- Displaying Premium Smartphone Details (Direct Object) ---\n";
    myPremiumPhone.displayPremiumSmartphoneDetails();
    std::cout << "\n";

    // Demonstrate polymorphic behavior with base pointers and virtual destructors
    Electronics* electronicsPtr = new PremiumSmartphone(15.0, "Future Devices", "Android 14", 150);
    std::cout << "--- Displaying Details via Electronics* (Polymorphic) ---\n";
    // Using dynamic_cast to safely access derived class methods if needed,
    // or relying on virtual functions if they were overridden.
    // For this example, we just display the base details available through Electronics*.
    electronicsPtr->displayElectronicsDetails();
    std::cout << "\n";

    delete electronicsPtr; // Correctly calls ~PremiumSmartphone(), then ~Smartphone(), then ~Electronics()

    std::cout << "Program finished successfully.\n";

    return 0;
}