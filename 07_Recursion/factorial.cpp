/*Factorial of a Number : Iterative and recursive approach
Problem Statement: Given a number X,  print its factorial.

To obtain the factorial of a number, it has to be multiplied by all the whole numbers preceding it. More precisely X! = X*(X-1)*(X-2) … 1.

Note: X  is always a positive number. 

Examples:

Example 1:
Input: X = 5
Output: 120
Explanation: 5! = 5*4*3*2*1

Example 2:
Input: X = 3
Output: 6
Explanation: 3!=3*2*1
Solution



Solution 1: Iterative

Approach:

Since the factorial of X  will be the product of the number itself and all its preceding numbers we can run loop i, from 1 to X. In every iteration current i, is multiplied with the product so far.  

Code:

C++
*/
#include <iostream>
using namespace std;
int factorial(int X) {
   int ans = 1;
   for (int i = 1; i <= X; i++) {
      ans = ans * i;
   }
   return ans;
}
int main() {
   int X = 5;
   int result = factorial(X);
   cout << "The factorial of " << X << " is " << result;
}
/*
Output: The factorial of 5 is 120

Time Complexity: O(n)

Space Complexity: O(1)

Solution 2: Recursive

Recursive way of calculating the factorial of first N Numbers (functional way):

The Factorial of a number N can be calculated by multiplying all the natural numbers till the number N. Through this approach, we can visualize the factorial of n natural numbers in the following way as shown below:

factorial(N) = N * factorial(N-1);
The Factorial of N natural numbers is the Nth integer multiplied by the Factorial of (N-1) natural numbers. The base case can be visualized as if n decreases to 0, then we return 1 because the factorial of 0 is 1 only. Here, we’ve just broken the problem into 2 subparts and the answers of both would be multiplied together and stored in the factorial(n) function which would then be printed at last.

To understand this functional approach better, let us have a look at the pseudocode given below:

int factorial(n)
{
   if(n == 0)
   {
     return 1;
   }

return n * factorial(n-1);

}

main()
{
   input(n);
   factorial(n);

}
Recursion Tree for the following problem can be represented as follows :


C++
*/
#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
   
   // Base Condition.
   if(n == 0)
   {
       return 1;
   }

   // Problem broken down into 2 parts and then combined.
   return n * factorial(n-1);

}

int main(){
  
  // Here, let’s take the value of n to be 3.
  int n = 3;
  cout<<factorial(n)<<endl;
  return 0;

}
/*
Output 

6

Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.

[tabby title="Java Coding"]

class Recursion {
    
    static int factorial(int n){
        
            // Base Condition.
            if(n == 0){
                
                return 1;
            }
            
            // Problem broken down into 2 parts and then combined.
            return n * factorial(n-1);
            

    }
    public static void main(String[] args) {

       // Here, let’s take the value of n to be 3.
       int n = 3;
       System.out.println(factorial(n));
    }
}
Output 

6

Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/