#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

struct Product {
    int productIdIdentifier;
    std::string productNameString;
    double productPriceValue;
};

int main() {
    Product productArrayOfTwoProducts[2]; // Fixed size array of Product structs

    std::cout << "Please provide the data for the first product:\n";
    std::cout << "Input Product 1 ID: ";
    std::cin >> productArrayOfTwoProducts[0].productIdIdentifier;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
    std::cout << "Input Product 1 Name: ";
    std::getline(std::cin, productArrayOfTwoProducts[0].productNameString);
    std::cout << "Input Product 1 Price: ";
    std::cin >> productArrayOfTwoProducts[0].productPriceValue;

    std::cout << "\nPlease provide the data for the second product:\n";
    std::cout << "Input Product 2 ID: ";
    std::cin >> productArrayOfTwoProducts[1].productIdIdentifier;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
    std::cout << "Input Product 2 Name: ";
    std::getline(std::cin, productArrayOfTwoProducts[1].productNameString);
    std::cout << "Input Product 2 Price: ";
    std::cin >> productArrayOfTwoProducts[1].productPriceValue;

    // Determine which product has the maximum price
    Product productWithHighestPriceDetails;
    if (productArrayOfTwoProducts[0].productPriceValue >= productArrayOfTwoProducts[1].productPriceValue) {
        productWithHighestPriceDetails = productArrayOfTwoProducts[0];
    } else {
        productWithHighestPriceDetails = productArrayOfTwoProducts[1];
    }

    // Output the detailed information of the product with the highest price
    std::cout << "\nProduct with highest price:\n";
    std::cout << "ID: " << productWithHighestPriceDetails.productIdIdentifier << "\n";
    std::cout << "Name: " << productWithHighestPriceDetails.productNameString << "\n";
    std::cout.precision(2);
    std::cout << std::fixed << "Price: " << productWithHighestPriceDetails.productPriceValue << "\n";

    return 0;
}