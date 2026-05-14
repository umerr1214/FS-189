#include <iostream>
#include <string>

// Electronics (base class)
class Electronics {
protected:
    double powerConsumption; // in Watts

public:
    Electronics(double pc) : powerConsumption(pc) {}

    virtual void displayDetails() const {
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

    virtual void displayDetails() const override {
        Electronics::displayDetails(); // Correctly calls base
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

    virtual void displayDetails() const override {
        // LOGICAL ERROR: This method does not call Smartphone::displayDetails().
        // It directly calls Electronics::displayDetails(), skipping Smartphone's specific details.
        Electronics::displayDetails();
        std::cout << "--- Premium Smartphone Details ---" << std::endl;
        std::cout << "Camera Megapixels: " << cameraMP << "MP" << std::endl;
    }
};

int main() {
    PremiumSmartphone flagshipPhone(6.8, "iOS", 108);
    flagshipPhone.displayDetails();
    return 0;
}