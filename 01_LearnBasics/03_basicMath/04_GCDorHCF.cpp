// Algorithm / Intuition
// We can optimise the time complexity of the previous approach. In the worst case, the loop iterates from 1 up to the minimum of N1 and N2. This could potentially result in a large number of iterations, especially when one input number is significantly larger than the other.

// If we iterate from the minimum of N1 and N2 down to 1, we reduce the number of iterations because we start from the potentially largest common factor and work downwards.

// The time complexity of this approach remains O(min(N1, N2)) but in practice, it will execute fewer iterations on average.

// Algorithm:
// Step 1: Iterate from the minimum of n1 and n2 because the greatest common divisor of two numbers cannot exceed the smaller number.

// Step 2: For each i in the iteration, we check if it is a common factor of both n1 and n2.

// If a common factor i is found, we return it as the gcd as we are iterating from the largest potential gcd to 1, the first common factor we encounter will be the greatest common divisor.
// Step 3: If the loop completes without finding any common factors we return 1. This is because 1 is always a divisor of any number any number hence is also the GCD of any pair of numbers where no other common factors exist.

                                
#include <iostream>
#include <algorithm>

using namespace std;

int findGcd(int n1, int n2) {
    // Iterate from the minimum of
    // n1 and n2 down to 1
    // Start from the minimum of n1 and n2
    // because the GCD cannot
    // exceed the smaller number
    
    for(int i = min(n1, n2); i > 0; i--) {
        // Check if i is a common
        // factor of both n1 and n2
        if(n1 % i == 0 && n2 % i == 0) {
            // If i is a common factor,
            // return it as the GCD
            return i;
        }
    }
    // If no common factors are found,
    // return 1 (as 1 is always a
    // divisor of any number)
    return 1;
}


int main() {
    int n1 = 20, n2 = 15;
    
    // Find the GCD of n1 and n2
    int gcd = findGcd(n1, n2);

    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

    return 0;
}


                                
                            