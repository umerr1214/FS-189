#include <iostream>
#include <vector> // Unnecessarily included, not used for primary array management.
#include <cstdlib> // For std::rand, std::exit
#include <ctime>   // For std::time
#include <cstring> // For memset (if using calloc)

// Global using declaration, generally discouraged in headers or global scope.
using namespace std; 

class Resource_Manager_For_Dynamic_Integer_Array {
private:
    int* p_internal_data_store_for_numbers; // Verbose and non-idiomatic C++ naming
    int current_array_capacity_value;        // Verbose and non-idiomatic C++ naming

public:
    // Constructor with somewhat redundant initialization logic
    Resource_Manager_For_Dynamic_Integer_Array(int initial_size_param) {
        if (initial_size_param <= 0) {
            cout << "Invalid size provided. Defaulting to 5 for safety." << endl;
            current_array_capacity_value = 5;
        } else {
            current_array_capacity_value = initial_size_param;
        }

        // Using calloc and free, which is C-style memory management and less idiomatic C++ than 'new int[size]{}'
        p_internal_data_store_for_numbers = (int*)calloc(current_array_capacity_value, sizeof(int));
        if (p_internal_data_store_for_numbers == nullptr) {
            cerr << "CRITICAL ERROR: Failed to allocate memory!" << endl;
            exit(1); 
        }
        cout << "Resource_Manager_For_Dynamic_Integer_Array object created with size " 
             << current_array_capacity_value << "." << endl;
    }

    // Destructor
    ~Resource_Manager_For_Dynamic_Integer_Array() {
        if (p_internal_data_store_for_numbers != nullptr) {
            free(p_internal_data_store_for_numbers); // Mismatched free with calloc (should be delete[] for new)
            p_internal_data_store_for_numbers = nullptr;
            cout << "Resource_Manager_For_Dynamic_Integer_Array object (size " 
                 << current_array_capacity_value << ") destroyed." << endl;
        }
    }

    // Function to populate array elements
    void execute_array_population_routine() { // Verbose method name, not const
        if (p_internal_data_store_for_numbers == nullptr) {
            cout << "Cannot populate a null array. Exiting routine." << endl;
            return;
        }
        
        // Inefficient way to fill: first with 0, then with random values.
        // calloc already zero-initializes, so this loop is redundant.
        for (int i = 0; i < current_array_capacity_value; ++i) {
            p_internal_data_store_for_numbers[i] = 0; 
        }

        // Seed rand every time this function is called, which is inefficient and bad practice.
        // std::srand should typically be called once at the start of the program.
        srand(time(nullptr)); 
        for (int i = 0; i < current_array_capacity_value; ++i) {
            p_internal_data_store_for_numbers[i] = rand() % 100; // Fill with random numbers
        }
        cout << "Array population routine completed." << endl;
    }

    // Function to output array contents
    void present_array_data_to_console() { // Verbose method name, not const
        if (p_internal_data_store_for_numbers == nullptr) {
            cout << "No array data to present." << endl;
            return;
        }
        cout << "Current array data (size " << current_array_capacity_value << "):" << endl;
        // Printing each element on a new line, less efficient for display and harder to read
        for (int i = 0; i < current_array_capacity_value; ++i) {
            cout << "Element " << i << ": " << p_internal_data_store_for_numbers[i] << endl; // Inefficient endl
        }
        cout << "--- End of Array Data ---" << endl;
    }
};

int main() {
    cout << "Program starting for Readability/Efficiency demonstration." << endl;

    Resource_Manager_For_Dynamic_Integer_Array my_first_resource(7);
    my_first_resource.execute_array_population_routine();
    my_first_resource.present_array_data_to_console();

    cout << "\nCreating another resource with an invalid size..." << endl;
    Resource_Manager_For_Dynamic_Integer_Array my_second_resource(0); // Invalid size
    my_second_resource.execute_array_population_routine();
    my_second_resource.present_array_data_to_console();

    cout << "\nProgram finished." << endl;
    return 0;
}