#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int binary_search(int arr[], int l, int r, int x){
    if(l<=r){
        int m = l+ (l+r)/2;
        if(arr[m]==x){
            return m;
        }
        else if(arr[m]>x){
            return binary_search(arr,l,m-1,x);
        }
        else{
            return binary_search(arr,m+1,r,x);
        }
    }
    return -1;
}

int main(int argc, char** argv){
    if(argc<2){
        return 1;
    }
    int arr[] = {4,5,7,2,8,1,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n);
    int result = binary_search(arr, 0, n-1, atoi(argv[1]));
    cout<< result+1<<" : "<<arr[result]<<endl;
    return 0;
}