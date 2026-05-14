#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int num1, num2, num3;
    std::cin >> num1 >> num2 >> num3;

    // This code correctly identifies the middle value, but its structure is overly complex
    // and uses deeply nested if-else statements. This makes it difficult to read,
    // understand, and verify compared to simpler, more direct methods like sorting
    // or using min/max functions. While functionally correct, its readability and
    // maintainability are poor.
    if (num1 > num2) {
        if (num1 < num3) { // Case: num2 < num1 < num3
            std::cout << num1 << std::endl;
        } else { // Case: num1 is largest (num1 > num2 and num1 > num3)
            if (num2 > num3) { // Case: num3 < num2 < num1
                std::cout << num2 << std::endl;
            } else { // Case: num2 < num3 < num1
                std::cout << num3 << std::endl;
            }
        }
    } else { // Case: num2 > num1
        if (num2 < num3) { // Case: num1 < num2 < num3
            std::cout << num2 << std::endl;
        } else { // Case: num2 is largest (num2 > num1 and num2 > num3)
            if (num1 > num3) { // Case: num3 < num1 < num2
                std::cout << num1 << std::endl;
            } else { // Case: num1 < num3 < num2
                std::cout << num3 << std::endl;
            }
        }
    }

    return 0;
}