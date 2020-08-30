#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int insert_element(int x,int b[],int *s,int k){
    int flag=-1;
    for(int i=0;i<=*s;i++){
        if(x>b[i]){
            flag = i;
            break;
        }
    }
    if(flag==-1){
        return 0;
    }
    int temp;
    if(*s<k){
        *s = *s+1;
    }
    for(int i=flag;i<=*s;i++){
        temp = b[i];
        b[i] = x;
        x = temp;
    }
    return 0;
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[k];
    b[0] = INT_MIN;
    int s=0;
    for(int i=0;i<n;i++){
            insert_element(a[i],b,&s,k);
    }
    cout<<"b - ";
    for(int i=0;i<k;i++){
        cout<<b[i]<<" : ";
    }
    cout<<endl;
    cout<<b[k-1]<<endl;
    return 0;
}