#include <iostream>
#include <cstdlib> // For rand(), srand()
#include <ctime>   // For time()

int main() {
    // Semantic Error: Seeding with a fixed value (or not at all) makes the "random" number predictable.
    // The programmer might think they are seeding randomness, but `srand(1)` will always produce the same sequence.
    srand(1); // Using a fixed seed instead of `time(0)`

    // Generate secret number between 1 and 100
    // With srand(1), rand() will always return the same first value, making secretNumber constant.
    int secretNumber = (rand() % 100) + 1;

    int guess;
    int attempts = 0;
    const int MAX_ATTEMPTS = 5;
    bool guessedCorrectly = false;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have picked a number between 1 and 100. You have " << MAX_ATTEMPTS << " attempts.\n";

    while (attempts < MAX_ATTEMPTS) {
        std::cout << "Attempt " << attempts + 1 << "/" << MAX_ATTEMPTS << ". Enter your guess: ";
        std::cin >> guess;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        attempts++;

        if (guess == secretNumber) {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts.\n";
            guessedCorrectly = true;
            break;
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }
    }

    if (!guessedCorrectly) {
        std::cout << "Sorry, you ran out of attempts. The secret number was " << secretNumber << ".\n";
    }

    return 0;
}