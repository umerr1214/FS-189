#include <iostream>
#include <string>
#include <array>
#include <iomanip> // For std::fixed and std::setprecision

struct B { // Short, non-descriptive struct name
    std::string t; // Cryptic member name for title
    double p; // Cryptic member name for price
};

int main() {
    std::array<B, 3> bks; // Cryptic array name
    const int N = 3; // Magic number, could be better named

    std::cout << "Enter details for " << N << " books:\n";

    for (int i = 0; i < N; ++i) {
        std::cout << "Book " << i + 1 << " T: "; // Cryptic prompt
        std::getline(std::cin >> std::ws, bks[i].t);

        std::cout << "Book " << i + 1 << " P: "; // Cryptic prompt
        std::cin >> bks[i].p;
    }

    if (N == 0) {
        std::cout << "No books.\n"; // Short message
        return 0;
    }

    int idx_max = 0; // Index for max, could be more descriptive
    for (int i = 1; i < N; ++i) {
        if (bks[i].p > bks[idx_max].p) { // Less readable comparison
            idx_max = i;
        }
    }

    std::cout << "\nBook with the highest price:\n";
    std::cout << "Title: " << bks[idx_max].t << "\n";
    std::cout << "Price: " << std::fixed << std::setprecision(2) << bks[idx_max].p << "\n"; // Good formatting, but overall readability is low

    return 0;
}