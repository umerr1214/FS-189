#include <iostream>
#include <string>

int main() {
    std::string sentence;
    std::cout << "Please enter a sentence: ";
    // Correctly reads an entire line (sentence) from standard input
    std::getline(std::cin, sentence);

    std::cout << "You entered: \"" << sentence << "\"" << std::endl;
    // Correct and efficient way to get the length of the string
    std::cout << "Total characters (including spaces): " << sentence.length() << std::endl;

    return 0;
}