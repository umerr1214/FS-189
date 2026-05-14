#include <iostream>
#include <string>

class Engine {
private:
    int engine_horsepower_value; // Readability Issue: Verbose name
    std::string engine_fuel_type_string; // Readability Issue: Verbose name

public:
    Engine(int hp_val, const std::string& fuel_type_str) { // Efficiency Issue: Not using initializer list for members
        this->engine_horsepower_value = hp_val; // Readability Issue: Excessive use of 'this->'
        this->engine_fuel_type_string = fuel_type_str;
    }

    void start_the_engine_component() { // Readability Issue: Verbose method name
        std::string output_message = "Engine component has initiated operation! Fuel source: "; // Efficiency Issue: Unnecessary intermediate string concatenation
        output_message += this->engine_fuel_type_string;
        output_message += ", Power rating: ";
        output_message += std::to_string(this->engine_horsepower_value);
        std::cout << output_message << std::endl;
    }

    int retrieve_current_horsepower_setting() { // Readability Issue: Verbose getter name, Efficiency Issue: Not const-correct
        return this->engine_horsepower_value;
    }

    std::string retrieve_current_fuel_type_designation() { // Readability Issue: Verbose getter name, Efficiency Issue: Not const-correct
        return this->engine_fuel_type_string;
    }
};

class Car {
private:
    std::string car_manufacturer_name; // Readability Issue: Verbose name
    std::string car_model_designation; // Readability Issue: Verbose name
    Engine composed_engine_unit; // Readability Issue: Verbose name for member object

public:
    Car(const std::string& car_mk, const std::string& car_md, int engine_hp, const std::string& engine_ft)
        : composed_engine_unit(engine_hp, engine_ft) // Member object must use initializer list
    {
        // Efficiency Issue: Not using initializer list for Car's own string members,
        // leading to default construction followed by assignment (less efficient)
        this->car_manufacturer_name = car_mk; // Readability Issue: Excessive use of 'this->'
        this->car_model_designation = car_md;
    }

    void execute_vehicle_startup_procedure() { // Readability Issue: Verbose method name
        std::cout << "Executing startup sequence for vehicle model: " << this->car_manufacturer_name << " " << this->car_model_designation << std::endl;
        this->composed_engine_unit.start_the_engine_component(); // Calls verbose engine method
    }

    std::string obtain_vehicle_manufacturer_information() { // Readability Issue: Verbose getter name, Efficiency Issue: Not const-correct
        return this->car_manufacturer_name;
    }

    std::string obtain_vehicle_model_information() { // Readability Issue: Verbose getter name, Efficiency Issue: Not const-correct
        return this->car_model_designation;
    }
};

int main() {
    Car my_automobile_instance("Volkswagen", "Golf", 180, "Diesel");
    my_automobile_instance.execute_vehicle_startup_procedure();
    std::cout << std::endl;

    Car another_automobile_instance("Audi", "A4", 220, "Gasoline");
    another_automobile_instance.execute_vehicle_startup_procedure();
    std::cout << std::endl;

    return 0;
}