#include <iostream>
#include <cstring> // For strlen

class StringWrapper {
private:
    char* string_data_pointer; // Less descriptive name

public:
    // Default and C-string constructor
    StringWrapper(const char* initial_string = nullptr) : string_data_pointer(nullptr) {
        if (initial_string == nullptr) {
            // Inefficiently allocates a single character for an empty string
            string_data_pointer = new char[1];
            string_data_pointer[0] = '\0';
        } else {
            // Manual character-by-character copy loop (less efficient than strcpy/memcpy)
            size_t string_length = std::strlen(initial_string);
            string_data_pointer = new char[string_length + 1];
            for (size_t i = 0; i <= string_length; ++i) { // Includes null terminator
                string_data_pointer[i] = initial_string[i];
            }
        }
    }

    // Deep Copy Constructor
    StringWrapper(const StringWrapper& source_wrapper) : string_data_pointer(nullptr) {
        if (source_wrapper.string_data_pointer != nullptr) {
            // Redundant strlen call if source_wrapper always ensures non-null data
            size_t len = std::strlen(source_wrapper.string_data_pointer);
            string_data_pointer = new char[len + 1];
            // Manual character-by-character copy loop again
            for (size_t i = 0; i <= len; ++i) { // Includes null terminator
                string_data_pointer[i] = source_wrapper.string_data_pointer[i];
            }
        } else {
            // Should not be reachable if string_data_pointer is always allocated
            string_data_pointer = new char[1];
            string_data_pointer[0] = '\0';
        }
    }

    // Copy Assignment Operator (also inefficient)
    StringWrapper& operator=(const StringWrapper& rhs) {
        if (this == &rhs) {
            return *this; // Self-assignment check
        }

        // Inefficient: delete current memory, then reallocate and copy
        delete[] string_data_pointer;
        string_data_pointer = nullptr; // Reset to null after delete

        if (rhs.string_data_pointer != nullptr) {
            size_t len = std::strlen(rhs.string_data_pointer);
            string_data_pointer = new char[len + 1];
            for (size_t i = 0; i <= len; ++i) {
                string_data_pointer[i] = rhs.string_data_pointer[i];
            }
        } else {
            string_data_pointer = new char[1];
            string_data_pointer[0] = '\0';
        }
        return *this;
    }

    // Destructor
    ~StringWrapper() {
        delete[] string_data_pointer;
        // No need to set to nullptr in destructor, object is going out of scope
    }

    // Getter for the C-style string
    const char* get_wrapped_string() const { // Verbose getter name
        return string_data_pointer;
    }

    // Function to print the string
    void print_contents(const char* label = "") const { // Verbose function name
        std::cout << label << (string_data_pointer ? string_data_pointer : "(null)") << std::endl;
    }
};

int main() {
    std::cout << "--- Testing Readability/Efficiency Issue ---" << std::endl;

    // Test Case 1: Constructor with string and null
    StringWrapper sw_greeting("Hello");
    sw_greeting.print_contents("sw_greeting: ");

    StringWrapper sw_empty; // Calls constructor with nullptr, allocates 1 byte
    sw_empty.print_contents("sw_empty: ");

    // Test Case 2: Copy constructor
    StringWrapper sw_copy = sw_greeting; // Uses inefficient copy constructor
    sw_copy.print_contents("sw_copy (from greeting): ");

    // Test Case 3: Copy assignment
    StringWrapper sw_assigned("Original");
    sw_assigned.print_contents("sw_assigned (before assignment): ");
    sw_assigned = sw_greeting; // Uses inefficient assignment operator
    sw_assigned.print_contents("sw_assigned (after assignment): ");

    StringWrapper sw_self_assign("Self assign test");
    std::cout << "Self assigning sw_self_assign = sw_self_assign..." << std::endl;
    sw_self_assign = sw_self_assign; // Self-assignment check works, but still has inefficient copy logic if not handled properly
    sw_self_assign.print_contents("sw_self_assign (after self-assign): ");

    std::cout << "--- End Test ---" << std::endl;
    return 0;
}