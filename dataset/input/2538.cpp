#include <iostream>
#include <string>

class Vehicle {
public:
    std::string brand;
protected:
    std::string model;
private:
    int year;

public:
    Vehicle(std::string b, std::string m, int y) : brand(b), model(m), year(y) {}

    int getYear() const {
        return year;
    }

    void setYear(int newYear) {
        year = newYear;
    }

    void displayVehicleInfo() const {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << getYear() << std::endl;
    }
};

class Car : public Vehicle {
public:
    Car(std::string b, std::string m, int y) : Vehicle(b, m, y) {}

    void setModel(std::string newModel) {
        model = newModel;
    }

    void displayCarInfo() const {
        std::cout << "Brand (from Car): " << brand << std::endl;
        std::cout << "Model (from Car): " << model << std::endl;
        std::cout << "Year (from Car via getter): " << getYear() << std::endl;
    }
};

int main() {
    Vehicle myVehicle("Toyota", "Camry", 2020);
    std::cout << "Original Vehicle Info:" << std::endl;
    myVehicle.displayVehicleInfo();
    std::cout << "----------------------" << std::endl;

    myVehicle.brand = "Honda";
    std::cout << "Modified brand directly: " << myVehicle.brand << std::endl;
    std::cout << "----------------------" << std::endl;

    myVehicle.setYear(2022);
    std::cout << "Modified year via setter: " << myVehicle.getYear() << std::endl;
    std::cout << "----------------------" << std::endl;

    // Semantic Error: Attempting to directly access private member 'year' from main
    // This line will cause a compilation error due to access violation.
    std::cout << "Attempting to access private member year directly: " << myVehicle.year << std::endl;

    Car myCar("Ford", "Focus", 2018);
    std::cout << "Original Car Info:" << std::endl;
    myCar.displayCarInfo();
    std::cout << "----------------------" << std::endl;

    myCar.setModel("Mustang");
    std::cout << "Modified model via derived class method: ";
    myCar.displayCarInfo();
    std::cout << "----------------------" << std::endl;

    return 0;
}