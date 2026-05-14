#include <iostream>

int solution_main() {
    int num1, num2, num3;

    std::cout << "Enter the first integer: ";
    std::cin >> num1;
    std::cout << "Enter the second integer: ";
    std::cin >> num2;
    std::cout << "Enter the third integer: ";
    std::cin >> num3;

    int largest;

    // This nested if-else structure is functionally correct but can be less readable
    // or more verbose compared to using logical AND operators in a single condition.
    // It involves more comparisons than strictly necessary in some paths.
    if (num1 >= num2) {
        if (num1 >= num3) {
            largest = num1;
        } else { // num3 > num1 (and num1 >= num2 is true)
            largest = num3;
        }
    } else { // num2 > num1
        if (num2 >= num3) {
            largest = num2;
        } else { // num3 > num2 (and num2 > num1 is true)
            largest = num3;
        }
    }
    
    std::cout << "The largest number is: " << largest << std::endl;

    return 0;
}

int main() {
    return solution_main();
}