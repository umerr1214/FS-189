#include <iostream>
#include <type_traits> // For std::is_same_v

template <typename T>
void compareAndPrint(T a, T b) {
    // Semantic error: For 'char' types, we explicitly cast to 'int' for printing.
    // This changes the output representation from characters to their ASCII values,
    // which deviates from the natural expectation of printing characters themselves.
    // The comparison logic (a > b, b > a, a == b) is still performed correctly on 'T' (char values).
    using PrintType = typename std::conditional<std::is_same_v<T, char>::value, int, T>::type;

    if (a > b) {
        std::cout << static_cast<PrintType>(a) << " is greater than " << static_cast<PrintType>(b) << std::endl;
    } else if (b > a) {
        std::cout << static_cast<PrintType>(b) << " is greater than " << static_cast<PrintType>(a) << std::endl;
    } else {
        std::cout << static_cast<PrintType>(a) << " is equal to " << static_cast<PrintType>(b) << std::endl;
    }
}

int main() {
    std::cout << "--- int comparison ---" << std::endl;
    compareAndPrint(5, 10);
    compareAndPrint(15, 5);
    compareAndPrint(7, 7);

    std::cout << "\n--- double comparison ---" << std::endl;
    compareAndPrint(3.14, 2.71);
    compareAndPrint(10.5, 20.1);
    compareAndPrint(9.9, 9.9);

    std::cout << "\n--- char comparison ---" << std::endl;
    compareAndPrint('A', 'B'); // Semantic error: will print ASCII values (e.g., 65 vs 66)
    compareAndPrint('Z', 'M'); // Semantic error: will print ASCII values (e.g., 90 vs 77)
    compareAndPrint('X', 'X'); // Semantic error: will print ASCII values (e.g., 88 vs 88)
    return 0;
}