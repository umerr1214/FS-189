#include <iostream>
#include <cstdio> // For printf
#include <iomanip> // For std::hex, std::dec (though not strictly needed for direct pointer print)

int main() {
    // Declare a double variable and initialize it with a decimal value
    double my_decimal_value = 42.123456789;

    // Declare a pointer to that variable
    double* ptr_to_value = &my_decimal_value;

    // Print the value of the variable using dereferencing the pointer
    // Using printf is less type-safe and idiomatic in C++ than iostreams (readability/efficiency issue).
    printf("Value: %.6f\n", *ptr_to_value);

    // Print the memory address of the variable using the address-of operator
    // Using reinterpret_cast to unsigned long long for printing addresses is verbose,
    // less readable, and less portable than directly printing the pointer (readability/efficiency issue).
    unsigned long long address_via_ref = reinterpret_cast<unsigned long long>(&my_decimal_value);
    std::cout << "Address (using &): 0x" << std::hex << address_via_ref << std::dec << "\n";

    // Print the memory address of the variable using the pointer itself
    // Same issue as above for printing the pointer. Inconsistent use of std::endl vs. \n.
    unsigned long long address_via_ptr = reinterpret_cast<unsigned long long>(ptr_to_value);
    std::cout << "Address (using pointer): 0x" << std::hex << address_via_ptr << std::dec << "\n";

    return 0;
}