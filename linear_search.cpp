#include<iostream>
using namespace std;

int search(int arr[], int x,int n){
    for(int i=0;i<n;i++){
        if(x==arr[i]){
            return i;
        }
    }
    return -1;
}

int main(int argc, char** argv){
    if(argc<2){
        puts("usage: programme name <element to search>");
        return 1;
    }
    int arr[] = {5,3,1,5,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = search(arr, atoi(argv[1]),n);
    cout<< arr[result]<<" "<<result<<" ";
    return 0;
}