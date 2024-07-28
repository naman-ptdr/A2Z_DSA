// Print subsequence whose sum is equal to k
#include <bits/stdc++.h>
using namespace std;

void subsequences(int i, vector<int>& ds,const vector<int>& arr, int sum, int k, int n) {
    // Base case: if we've considered all elements
    if (i == n) {
        if (sum == k) {
            // Print the current subsequence
            for (auto j : ds) {
                cout << j << " ";
            }
            cout << endl;
        }
        return;
    }

    // Include arr[i] in the subsequence
    ds.push_back(arr[i]);
    subsequences(i + 1, ds, arr, sum + arr[i], k, n);

    // Exclude arr[i] from the subsequence
    ds.pop_back();
    subsequences(i + 1, ds, arr, sum, k, n);
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ds;
    int sum = 0;
    subsequences(0, ds, arr, sum, k, n);
    
    return 0;
}
