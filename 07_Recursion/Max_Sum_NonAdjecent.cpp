// Max sum of non adjecent element of array
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int ind, int sum, int &maxi){
    if(ind>=arr.size()){
        maxi = max(sum, maxi);
        return;
    }

    solve(arr, ind+2, sum+arr[ind], maxi);


    solve(arr, ind+1, sum, maxi);

}
int main(){
    vector<int> arr{2, 1, 4, 9};
    int sum = 0;
    int maxi = INT_MIN;
    solve(arr, 0, sum, maxi);

    return 0;
}

