/*Sum of first N Natural Numbers
Problem statement: Given a number ‘N’, find out the sum of the first N natural numbers.

Examples:

Example 1:
Input: N=5
Output: 15
Explanation: 1+2+3+4+5=15

Example 2:
Input: N=6
Output: 21
Explanation: 1+2+3+4+5+6=15
Solution
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution1: Using Loop

Intuition: We can simply add numbers one by one from 1 to N.

For eg. if N = 5, we can add 1+2+3+4+5=15.

We can use a for loop or while loop to achieve the goal.

Approach: 

Take a variable sum and initialize it as 0.
Take a for loop and run from 1 to N.
Save the result in sum.
*/



// #include<bits/stdc++.h>
// using namespace std;
//  void solve(int n) {
//     int sum = 0;
//     for (int i = 1; i <= n; i++) {
//       sum += i;
//     }
//     cout<<"The sum of the first "<<n<<" numbers is: "<<sum<<endl;
//   }
//  int main() {

//     solve(5);
//     solve(6);
//   }



/*Output:

The sum of the first 5 numbers is: 15
The sum of the first 6 numbers is: 21

Time Complexity: O(N)

Space Complexity: O(1)






Solution 2: Using the formula

Intuition: We can use the formula for the sum of N numbers, i.e N(N+1)/2.

For eg: N=5

5(5+1)/2 = 5(6)/2 = 15.

Approach: 

Take a variable sum.
Initialize it with N(N+1)/2, where N is a given number.


*/


#include<bits/stdc++.h>
using namespace std;
 void solve(int N) {
    int sum = N * (N + 1) / 2;
    cout<<"The sum of the first "<<N<<" numbers is: "<<sum<<endl;
  }
 int main() {

    solve(5);
    solve(6);
  }

/*The sum of the first 5 numbers is: 15
The sum of the first 6 numbers is: 21

Time Complexity: O(1)

Space Complexity: O(1)
*/