#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class ResourceHandler {
public:
    int* data_ptr; // Less descriptive variable name
    int array_size; // Less descriptive variable name

    // Constructor: Allocates memory but does NOT initialize array elements.
    // This is less efficient if elements are always intended to be initialized,
    // and can lead to reading uninitialized memory if not explicitly set later.
    ResourceHandler(int sz) : array_size(sz), data_ptr(nullptr) {
        if (array_size > 0) {
            data_ptr = new int[array_size]; // Elements are uninitialized (garbage values)
        } else {
            array_size = 0;
        }
    }

    // Destructor: Deallocates the dynamically allocated memory
    ~ResourceHandler() {
        if (data_ptr != nullptr) {
            delete[] data_ptr;
            data_ptr = nullptr;
        }
    }

    // Method to manually initialize the array with a default value
    void initialize_with_val(int value) { // Verbose method name
        for (int i = 0; i < array_size; ++i) {
            *(data_ptr + i) = value; // Using pointer arithmetic for access, less readable than array indexing
        }
    }

    // Method to set a value at a specific index
    void set_val(int idx, int val) { // Less descriptive parameter names
        if (idx >= 0 && idx < array_size) {
            data_ptr[idx] = val;
        }
    }

    // Method to print the array contents, slightly less clean formatting
    std::string print_arr() const {
        std::ostringstream oss;
        oss << "{";
        for (int i = 0; i < array_size; ++i) {
            oss << data_ptr[i];
            if (i < array_size - 1) {
                oss << ","; // No space after comma
            }
        }
        oss << "}";
        return oss.str();
    }
};

void run_test_case(int initial_size, const std::vector<std::pair<int, int>>& values_to_set, std::ostream& os) {
    os << "Constructing ResourceHandler with size " << initial_size << std::endl;
    ResourceHandler handler(initial_size);

    os << "Array after construction (uninitialized values): " << handler.print_arr() << std::endl;

    os << "Initializing array with 0..." << std::endl;
    handler.initialize_with_val(0);
    os << "Array after initialization: " << handler.print_arr() << std::endl;

    for (const auto& p : values_to_set) {
        handler.set_val(p.first, p.second);
    }
    os << "Array after setting values: " << handler.print_arr() << std::endl;
    os << "End of test case." << std::endl;
}

int main() {
    std::vector<std::pair<int, int>> values1 = {{0, 100}, {1, 200}, {2, 300}};
    run_test_case(3, values1, std::cout);
    return 0;
}