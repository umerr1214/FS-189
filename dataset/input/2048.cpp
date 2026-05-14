#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but often included.

// Base class Vehicle
class Vehicle {
private: // Using private and then needing getters/setters for derived classes is less efficient than protected
    int v_speed; // Poor variable name
    std::string v_color; // Poor variable name

public:
    // Constructor - passes string by value (less efficient)
    Vehicle(int s, std::string c);

    // Setter - passes string by value (less efficient)
    void set_v_speed(int s); // Inconsistent naming convention (set_v_speed vs setSpeed)
    void set_v_color(std::string c);

    // Getters - missing const (less robust)
    int get_v_speed();
    std::string get_v_color();

    void show_v_info(); // Poor method name, defined outside
};

// Defining methods outside the class declaration for all methods (less readable for simple ones)
Vehicle::Vehicle(int s, std::string c) {
    v_speed = s;
    v_color = c;
}

void Vehicle::set_v_speed(int s) {
    v_speed = s;
}

void Vehicle::set_v_color(std::string c) {
    v_color = c;
}

int Vehicle::get_v_speed() {
    return v_speed;
}

std::string Vehicle::get_v_color() {
    return v_color;
}

void Vehicle::show_v_info() {
    std::cout << "Vehicle Details: Speed = " << v_speed << " KPH, Color = " << v_color << std::endl << std::endl; // Excessive std::endl
}

// Derived class Car
class Car : public Vehicle {
private:
    int c_doors; // Poor variable name

public:
    // Constructor - passes string by value (less efficient)
    Car(int s, std::string c, int nd);

    // Setter
    void set_c_doors(int nd);

    // Getter - missing const
    int get_c_doors();

    void car_special_action(); // Poor method name
    void show_c_details(); // Poor method name
};

Car::Car(int s, std::string c, int nd) : Vehicle(s, c) {
    c_doors = nd;
}

void Car::set_c_doors(int nd) {
    c_doors = nd;
}

int Car::get_c_doors() {
    return c_doors;
}

void Car::car_special_action() {
    std::cout << "Car Action: Zoom! This car has " << c_doors << " doors." << std::endl << std::endl; // Excessive std::endl
}

void Car::show_c_details() {
    show_v_info(); // Calls base method
    std::cout << "Car Features: Doors = " << c_doors << std::endl << std::endl; // Excessive std::endl
}

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    bool m_sidecar; // Poor variable name

public:
    // Constructor - passes string by value (less efficient)
    Motorcycle(int s, std::string c, bool hs);

    // Setter
    void set_m_sidecar(bool hs);

    // Getter - missing const
    bool get_m_sidecar();

    void moto_trick(); // Poor method name
    void show_m_details(); // Poor method name
};

Motorcycle::Motorcycle(int s, std::string c, bool hs) : Vehicle(s, c) {
    m_sidecar = hs;
}

void Motorcycle::set_m_sidecar(bool hs) {
    m_sidecar = hs;
}

bool Motorcycle::get_m_sidecar() {
    return m_sidecar;
}

void Motorcycle::moto_trick() {
    std::cout << "Motorcycle Trick: Pop a wheelie! Sidecar status: " << (m_sidecar ? "Present" : "Absent") << std::endl << std::endl; // Excessive std::endl
}

void Motorcycle::show_m_details() {
    show_v_info(); // Calls base method
    std::cout << "Motorcycle Specs: Has a sidecar = " << (m_sidecar ? "True" : "False") << std::endl << std::endl; // Excessive std::endl
}

int main() {
    std::cout << "== CAR DEMO ==" << std::endl << std::endl; // Excessive std::endl
    Car my_car_obj(180, "Blue", 2); // Poor variable name
    my_car_obj.show_c_details();
    my_car_obj.car_special_action();

    std::cout << "== MOTORCYCLE DEMO ==" << std::endl << std::endl; // Excessive std::endl
    Motorcycle my_moto_obj(100, "Green", false); // Poor variable name
    my_moto_obj.show_m_details();
    my_moto_obj.moto_trick();

    return 0;
}