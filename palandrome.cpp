#include<iostream>
using namespace std;

bool palandrome(string s){
    int n,i,j;
    n = s.length();
    i=0;
    j=n-1;
    while(j>i){
        if(s[i] != s[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    cout<<palandrome(s)<<endl;
    return 0;
}