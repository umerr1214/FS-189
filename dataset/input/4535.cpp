#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Choose a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have chosen a number between 1 and 100.\n";

    do {
        std::cout << "Guess the number: ";
        std::cin >> guess;
        attempts++;

        // Logical error: hints are reversed
        if (guess < randomNumber) {
            std::cout << "Too high!\n"; // Should be "Too low!"
        } else if (guess > randomNumber) {
            std::cout << "Too low!\n";  // Should be "Too high!"
        } else {
            std::cout << "Correct! You guessed it in " << attempts << " tries.\n";
        }
    } while (guess != randomNumber);

    return 0;
}