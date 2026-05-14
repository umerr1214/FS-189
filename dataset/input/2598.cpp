#include <iostream>
#include <string>

// Electronics (base class)
class Electronics {
protected:
    double powerConsumption; // in Watts

public:
    Electronics(double pc) : powerConsumption(pc) {}

    // SEMANTIC ERROR: displayDetails is NOT virtual.
    // This prevents polymorphic behavior when accessed via base class pointers/references.
    void displayDetails() const { // Missing 'virtual' keyword
        std::cout << "--- Electronics Details ---" << std::endl;
        std::cout << "Power Consumption: " << powerConsumption << "W" << std::endl;
    }
};

// Smartphone (derived from Electronics)
class Smartphone : public Electronics {
protected:
    std::string operatingSystem;

public:
    Smartphone(double pc, const std::string& os)
        : Electronics(pc), operatingSystem(os) {}

    // This method effectively hides Electronics::displayDetails(),
    // but does not override it polymorphically because the base method is not virtual.
    void displayDetails() const {
        Electronics::displayDetails();
        std::cout << "--- Smartphone Details ---" << std::endl;
        std::cout << "Operating System: " << operatingSystem << std::endl;
    }
};

// PremiumSmartphone (derived from Smartphone)
class PremiumSmartphone : public Smartphone {
private:
    int cameraMP; // Megapixels

public:
    PremiumSmartphone(double pc, const std::string& os, int mp)
        : Smartphone(pc, os), cameraMP(mp) {}

    // This method hides Smartphone::displayDetails() and Electronics::displayDetails(),
    // but does not override them polymorphically.
    void displayDetails() const {
        Smartphone::displayDetails();
        std::cout << "--- Premium Smartphone Details ---" << std::endl;
        std::cout << "Camera Megapixels: " << cameraMP << "MP" << std::endl;
    }
};

int main() {
    PremiumSmartphone flagshipPhone(6.8, "iOS", 108);
    Smartphone midRangePhone(5.5, "Android");

    // When calling through base class pointers, static dispatch will occur
    // and Electronics::displayDetails() will always be called due to lack of 'virtual'.
    Electronics* e1 = &flagshipPhone;
    Electronics* e2 = &midRangePhone;

    std::cout << "--- Test Case 1: Calling PremiumSmartphone via Electronics pointer ---" << std::endl;
    e1->displayDetails(); // Will call Electronics::displayDetails, not PremiumSmartphone's
    std::cout << "\n";

    std::cout << "--- Test Case 2: Calling Smartphone via Electronics pointer ---" << std::endl;
    e2->displayDetails(); // Will call Electronics::displayDetails, not Smartphone's
    std::cout << "\n";

    // Direct calls to derived objects still work as expected, as static dispatch
    // correctly identifies the object type.
    std::cout << "--- Test Case 3: Direct call to PremiumSmartphone ---" << std::endl;
    flagshipPhone.displayDetails();
    std::cout << "\n";

    return 0;
}