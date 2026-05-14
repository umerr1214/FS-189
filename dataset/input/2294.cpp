#include <iostream>
#include <cstring> // For strlen, but strcpy is avoided for inefficiency
#include <string>  // For std::to_string

class StringWrapper {
private:
    char* my_char_array; // Less descriptive variable name
    size_t current_len;  // Less descriptive variable name

public:
    // Constructor
    StringWrapper(const char* input_str = "") {
        if (input_str == nullptr) {
            input_str = "";
        }
        current_len = strlen(input_str);
        my_char_array = new char[current_len + 1];
        // Inefficient manual copy loop instead of strcpy
        for (size_t i = 0; i <= current_len; ++i) {
            my_char_array[i] = input_str[i];
        }
        std::cout << "Constructor: " << my_char_array << std::endl;
    }

    // Destructor
    ~StringWrapper() {
        delete[] my_char_array;
        std::cout << "Destructor called for: " << (my_char_array ? my_char_array : "nullptr") << std::endl;
    }

    // Copy Constructor - Inefficient and less readable
    StringWrapper(const StringWrapper& original_obj) { // Parameter name slightly less clear
        // Inefficient: Re-calculating string length using strlen, even though original_obj.current_len is available.
        size_t len_of_original = strlen(original_obj.my_char_array);
        current_len = len_of_original;
        my_char_array = new char[current_len + 1];
        // Inefficient manual copy loop instead of strcpy
        for (size_t k = 0; k <= current_len; ++k) {
            my_char_array[k] = original_obj.my_char_array[k];
        }
        std::cout << "Copy Constructor: " << my_char_array << std::endl;
    }

    // Copy Assignment Operator (for completeness)
    StringWrapper& operator=(const StringWrapper& source_obj) { // Parameter name slightly less clear
        if (this == &source_obj) {
            return *this;
        }
        delete[] my_char_array;
        // Inefficient: Re-calculating string length using strlen
        size_t new_len = strlen(source_obj.my_char_array);
        current_len = new_len;
        my_char_array = new char[current_len + 1];
        // Inefficient manual copy loop
        for (size_t idx = 0; idx <= current_len; ++idx) {
            my_char_array[idx] = source_obj.my_char_array[idx];
        }
        std::cout << "Copy Assignment: " << my_char_array << std::endl;
        return *this;
    }

    const char* c_str_method() const { // Non-standard method name
        return my_char_array;
    }
    size_t get_size_val() const { // Non-standard method name
        return current_len;
    }
};

int main() {
    std::cout << "--- Testing StringWrapper with Readability/Efficiency Issues ---" << std::endl;

    StringWrapper original_string("SampleText");
    StringWrapper copied_string = original_string; // Calls copy constructor

    std::cout << "Original: " << original_string.c_str_method() << " (len: " << original_string.get_size_val() << ")" << std::endl;
    std::cout << "Copied: " << copied_string.c_str_method() << " (len: " << copied_string.get_size_val() << ")" << std::endl;

    StringWrapper another_string("MoreData");
    StringWrapper assigned_string; // Default constructor
    assigned_string = another_string; // Calls copy assignment

    std::cout << "\nAnother: " << another_string.c_str_method() << " (len: " << another_string.get_size_val() << ")" << std::endl;
    std::cout << "Assigned: " << assigned_string.c_str_method() << " (len: " << assigned_string.get_size_val() << ")" << std::endl;

    std::cout << "\nCreating and destroying several StringWrapper objects:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        StringWrapper loop_str("Num" + std::to_string(i));
        StringWrapper loop_copy = loop_str;
        std::cout << "  Loop " << i << ": " << loop_str.c_str_method() << ", Copy " << i << ": " << loop_copy.c_str_method() << std::endl;
    }

    std::cout << "\nEnd of main. Code is functionally correct but inefficient and less readable." << std::endl;

    return 0;
}