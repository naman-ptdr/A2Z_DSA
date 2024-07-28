// Implement Pow(x,n) | X raised to the power N
// Problem Statement: Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).




// #include<bits/stdc++.h>
// using namespace std;
// double myPow(double x, int n) {
//       double ans = 1.0;
//       for (int i = 0; i < n; i++) {
//         ans = ans * x;
//       }
//       return ans;
// }
// int main()
// {
//     cout<<myPow(2,10)<<endl;
// }



// Approach: Initialize ans as 1.0  and store a duplicate copy of n i.e nn using to avoid overflow

// Check if nn is a negative number, in that case, make it a positive number.

// Keep on iterating until nn is greater than zero, now if nn is an odd power then multiply x with ans ans reduce nn by 1. Else multiply x with itself and divide nn by two.

// Now after the entire binary exponentiation is complete and nn becomes zero, check if n is a negative value we know the answer will be 1 by and.



#include<bits/stdc++.h>

using namespace std;
double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}

int main() {
  cout << myPow(2, 10) << endl;
}



// Output: 1024

// Time Complexity: O(log n)

// Space Complexity: O(1)