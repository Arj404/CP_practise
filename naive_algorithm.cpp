#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void search(string s, string p){
    int n,m;
    n=s.length();
    m=p.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(s[i+j] != p[j]){
                break;
            }
        }
        if(j==m){
            cout<<"pattern found at "<<i<<endl;
        }
    }
}

int main(){
    string s,p;
    cin>>s>>p;
    search(s,p);
    return 0;
}