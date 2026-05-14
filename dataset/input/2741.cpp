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
public:
    Car(std::string b, int nd) : Vehicle(b), numDoors(nd) {}
    // Logical Error: Does not call Vehicle::displayInfo() to show inherited brand.
    void displayInfo() const {
        // Vehicle::displayInfo(); // This call is missing, leading to incomplete display
        std::cout << "Car Brand: " << brand << std::endl; // Accesses inherited brand directly
        std::cout << "Number of Doors: " << numDoors << std::endl;
    }
};

// SportsCar class derived from Car
class SportsCar : public Car {
private:
    int topSpeed;
public:
    SportsCar(std::string b, int nd, int ts) : Car(b, nd), topSpeed(ts) {}
    // Logical Error: Does not call Car::displayInfo() to show inherited car and vehicle info.
    void displayInfo() const {
        // Car::displayInfo(); // This call is missing, leading to incomplete display
        std::cout << "SportsCar Brand: " << brand << std::endl; // Accesses inherited brand directly
        std::cout << "SportsCar Doors: " << numDoors << std::endl; // Accesses inherited numDoors directly
        std::cout << "Top Speed: " << topSpeed << " mph" << std::endl;
    }
};

int main() {
    Vehicle v("General");
    Car c("Toyota", 4);
    SportsCar sc("Ferrari", 2, 200);

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