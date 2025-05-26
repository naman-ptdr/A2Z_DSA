#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low + 1 && arr[j] > pivot) j--;

        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

void print(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of Array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the values of Array : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array before sorting : ";
    print(arr);
    quickSort(arr, 0, n - 1);
    cout << "Array after sorting : ";
    print(arr);

    return 0;
}
