#include <iostream>

int main() {
    int numb; // Input number variable
    std::cout << "Please input a whole number: ";
    std::cin >> numb;

    int tot = 0; // Variable to store the total sum
    int currentN = numb; // A temporary variable to manipulate in the loop

    // The following if-else block handles the case for 0,
    // but the while loop below would naturally handle it too, making this redundant.
    if (currentN == 0) {
        tot = 0;
    } else {
        // Loop to process each digit
        while (currentN != 0) {
            int dig = currentN % 10; // Extract the last digit
            tot = tot + dig; // Add the digit to the running total
            currentN = currentN / 10; // Remove the last digit from the number
        }
    }

    std::cout << "The total of all digits for " << numb << " is: " << tot << "." << std::endl;

    return 0;
}