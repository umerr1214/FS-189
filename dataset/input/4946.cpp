#include <iostream>

int user_main() {
  std::cout << "Enter a positive integer limit: ";
  int l; // Readability Issue: Poor variable name for 'limit'
  std::cin >> l; // Assuming valid input for this category

  long long s = 0; // Readability Issue: Poor variable name for 'sum'
  // Efficiency Issue: Iterates through all numbers from 1 to 'l' and checks for evenness.
  // Less efficient than directly iterating through even numbers (i.e., starting at 2 and incrementing by 2).
  for (int x = 1; x <= l; ++x) { 
    if (x % 2 == 0) {
      s += x;
    }
  }

  std::cout << "The sum of even numbers up to " << l << " is: " << s << std::endl;
  return 0;
}