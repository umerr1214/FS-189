#include <iostream>

int main()
{
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    switch (ch)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            std::cout << "It is an uppercase vowel." << std::endl;
            break;
        default:
            std::cout << "It is not an uppercase vowel." << std::endl;
            break;
    }
    // Missing closing brace for main function
}