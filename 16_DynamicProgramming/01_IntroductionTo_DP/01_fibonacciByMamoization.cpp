#include<bits/stdc++.h>
using namespace std;
int fibona(int n, vector<int>& dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fibona(n-1, dp)+fibona(n-2, dp);
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<fibona(n, dp);
return 0;
}