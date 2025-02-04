#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0; i<=n-2; i++){
        int mini = i;
        for(int j=i; j<=n-1; j++){
            if(arr[mini]>arr[j]) mini = j;
        }
        swap(arr[mini], arr[i]);
    }
}

void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        int didSwap = 0;
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                didSwap = 1;
                swap(arr[j], arr[j+1]);
            }
        }
        if(didSwap==0) break;
    }
}
void insertion_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        int j=i; 
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    insertion_sort(arr, n);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

return 0;
}