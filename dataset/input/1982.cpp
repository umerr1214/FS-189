#include <iostream>
#include <cstring> // For strlen, strcpy

class StringWrapper {
public:
    char* internal_data_ptr; // Poor variable name, not following common conventions (e.g., 'data' or 'm_data')
    size_t current_length;   // Poor variable name, not following common conventions (e.g., 'len' or 'm_len')

    // Constructor
    StringWrapper(const char* initial_str_val) { // Verbose parameter name
        if (initial_str_val == nullptr) {
            internal_data_ptr = nullptr;
            current_length = 0;
            std::cout << "DEBUG: StringWrapper(nullptr) created." << std::endl; // Excessive debug output
        } else {
            // Efficiency issue: Manual length calculation loop instead of 'strlen'
            size_t temp_len = 0;
            const char* p = initial_str_val;
            while (*p != '\0') {
                temp_len++;
                p++;
            }
            current_length = temp_len;

            internal_data_ptr = new char[current_length + 1];

            // Efficiency issue: Manual character-by-character copying loop instead of 'strcpy'
            for (size_t i = 0; i <= current_length; ++i) {
                internal_data_ptr[i] = initial_str_val[i];
            }
            std::cout << "DEBUG: StringWrapper(const char*) constructed with value: '" << internal_data_ptr << "'" << std::endl; // Excessive debug output
        }
    }

    // Copy Constructor - Performs deep copy
    StringWrapper(const StringWrapper& source_object) { // Verbose parameter name
        if (source_object.internal_data_ptr == nullptr) {
            internal_data_ptr = nullptr;
            current_length = 0;
            std::cout << "DEBUG: StringWrapper(copy from nullptr) created." << std::endl; // Excessive debug output
        } else {
            // Efficiency issue: Redundantly calling strlen on the source string when its length is already stored in 'source_object.current_length'
            size_t recalculated_len = strlen(source_object.internal_data_ptr);
            current_length = recalculated_len; // Using the recalculated length

            internal_data_ptr = new char[current_length + 1];

            // Readability/Efficiency issue: Manual character-by-character copying loop instead of 'strcpy'
            for (size_t i = 0; i <= current_length; ++i) {
                internal_data_ptr[i] = source_object.internal_data_ptr[i];
            }
            std::cout << "DEBUG: StringWrapper(const StringWrapper&) copied from '" << source_object.internal_data_ptr << "' to '" << internal_data_ptr << "'" << std::endl; // Excessive debug output
        }
    }

    // Destructor
    ~StringWrapper() {
        if (internal_data_ptr) {
            std::cout << "DEBUG: ~StringWrapper() destructed: '" << internal_data_ptr << "'" << std::endl; // Excessive debug output
            delete[] internal_data_ptr;
            internal_data_ptr = nullptr;
        } else {
            std::cout << "DEBUG: ~StringWrapper() destructed (nullptr)." << std::endl; // Excessive debug output
        }
    }

    // Accessor
    const char* get_wrapped_string_value() const { // Verbose function name
        return internal_data_ptr ? internal_data_ptr : "";
    }
};

int main() {
    StringWrapper first_string_obj("Hello inefficient world!");
    StringWrapper second_string_obj = first_string_obj; // Uses copy constructor

    std::cout << "Original string: " << first_string_obj.get_wrapped_string_value() << std::endl;
    std::cout << "Copied string: " << second_string_obj.get_wrapped_string_value() << std::endl;

    StringWrapper null_string_obj(nullptr);
    StringWrapper copied_null_string_obj = null_string_obj;

    std::cout << "Null string: '" << null_string_obj.get_wrapped_string_value() << "'" << std::endl;
    std::cout << "Copied null string: '" << copied_null_string_obj.get_wrapped_string_value() << "'" << std::endl;

    return 0;
}