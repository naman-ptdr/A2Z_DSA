// Approach: Efficient (Single traversal)
// As we know that for a sorted array the previous of every element is smaller than or equal to its current element.
// So, Through this, we can conclude that if the previous element is smaller than or equal to the current element then. Then we can say that the two elements are sorted. If the condition is true for the entire array then the array is sorted.
// We will check every element with its previous element if the previous element is smaller than or equal to the current element then we will move to the next index.
// If the whole array is traversed successfully or the size of the given array is zero or one (i.e N = 0 or N = 1). Then we will return True else return False.




#include<bits/stdc++.h>

using namespace std;

bool isSorted(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}

int main() {

  int arr[] = {1, 2, 3, 4, 5}, n = 5;

  printf("%s", isSorted(arr, n) ? "True" : "False");

}

