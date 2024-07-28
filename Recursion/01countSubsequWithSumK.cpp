//count subsequence with sum k

#include <bits/stdc++.h>
using namespace std;

// bool flag = false;
int subsequences(int i, const vector<int> &arr, int sum, int k, int n)
{
    // Base case: if we've considered all elements
    if (i == n)
    {
        if (sum == k)
        {
            // condition satisfied
            return 1;
        }
        // condition not satisfied
        return 0;
    }

    // Include arr[i] in the subsequence
    sum += arr[i];
    int l = subsequences(i + 1, arr, sum, k, n);

    // Exclude arr[i] from the subsequence
    sum -= arr[i];
    int r = subsequences(i + 1, arr, sum, k, n);

    return l+r;
}

int main()
{
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    cout<<"Number of subsequences whose sum is k : ";
    cout<<subsequences(0, arr, sum, k, n);

    return 0;
}
