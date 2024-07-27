/*Recursive way of calculating the sum of first N Natural Numbers:

Parameterized Way
Functional Way
1. Parameterized way

In this approach, instead of using a global variable for calculating the sum, we pass the sum in the parameters of the function each time we add an integer to it during the function call. The sum gets incremented by an ith integer and i get decremented by 1 in each function call. At the end when i becomes less than 1, we simply return the calculated sum until that point.

To understand this parameterized approach better, let us have a look at the pseudocode given below:

// void func(i,sum)
// {
//    if(i<1)
//    {
//      print(sum);
//      return;
//    }

// func(i-1,sum+i);

// }

// main()
// {
//    input(n);
//    func(n,0);

// }
We can clearly see in this pseudocode that we first call the function when the value of sum is 0 and then we increment the value of sum by i (initially i is n) and decrement i by 1 inside the parameter of the function and make a call again. But, we know that this will go on forever as i will be decreasing continuously after every function call. So, to avoid this we put a base condition that if i is less than 1, then simply terminate the current recursive call and return the calculated sum.
*/

#include <bits/stdc++.h>
using namespace std;

void func(int i, int sum)
{

    // Base Condition.
    if (i < 1)
    {
        cout << sum << endl;
        return;
    }

    // Function call to increment sum by i till i decrements to 1.
    func(i - 1, sum + i);
}

int main()
{

    // Here, let’s take the value of n to be 3.
    int n = 3;
    func(n, 0);
    return 0;
}

/*Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.






2. Functional way

This approach is a lot simpler than the parameterized recursion. We can visualize the sum of n natural numbers in the following way as shown below:

sumOfNaturalNumbers(N) = N + sumOfNaturalNumbers(N-1);
The Sum of N natural numbers would just be the Nth integer added to the Sum of (N-1) natural numbers. The base case can be visualized as if n decreases to 0, then we return 0 because the sum of 0 natural numbers is 0 only. Here, we’ve just broken the problem into 2 subparts and the answers of both these subparts would be added and stored in the Sum(n) function which would then be printed at last.

To understand this functional approach better, let us have a look at the pseudocode given below:

int func(n)
{
   if(n == 0)
   {
     return 0;
   }

return n + func(n-1);

}

main()
{
   input(n);
   func(n);

}
*/

#include <bits/stdc++.h>
using namespace std;

int func(int n)
{

    // Base Condition.
    if (n == 0)
    {
        return 0;
    }

    // Problem broken down into 2 parts and then combined.
    return n + func(n - 1);
}

int main()
{

    // Here, let’s take the value of n to be 3.
    int n = 3;
    cout << func(n) << endl;
    return 0;
}

/*Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/