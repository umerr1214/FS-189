#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    std::string sentence;
    std::cout << "Please enter a sentence: ";
    // Robustness issue: std::cin >> only reads up to the first whitespace.
    // This means if the user enters "Hello World", only "Hello" will be read into 'sentence'.
    std::cin >> sentence; 
    
    // Clear the rest of the line from the input buffer to prevent it from affecting subsequent inputs
    // if this were part of a larger program. For this specific problem, the core robustness issue
    // is the partial reading of the sentence itself.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "You entered: " << sentence << std::endl;
    std::cout << "Total characters (including spaces in what was read): " << sentence.length() << std::endl;
    return 0;
}