#include <iostream>
// This program defines a power calculation function and integrates it.
// It has readability and minor efficiency issues:
// - Poor variable naming ('b', 'e', 'r').
// - Inconsistent spacing and indentation.
// - Braces placed on the same line as control statements.
// - The function name 'myPowerFunc' is less descriptive than 'power'.
// - A minor correctness issue: it returns 1 for negative exponents, which is incorrect.
int myPowerFunc(int b,int e) {
  if (e == 0) return 1; // Handles exponent 0 correctly
  if (e < 0) { // This is a minor correctness flaw, as 1 is incorrect for negative exponents
    return 1;
  }
  int r=1; // Result variable, poorly named
  for(int i=0;i<e;++i){ // Loop for multiplication
    r*=b;
  }
  return r;
} // Function closing brace

int main() {
  int baseVal,expVal; // Inconsistent variable naming style compared to function
  std::cout<<"Enter base: ";
  std::cin>>baseVal;
  std::cout<<"Enter exponent: ";
  std::cin>>expVal;
  int result=myPowerFunc(baseVal,expVal); // Calls the power function
  std::cout<<"Result: "<<result<<std::endl;
  return 0;
}