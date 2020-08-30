#include<iostream>
using namespace std;

void segregate(int a[], int n){
    int t1,t2,t;
    t1=0;
    t2=n-1;
    while(t2>t1){
        if(a[t1] == 1){
            t=a[t1];
            a[t1] = a[t2];
            a[t2] = t;
            t2--;
        }
        else{
            t1++;
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
    segregate(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" : ";
    }
    cout<<endl;
    return 0;
}