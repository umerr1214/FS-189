#include <iostream>
#include <type_traits> // Required for std::is_same_v

template <typename T>
void printValue(T value) {
    if constexpr (std::is_same_v<T, char>) {
        // Logical Error: For 'char' type, it prints the ASCII integer value
        // instead of the character itself, which deviates from "simply prints its value".
        std::cout << "Value (ASCII): " << static_cast<int>(value) << std::endl;
    } else {
        std::cout << "Value: " << value << std::endl;
    }
}

int main() {
    printValue(10);
    printValue('A'); // This will incorrectly print "Value (ASCII): 65"
    return 0;
}