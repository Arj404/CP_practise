#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r){
    int n1, n2;
    n1 = m-l+1;
    n2 = r-m;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++){
        L[i] = a[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = a[m+1+i];
    }
    int i, j, k;
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k] = L[i];
            k++;
            i++;
        }
        else{
            a[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r){
    if(r>l){
        int m = (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    cout<<"Sorted array : ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" : ";
    }
    cout<<endl;
    return 0;
}