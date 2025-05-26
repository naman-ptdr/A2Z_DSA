#include<bits/stdc++.h>
using namespace std;


int fibonacci(int n){
    if(n<=1) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    int n;
    cout<<"Enter any Integer : ";
    cin>>n;
    cout<<"Fibonacci no. at n th place is : "<<fibonacci(n);
}