/*Print 1 to N using Recursion
Prerequisite: The learner must know how to write a simple function in any 
language with parameters.

Now, after understanding the basics of recursion, the recursion tree, and 
the base case of recursion we can solve some basic problems of recursion which 
would strengthen our concepts and make us understand how recursion functions at its 
core. In this article, we’ll print integers from 1 to N without using any Global Variable 

but by using function parameters. 

Problem: Print from 1 to N using Recursion

Since in this problem, there is no global variable that can be incremented 
each time we call a function, how can we keep a track of the number of integers 
being printed on the output screen?

For this problem, we’re going to be using a function along with parameters 
that get incremented with each function call through which we can keep track of 
the integer count while printing. To understand this problem better, let us see the 
pseudocode below for this : 

void func( i, n )
{
   if(i>n) return;
 print(i);
   f( i+1,N );
}
main()
{
  int n;
  input(n);
  f(1,n);
}
We can clearly see in this pseudocode that we first call the function when the value of i 
is 1 and then print the value of i and increment i by 1 inside the parameter of the function 
and make a call again. But, we know that this will go on forever as i will be 
increasing continuously after every function call. So, to avoid this we put a base 
condition that if i exceeds n, then simply terminate the current recursive call and 
return to the previous call.

In this way, all the integers from 1 to N would get printed and as soon as we exceed the 
count of printing by n, the function terminates.
*/



// #include<bits/stdc++.h>
// using namespace std;

// void func(int i, int n){
   
//    // Base Condition.
//    if(i>n) return;
//    cout<<i<<endl;

//    // Function call to print i till i increments to n.
//    func(i+1,n);

// }

// int main(){
  
//   // Here, let’s take the value of n to be 4.
//   int n = 4;
//   func(1,n);
//   return 0;

// }




/*Output 

1
2
3
4
*/








/*Alternate Approach for printing integers from 1 to N (using Backtracking)

This is an alternative approach for printing the integers from 1 to N using recursion. 
In the previous approach, we used forward recursion but in this approach, we will be using 
backward recursion. The only change from the previous approach here will be that the 
print line would be kept after the function call inside the recursive function contrary 
to the previous approach. The function would be called for printing (i-1) integers and 
the nth integer would be printed.

To get a clear understanding of what this approach is like let’s see the pseudocode for this :

void func( i, n )
{
   if(i<1) return;
 f( i-1,N );
print(i);

}
main()
{
  int n;
  input(n);
  f(n,n);
}
We can clearly see in this pseudocode that we first call the function when the value of 
i is N and then make a call again inside this function for printing (n-1) integers and 
after this we print N. But, we know that this will go on forever as i will be decreasing 
continuously after every function call. So, to avoid this we put a base condition that if 
i is less than n, then simply terminate the current recursive call and return to the previous call.

In this way, all the integers from 1 to N would get printed and as soon as i becomes less 
than n, the function call terminates.
*/




#include<bits/stdc++.h>
using namespace std;

void func(int i, int n){
   
   // Base Condition.
   if(i<1) return;
   
   // Function call to print (n-1) integers.
   func(i-1,n);
   cout<<i<<endl;

}

int main(){
  
  // Here, let’s take the value of n to be 4.
  int n = 4;
  func(n,n);
  return 0;

}



/*Output:

1
2
3
4

Time Complexity: O(N) { Since the function is being called n times, and for each function, 
we have only one printable line that takes O(1) time, so the cumulative time complexity 
would be O(N) }

Space Complexity: O(N) { In the worst case, the recursion stack space would be full with 
all the function calls waiting to get completed and that would make it an O(N) recursion 
stack space }.
*/