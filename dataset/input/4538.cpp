#include <iostream>
#include <cstdlib> // For rand(), srand()
#include <ctime>   // For time()

// Readability Issue: Using a global variable for the secret number.
// This reduces encapsulation and makes the code harder to reason about,
// especially in larger programs where global state can lead to unexpected side effects.
int SECRET_NUMBER_GLOBAL;

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Initialize the global secret number
    SECRET_NUMBER_GLOBAL = std::rand() % 100 + 1; // Number between 1 and 100

    int usr_g; // Readability Issue: Non-descriptive variable name for user guess
    int cnt = 0; // Readability Issue: Non-descriptive variable name for attempt count

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have chosen a number between 1 and 100." << std::endl;

    do {
        std::cout << "Enter your guess: ";
        // Basic input, assumes valid integer input for this error type.
        std::cin >> usr_g;

        cnt++; // Increment attempt count

        if (usr_g < SECRET_NUMBER_GLOBAL) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (usr_g > SECRET_NUMBER_GLOBAL) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << SECRET_NUMBER_GLOBAL << " in " << cnt << " attempts." << std::endl;
        }
    } while (usr_g != SECRET_NUMBER_GLOBAL); // Loop until correct guess

    return 0;
}