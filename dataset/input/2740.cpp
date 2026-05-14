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
} // SYNTAX ERROR: Missing semicolon here

// Car class derived from Vehicle
class Car : public Vehicle {
protected:
    int numDoors;
public:
    Car(std::string b, int nd) : Vehicle(b), numDoors(nd) {}
    void displayInfo() const {
        Vehicle::displayInfo();
        std::cout << "Number of Doors: " << numDoors << std::endl;
    }
};

// SportsCar class derived from Car
class SportsCar : public Car {
private:
    int topSpeed;
public:
    SportsCar(std::string b, int nd, int ts) : Car(b, nd), topSpeed(ts) {}
    void displayInfo() const {
        Car::displayInfo();
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