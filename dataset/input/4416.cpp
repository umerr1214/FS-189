#include <iostream>

template <typename T>
T printValue(T value) { // Semantic Error: Function is declared to return 'T', but has no return statement.
    std::cout << "Value: " << value << std::endl;
    // Missing 'return value;'
}

int main() {
    // Calling a function that is declared to return a value but doesn't,
    // which results in a semantic error (compiler will typically flag missing return).
    int int_val = printValue(10);
    char char_val = printValue('A');

    // These lines would demonstrate the returned values if the function were correct.
    // However, due to the semantic error, the program won't compile or link successfully.
    std::cout << "Returned int_val: " << int_val << std::endl;
    std::cout << "Returned char_val: " << char_val << std::endl;

    return 0;
}