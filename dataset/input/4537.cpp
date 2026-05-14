#include <iostream>
#include <cstdlib> // For rand(), srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Choose a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have chosen a number between 1 and 100." << std::endl;

    do {
        std::cout << "Enter your guess: ";
        // Robustness Issue: No input validation.
        // If the user enters non-numeric input, std::cin will fail,
        // and the loop will become infinite as 'guess' won't be updated,
        // and the error state of std::cin won't be cleared.
        std::cin >> guess;

        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}