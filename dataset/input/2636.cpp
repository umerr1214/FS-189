#include <iostream>
#include <cstdlib> // For malloc, free
#include <cstring> // For memset

class DynamicIntegerArray {
private:
    int* d_ptr; // Cryptic variable name for data pointer
    int s_val;  // Cryptic variable name for size value

public:
    // Constructor
    DynamicIntegerArray(int sz_param) : s_val(sz_param) {
        if (s_val < 0) { // Basic check for negative size, but not robust error handling (e.g., throwing)
            s_val = 0;
        }
        if (s_val == 0) {
            d_ptr = nullptr;
        } else {
            // Readability/Efficiency Issue: Using malloc/free instead of new/delete.
            // malloc does not call constructors for elements (though int doesn't have one).
            // It also requires explicit casting and is less idiomatic C++.
            d_ptr = static_cast<int*>(malloc(s_val * sizeof(int)));
            if (d_ptr == nullptr) {
                std::cerr << "Memory allocation failed using malloc!" << std::endl;
                s_val = 0; // Set size to 0 if allocation fails
            } else {
                // Initialize memory to zero using memset, less C++ idiomatic than loop or value-initialization with new.
                memset(d_ptr, 0, s_val * sizeof(int));
            }
        }
        std::cout << "DynamicIntegerArray (malloc) of size " << s_val << " created." << std::endl;
    }

    // Destructor
    ~DynamicIntegerArray() {
        if (d_ptr != nullptr) {
            // Readability/Efficiency Issue: Using free instead of delete[].
            free(d_ptr);
            d_ptr = nullptr;
        }
        std::cout << "DynamicIntegerArray (malloc) of size " << s_val << " destroyed." << std::endl;
    }

    // Get size
    int get_sz() const { return s_val; } // Cryptic method name

    // Element access
    int& op_idx(int idx) { // Cryptic method name, not using operator[]
        if (idx < 0 || idx >= s_val) {
            std::cerr << "Error: Index out of bounds (malloc)!" << std::endl;
            static int dummy_val = -1; // Return a static dummy value to avoid crash
            return dummy_val;
        }
        return d_ptr[idx];
    }

    const int& op_idx(int idx) const { // Cryptic method name, not using operator[]
        if (idx < 0 || idx >= s_val) {
            std::cerr << "Error: Index out of bounds (const malloc)!" << std::endl;
            static const int dummy_val = -1;
            return dummy_val;
        }
        return d_ptr[idx];
    }

    void show_arr() const { // Cryptic method name
        if (s_val <= 0 || d_ptr == nullptr) {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
        for (int i = 0; i < s_val; ++i) {
            std::cout << d_ptr[i] << (i == s_val - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    std::cout << "--- Test Case 1: Normal Allocation ---" << std::endl;
    {
        DynamicIntegerArray d_arr(5);
        for (int i = 0; i < d_arr.get_sz(); ++i) {
            d_arr.op_idx(i) = (i + 1) * 11;
        }
        std::cout << "Array contents: ";
        d_arr.show_arr();
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 2: Zero Size Allocation ---" << std::endl;
    {
        DynamicIntegerArray d_arr(0);
        std::cout << "Array contents: ";
        d_arr.show_arr();
        d_arr.op_idx(0) = 100; // Should show error
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 3: Negative Size Allocation ---" << std::endl;
    {
        DynamicIntegerArray d_arr(-3); // Should become size 0
        std::cout << "Array size: " << d_arr.get_sz() << std::endl;
        std::cout << "Array contents: ";
        d_arr.show_arr();
    }
    std::cout << std::endl;

    std::cout << "--- Test Case 4: Out of Bounds Access ---" << std::endl;
    {
        DynamicIntegerArray d_arr(3);
        d_arr.op_idx(0) = 10; d_arr.op_idx(1) = 20; d_arr.op_idx(2) = 30;
        std::cout << "Array contents: ";
        d_arr.show_arr();
        std::cout << "Accessing d_arr.op_idx(3): " << d_arr.op_idx(3) << std::endl;
        std::cout << "Accessing d_arr.op_idx(-1): " << d_arr.op_idx(-1) << std::endl;
    }
    std::cout << std::endl;

    return 0;
}