#include <iostream>
#include <cstdlib> // For srand, rand
#include <ctime>   // For time

int main() {
    srand(time(0));
    int targetNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have generated a number between 1 and 100. Try to guess it." << std::endl // SYNTAX ERROR: Missing semicolon

    do {
        attempts++;
        std::cout << "Attempt " << attempts << ": Enter your guess: ";
        std::cin >> guess;

        if (guess < targetNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > targetNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << targetNumber
                      << " in " << attempts << " attempts." << std::endl;
        }
    } while (guess != targetNumber);

    return 0;
}