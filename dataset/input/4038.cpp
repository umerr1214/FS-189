#include <iostream>

int main()
{
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    // Semantic Error: The switch expression is 'ch - 'A'', which is an integer representing the difference.
    // However, the case labels are still character literals ('A', 'E', etc.), which are also integers (their ASCII values).
    // These case labels will almost certainly never match the result of 'ch - 'A'',
    // as 'ch - 'A'' would need to evaluate to 65 (ASCII of 'A') for case 'A' to match, etc.
    // This results in all inputs falling to the default case.
    switch (ch - 'A')
    {
        case 'A': // This case will only match if (ch - 'A') == 65 (ASCII of 'A')
        case 'E': // This case will only match if (ch - 'A') == 69 (ASCII of 'E')
        case 'I': // etc.
        case 'O':
        case 'U':
            std::cout << "It is an uppercase vowel." << std::endl;
            break;
        default:
            std::cout << "It is not an uppercase vowel." << std::endl;
            break;
    }

    return 0;
}