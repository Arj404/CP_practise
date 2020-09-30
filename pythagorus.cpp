#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countTriplets(int x, int y) 
{
    int result =0;
    for(int a=x;a<=y;a++){
        for(int b=a;b<=y;b++){
            for(int c=b;c<=y;c++){
                if((a*a)+(b*b) == c*c){
                    result++;
                    cout<<a<<" "<<b<<" "<<c<<endl;
                }
            }
        }
    }
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<countTriplets(n,m)<<endl;
    return 0;
}