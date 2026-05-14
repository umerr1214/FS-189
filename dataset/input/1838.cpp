#include <iostream>
#include <string>
// Not using std::move for string parameters for a minor efficiency issue (unnecessary copies)

// CPU_component class with less readable names and inefficient constructor
class CPU_component {
private:
    std::string cpu_manuf; // Less descriptive variable name
    double clk_spd_ghz; // Less descriptive variable name

public:
    // Constructor assigns in body, leading to default construction then assignment for strings
    CPU_component(std::string p_manuf, double p_clk_spd) {
        cpu_manuf = p_manuf; // Inefficient: copy constructor then assignment
        clk_spd_ghz = p_clk_spd;
    }

    std::string get_cpu_manufacturer_info() const { return cpu_manuf; } // Verbose getter name
    double get_clock_speed_value() const { return clk_spd_ghz; } // Verbose getter name
};

// Laptop_device class with less readable names and inefficient constructor
class Laptop_device {
private:
    std::string laptop_model_name; // Less descriptive variable name
    CPU_component the_cpu_unit; // Less descriptive member name

public:
    // Constructor:
    // 1. Default constructs `the_cpu_unit` first, then assigns a new `CPU_component` object.
    //    This is less efficient than using an initializer list for `the_cpu_unit`.
    // 2. Assigns `laptop_model_name` in the body, also less efficient.
    Laptop_device(std::string p_model_name, std::string p_cpu_manuf, double p_cpu_clk_spd)
        : the_cpu_unit("", 0.0) // Default construct CPU_component, then assign
    {
        laptop_model_name = p_model_name; // Inefficient: copy constructor then assignment
        the_cpu_unit = CPU_component(p_cpu_manuf, p_cpu_clk_spd); // Creates temporary, then copy assigns
    }

    std::string retrieve_laptop_model() const { return laptop_model_name; }
    std::string retrieve_cpu_manuf() const { return the_cpu_unit.get_cpu_manufacturer_info(); }
    double retrieve_cpu_speed() const { return the_cpu_unit.get_clock_speed_value(); }

    void print_device_specifications() const { // Verbose function name
        std::cout << "Laptop Model: " << laptop_model_name << std::endl; // Using std::endl is less efficient than '\n'
        std::cout << "  CPU Manufacturer: " << the_cpu_unit.get_cpu_manufacturer_info() << std::endl;
        std::cout << "  CPU Clock Speed: " << the_cpu_unit.get_clock_speed_value() << " GHz" << std::endl;
    }
};

int main() {
    // Example usage with verbose variable names
    Laptop_device first_laptop_instance("ZenBook Pro", "IntelCore", 2.8);
    first_laptop_instance.print_device_specifications();

    Laptop_device second_laptop_instance("Surface Laptop", "Qualcomm", 3.0);
    second_laptop_instance.print_device_specifications();

    return 0;
}