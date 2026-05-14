#include <iostream>
#include <string> // Included for consistency with driver, though not directly used in this file
#include <limits> // Included for consistency with driver, though not directly used in this file

// Function to encapsulate calculator logic for testing
void run_calculator(std::istream& i, std::ostream& o) {
double n1,n2;char op;
o<<"Enter first number: ";
i>>n1;
o<<"Enter operator (+, -, *, /): ";
i>>op;
o<<"Enter second number: ";
i>>n2;
double r;bool v=true;
switch(op){
case '+':r=n1+n2;break;
case '-':r=n1-n2;break;
case '*':r=n1*n2;break;
case '/':if(n2==0){
o<<"Error: Division by zero is not allowed."<<std::endl;v=false;
}else{r=n1/n2;}
break;
default:o<<"Error: Invalid operator."<<std::endl;v=false;
break;
}
if(v){o<<"Result: "<<r<<std::endl;}
}

// Original main function, just calls run_calculator with std::cin/cout
int main() {
    run_calculator(std::cin, std::cout);
    return 0;
}