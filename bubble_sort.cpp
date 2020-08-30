#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubble(int a[], int n){
    int t;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                t = a[j];
                a[j] = a[i];
                a[i] = t;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubble(a,n);
    cout<<"Sorted : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" : ";
    }
    cout<<endl;
    return 0;
}