#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    a[0] = 1;
    a[1] = 1;
    for(int i=2;i<=n;i++){
        a[i] = 0;
        for(int j=0;j<i;j++){
            a[i]+=a[j]*a[i-j-1];
        }
    }
    cout<<a[n]<<endl;
    return 0;
}