#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lsum(int arr[], int n){
    int max, result;
    max = 0;
    result = INT_MIN;
    for(int i=0;i<n;i++){
        max = max + arr[i];
        if(max>result){
            result = max;
        }
        if(max<0){
            max=0;
        }
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<lsum(a,n)<<endl;
    return 0;
}