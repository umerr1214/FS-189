#include <iostream>
#include <string>

// Vehicle class
class Vehicle {
protected:
    std::string brand;
public:
    Vehicle(std::string b) : brand(b) {}
    void displayInfo() const {
        std::cout << "Vehicle Brand: " << brand << std::endl;
    }
};

// Car class derived from Vehicle
class Car : public Vehicle {
protected:
    int numDoors;
    std::string brand; // SEMANTIC ERROR: Shadows Vehicle::brand
public:
    // Car's constructor now needs to initialize both Vehicle::brand and Car::brand (the shadowed one)
    Car(std::string v_brand, int nd, std::string c_brand) : Vehicle(v_brand), numDoors(nd), brand(c_brand) {}
    void displayInfo() const {
        Vehicle::displayInfo(); // This will display Vehicle's brand
        std::cout << "Car Brand (shadowed): " << brand << std::endl; // This displays Car's own brand
        std::cout << "Number of Doors: " << numDoors << std::endl;
    }
};

// SportsCar class derived from Car
class SportsCar : public Car {
private:
    int topSpeed;
protected:
    int numDoors; // SEMANTIC ERROR: Shadows Car::numDoors
public:
    // SportsCar's constructor now needs to initialize Vehicle::brand, Car::numDoors, Car::brand, SportsCar::topSpeed, and SportsCar::numDoors (the shadowed one)
    SportsCar(std::string v_brand, int c_doors, std::string c_brand, int ts, int sc_doors)
        : Car(v_brand, c_doors, c_brand), topSpeed(ts), numDoors(sc_doors) {}
    void displayInfo() const {
        Car::displayInfo(); // This will display Vehicle's brand, Car's brand, and Car's numDoors
        std::cout << "SportsCar Doors (shadowed): " << numDoors << std::endl; // This displays SportsCar's own numDoors
        std::cout << "Top Speed: " << topSpeed << " mph" << std::endl;
    }
};

int main() {
    Vehicle v("General");
    Car c("Toyota", 4, "Toyota_Shadow"); // Vehicle brand, Car doors, Car's shadowed brand
    SportsCar sc("Ferrari", 2, "Ferrari_Shadow", 200, 3); // Vehicle brand, Car doors, Car's shadowed brand, Top speed, SportsCar's shadowed doors

    std::cout << "--- Vehicle Info ---" << std::endl;
    v.displayInfo();
    std::cout << std::endl;

    std::cout << "--- Car Info ---" << std::endl;
    c.displayInfo();
    std::cout << std::endl;

    std::cout << "--- SportsCar Info ---" << std::endl;
    sc.displayInfo();
    std::cout << std::endl;

    return 0;
}