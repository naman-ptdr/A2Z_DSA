#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left++]);
        }else{
            temp.push_back(arr[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=high){
        temp.push_back(arr[right++]);
    }
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}
void mergeSort(int arr[], int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i] <= pivot && i<= high-1) i++;
        while(arr[j] > pivot && j>= low+1) j--;
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}


void quickSort(int arr[], int low, int high){
    if(low<high){
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<< "Before Sorting : ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    mergeSort(arr, 0, n-1);
    cout<< "After Sorting : ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
return 0;
}