#include <iostream>
#include <string> // Included but not strictly necessary for this template, adding slight overhead/verbosity
#include <iomanip> // For consistent double precision printing

template <typename T>
void compareAndPrint(T firstValue, T secondValue) {
    // Readability / Efficiency Issue:
    // This implementation is overly verbose and uses a nested if-else structure
    // which, while functionally correct, makes the code less concise and
    // harder to read compared to a direct if-else if-else chain.
    // The output messages are excessively wordy and fragmented, diminishing clarity.
    // While not a major performance hit for this simple task, the verbosity
    // and fragmented output stream operations are less efficient than a concise approach.

    std::cout << std::fixed << std::setprecision(10); // Set precision for consistent double output

    if (firstValue == secondValue) {
        std::cout << "The initial argument, specifically the value of " << firstValue
                  << ", has been determined to be precisely equivalent to the subsequent argument, "
                  << "which holds the value of " << secondValue << "." << std::endl;
    } else {
        // Nested condition for greater or less, making the logic slightly less flat and harder to parse at a glance.
        if (firstValue > secondValue) {
            std::cout << "Following a detailed assessment, it is evident that the value of " << firstValue
                      << " is unequivocally greater than the value of " << secondValue << "." << std::endl;
        } else {
            // If not equal and not greater, it must logically be less.
            std::cout << "Conversely, after careful consideration, it is apparent that " << firstValue
                      << " is distinctly less than " << secondValue << "." << std::endl;
        }
    }
}

int main() {
    // Demonstrate with int
    compareAndPrint(5, 10);
    compareAndPrint(10, 5);
    compareAndPrint(7, 7);

    // Demonstrate with double
    compareAndPrint(3.14, 2.71);
    compareAndPrint(2.71, 3.14);
    compareAndPrint(5.0, 5.0);
    compareAndPrint(0.1 + 0.2, 0.3); // (0.1+0.2 is slightly greater than 0.3)
    compareAndPrint(0.3, 0.1 + 0.2); // (0.3 is slightly less than 0.1+0.2)

    // Demonstrate with char
    compareAndPrint('a', 'b');
    compareAndPrint('b', 'a');
    compareAndPrint('c', 'c');

    return 0;
}