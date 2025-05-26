#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Merging two halves
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements of the left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements of the right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void MergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;  // Base case: array is already sorted
    int mid = low + (high - low) / 2;
    MergeSort(arr, low, mid);          // Sort the first half
    MergeSort(arr, mid + 1, high);     // Sort the second half
    merge(arr, low, mid, high);        // Merge the sorted halves
}

void print(const vector<int> &arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of Array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    print(arr);

    MergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    print(arr);

    return 0;
}
