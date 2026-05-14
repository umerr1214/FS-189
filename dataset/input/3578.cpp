#include <iostream>

int main() {
    int num1, num2, num3;

    std::cout << "Enter three integer numbers: ";
    std::cin >> num1 >> num2 >> num3;

    int largest;

    if (num1 >= num2) {
        if (num1 >= num3) {
            largest = num1;
        } else { // num3 > num1
            largest = num3;
        }
    } else { // num2 > num1
        if (num2 >= num3) {
            largest = num2;
        } else { // num3 > num2
            largest = num3;
        }
    }

    std::cout << "The largest number is: " << largest << std::endl;

    return 0;
}