#include <iostream>

int main() {
        int first_integer_value_from_user;
        int second_integer_value_from_user;
        int third_integer_value_from_user;

    std::cout << "Enter three distinct integers: ";
    std::cin >> first_integer_value_from_user >> second_integer_value_from_user >> third_integer_value_from_user;

    // Readability / Efficiency Issue:
    // - Excessively long variable names.
    // - Inconsistent and poor indentation.
    // - The nested if-else structure, while functionally correct, is less readable
    //   and slightly less direct than a linear if-else if-else chain for this specific problem.
    //   It doesn't significantly impact efficiency for just three numbers but reduces clarity.
    if (first_integer_value_from_user > second_integer_value_from_user) {
        if (first_integer_value_from_user > third_integer_value_from_user) {
            std::cout << "The largest number is: " << first_integer_value_from_user << std::endl;
        } else {
            std::cout << "The largest number is: " << third_integer_value_from_user << std::endl;
        }
    } else {
        if (second_integer_value_from_user > third_integer_value_from_user) {
            std::cout << "The largest number is: " << second_integer_value_from_user << std::endl;
        } else {
            std::cout << "The largest number is: " << third_integer_value_from_user << std::endl;
        }
    }

    return 0;
}