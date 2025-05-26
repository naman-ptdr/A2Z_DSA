//  print all subsequences 
#include<bits/stdc++.h>
using namespace std;

void printf(int index,vector<int> &ds, vector<int>arr,int n){
    if(index == n){
        for(auto it : ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return ;
    }
    ds.push_back(arr[index]);
    printf(index+1,ds, arr, n);
    ds.pop_back();
    printf(index+1,ds, arr, n);
}
int main(){
    int n;
    cout<<"Enter size of Array: ";
    cin>>n;
    vector<int> arr(n);
    vector<int> ds;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    printf(0,ds, arr, n);
    return 0;
}