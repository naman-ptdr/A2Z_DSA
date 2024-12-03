// Algorithm / Intuition
// We can optimise the previous approach by using the property that for any non-negative integer n, if d is a divisor of n then n/d is also a divisor of n.

// This property is symmetric about the square root of n by traversing just the first half we can avoid redundant iteration and computations improving the efficiency of the algorithm.


// Algorithm

// Step 1: Initialise an array to store the divisors.

// Step 2: Iterate from 1 to square root of n using a loop variable ‘i’. For each value of ‘i’:

// Check if ‘i’ is a divisor of ‘n’ by checking if ‘n’ is divisible by ‘i’ without a remainder (‘n’%i == 0).
// If i is a divisor, add it to the vectors of divisors.
// If i is different from n/i add the counterpart divisor n/i to the vector of divisors.
// Step 3: After the loop, return the array of divisors.



                                
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> findDivisors(int n) {
    // Initialize an empty
    // vector to store the divisors
    vector<int> divisors; 

    // Iterate up to the square
    // root of n to find divisors
    // Calculate the square root of n
    int sqrtN = sqrt(n); 
    
    // Loop from 1 to the
    // square root of n
    for (int i = 1; i <= sqrtN; ++i) { 
        // Check if i divides n
        // without leaving a remainder
        if (n % i == 0) { 
            // Add divisor i to the list
            divisors.push_back(i); 

            // Add the counterpart divisor
            // if it's different from i
            if (i != n / i) {
                // Add the counterpart
                // divisor to the list
                divisors.push_back(n / i); 
            }
        }
    }
    
    // Return the list of divisors
    return divisors; 
}


int main() {
    int number = 12;
    vector<int> divisors = findDivisors(number);

    cout << "Divisors of " << number << " are: ";
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}
                                
                            