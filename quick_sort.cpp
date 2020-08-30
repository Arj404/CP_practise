#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int h){
    int i = l-1;
    int p = a[(l+h)/2];
    for(int j=l; j<h;j++){
        if(p>a[i]){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[(l+h)/2]);
    return i+1;
}

void quicksort(int a[], int l, int h){
    if(h>l){
        int p = partition(a, l, h);
        quicksort(a,l,p-1);
        quicksort(a, p+1,h);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    cout<<"Sorted : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" : ";
    }
    cout<<endl;
    return 0;
}