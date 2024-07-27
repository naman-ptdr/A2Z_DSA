/*Print Name N times using Recursion
Prerequisite: The learner must know how to write a simple function in 
any language with parameters.

Now, after understanding the basics of recursion, the recursion tree, 
and the base case of recursion we can solve some basic problems of recursion 
which would strengthen our concepts and make us understand how recursion functions at its core.

Problem: Print your Name N times using recursion

Since in this problem, there is no count that can be incremented each 
time we call a function, how can we keep a track of how many times we have printed the name?

For this problem, we’re going to be using a function along with parameters 
in which we can keep track of the number of times we’ve printed something. 
To understand this problem better, let us see the pseudocode below for this : 

void func( i, n )
{
   if(i>n) return;
 print(“Raj”);
   f( i+1,N );
}
main()
{
  int n;
  input(n);
  f(1,n);
}
We can clearly see in this pseudocode that we first call the function when the value 
of i is 1 and then print the name and increment i by 1 inside the parameter of the function 
and make a call again. But, we know that this will go on forever as i will be increasing 
continuously after every function call. So, to avoid this we put a base condition that if 
i exceeds n, then simply terminate the current recursive call and return to the previous call.
*/


#include<bits/stdc++.h>
using namespace std;

void func(int i, int n){
   
   // Base Condition.
   if(i>n) return;
   cout<<"Raj"<<endl;

   // Function call to print till i increments.
   func(i+1,n);

}

int main(){
  
  // Here, let’s take the value of n to be 4.
  int n = 4;
  func(1,n);
  return 0;

}


/*Output 

Raj
Raj
Raj
Raj

Time Complexity: O(N) { Since the function is being called n times, and for each 
function, we have only one printable line that takes O(1) time, so the cumulative 
time complexity would be O(N) }

Space Complexity: O(N) { In the worst case, the recursion stack space would be 
full with all the function calls waiting to get completed and that would make it 
an O(N) recursion stack space }.
*/