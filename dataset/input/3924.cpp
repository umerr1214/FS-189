#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    std::string inputString;
    char searchChar;

    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    std::cout << "Enter a character to count: ";
    std::cin >> searchChar;

    // Clear the input buffer after reading a char with >>
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int count = 0;
    // Semantic error: loop iterates one too many times, accessing inputString[inputString.length()]
    // which is out-of-bounds and leads to undefined behavior.
    for (int i = 0; i <= inputString.length(); ++i) { // Incorrect loop condition, should be 'i < inputString.length()'
        // This will access inputString[inputString.length()] which is past the end of the string.
        // On some systems, this might read a null terminator, on others it might crash,
        // or read garbage data. The behavior is undefined.
        if (inputString[i] == searchChar) {
            count++;
        }
    }

    std::cout << "The character '" << searchChar << "' appears " << count << " times in \"" << inputString << "\"." << std::endl;

    return 0;
}