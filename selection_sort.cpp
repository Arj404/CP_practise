//repeatedly finding the minimum element

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Selection(int a[],int n){
    int min,t;
    for(int i=0;i<n;i++){
        min =i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Selection(a,n);
    cout<<"Sorted : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" : ";
    }
    cout<<endl;
    return 0;
}