// Algorithm / Intuition
// The logarithmic base 10 of a positive integers gives the number of digits in n. We add 1 to the result to ensure that the count is correct even for numbers that are powers of 10.

// We cast the result to an integer to ensure that any fractional part is discarded giving the exact count of digits.

// Algorithm

// Step 1: Initialise a variable to store the count of digits of the number.

// Step 2: The count of digits can be calculated using log10 N + 1.

// log10 N operation gives the logarithmic base 10 of which returns the power to which 10 must be raised to, to be equal to N.
// We add 1 to the result which accounts for the possibility that N itself is a power of 10.
// Financially cast the result to an integer to ensure that it is rounded down to the nearest whole number.
// Step 3: Return the value of count which represents the count of digits in the input integer N


                                
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;



// Calculate the count of digits in 'n'
// using logarithmic operation log10(n) + 1.
int countDigits(int n){
    // Initialize a variable 'cnt' to
    // store the count of digits.
    int cnt = (int)(log10(n)+1);

    // The expression (int)(log10(n)+1)
    // calculates the number of digits in 'n'
    // and casts it to an integer.
    
    // Adding 1 to the result accounts
    // for the case when 'n' is a power of 10,
    // ensuring that the count is correct.
   
    // Finally, the result is cast
    // to an integer to ensure it is rounded
    // down to the nearest whole number.
    
    // Return the count of digits in 'n'.
    return cnt;
}




int main() {
    int N = 329823;
    cout << "N: "<< N << endl;
    int digits = countDigits(N);
    cout << "Number of Digits in N: "<< digits << endl;
    return 0;
}
                                
                            