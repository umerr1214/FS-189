#include <iostream> // For std::cout, std::cin, std::endl
#include <string>   // For std::string, std::getline
#include <algorithm> // For std::reverse

int main() {
    // Improve I/O performance (optional, but good practice for competitive programming/large inputs)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "Enter a string: ";
    std::string userString;
    
    // Read the entire line from the user, including spaces
    std::getline(std::cin, userString);

    // Reverse the string in-place using std::reverse from <algorithm>
    std::reverse(userString.begin(), userString.end());

    std::cout << "Reversed string: " << userString << std::endl;

    return 0;
}